
#ifndef Extensions_PipeClose_h
#define Extensions_PipeClose_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Pipe {


class PipeClose : public Extensions::ExtensionMethod
{
public:
	PipeClose()
	: ExtensionMethod(0, "pipe_close", Designtime::IntegerObject::TYPENAME)
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

			int error = 0;
			if ( param_handle > 0 && param_handle < (int)mPipes.size() ) {
				Pipe& p = mPipes[param_handle];

				close(p.fd[0]);
				p.fd[0] = 0;

				close(p.fd[1]);
				p.fd[1] = 0;
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

