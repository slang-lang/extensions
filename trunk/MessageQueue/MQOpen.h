
#ifndef Extensions_MQOpen_h
#define Extensions_MQOpen_h


// Library includes
#include <errno.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace MQ {


class MQOpen : public Extensions::ExtensionMethod
{
public:
	MQOpen()
	: ExtensionMethod(0, "msgget", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("name", Designtime::StringObject::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("mode", Designtime::IntegerObject::TYPENAME, 666, true));
		params.push_back(Parameter::CreateDesigntime("create", Designtime::BoolObject::TYPENAME, false, true));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			std::string param_name = (*it++).value().toStdString();
			int param_mode = (*it++).value().toInt();
			bool param_create = (*it++).value().toBool();

			size_t queue_handle = mMQs.size();
			int& queue = mMQs[queue_handle];

			key_t key = ftok(param_name.c_str(), 'B');
			queue = msgget(key, 0644 | (param_create ? IPC_CREAT : 0));

			if ( queue == -1 ) {
				queue_handle = 0;
			}

			*result = Runtime::IntegerObject( static_cast<int>(queue_handle) );
		}
		catch ( std::exception& e ) {
			Runtime::Object *data = Controller::Instance().repository()->createInstance(Runtime::StringObject::TYPENAME, ANONYMOUS_OBJECT);
			*data = Runtime::StringObject(std::string(e.what()));

			Controller::Instance().thread(threadId)->exception() = Runtime::ExceptionData(data, token.position());
			return Runtime::ControlFlow::Throw;
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
