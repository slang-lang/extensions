
#ifndef Extensions_MQClose_h
#define Extensions_MQClose_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace MQ {


class MQClose : public Extensions::ExtensionMethod
{
public:
	MQClose()
	: ExtensionMethod(0, "msgctl", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::IntegerObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_handle = (*it++).value().toInt();

			int method_result = 0;
			if ( param_handle > 0 && param_handle < (int)mMQs.size() ) {
				int& queue = mMQs[param_handle];

				method_result = msgctl(queue, IPC_RMID, NULL);
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

