
#ifndef Extensions_MQReceive_h
#define Extensions_MQReceive_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace MQ {


class MQReceive : public Extensions::ExtensionMethod
{
public:
	MQReceive()
	: ExtensionMethod(nullptr, "msgrcv", Designtime::StringObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::IntegerObject::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("wait", Designtime::BoolObject::TYPENAME, false, true));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_handle = (*it++).value().toInt();
			bool param_wait = (*it++).value().toBool();

			std::string method_result;
			if ( param_handle > 0 && param_handle < (int)mMQs.size() ) {
				int& queue = mMQs[param_handle];

				struct Message_t message;

				int msgflg = (param_wait ? 0 : IPC_NOWAIT);
				if ( msgrcv(queue, &message, sizeof message.mText, 0, msgflg) != -1 ) {
					method_result = std::string(message.mText );
				}
			}

			*result = Runtime::StringObject( method_result );
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

