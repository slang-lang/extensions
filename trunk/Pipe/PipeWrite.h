
#ifndef Extensions_PipeWrite_h
#define Extensions_PipeWrite_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Pipe {


class PipeWrite : public Extensions::ExtensionMethod
{
public:
	PipeWrite()
	: ExtensionMethod(0, "pipe_write", Designtime::IntegerObject::TYPENAME)
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

			int error = 0;
			if ( param_handle > 0 && param_handle < (int)mPipes.size() ) {
				Pipe& p = mPipes[param_handle];

				write(p.fd[1], param_message.c_str(), param_message.size());
			}
			else {
				error = -1;
			}

			*result = Runtime::IntegerObject( error );
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

