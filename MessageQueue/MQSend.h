
#ifndef Extensions_MQSend_h
#define Extensions_MQSend_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace MQ {


class MQSend : public Extensions::ExtensionMethod
{
public:
	MQSend()
	: ExtensionMethod(0, "msgsnd", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::IntegerObject::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("message", Designtime::StringObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_handle = (*it++).value().toInt();
			std::string param_message = (*it++).value().toStdString();

			int method_result = 0;
			if ( param_handle > 0 && param_handle < (int)mMQs.size() ) {
				int& queue = mMQs[param_handle];

				struct Message_t message;
				message.mType = 1;

				if ( param_message.size() >= 512 ) {
					param_message.resize(512);
				}

				snprintf(message.mText, param_message.size(), "%s", param_message.c_str());
				message.mText[param_message.size()] = '\0';

				method_result = msgsnd(queue, &message, param_message.size() + 1, 0);
			}

			*result = Runtime::IntegerObject( method_result );
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

