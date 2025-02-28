
#ifndef Extensions_PipeClose_h
#define Extensions_PipeClose_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Pipe {


class PipeClose : public Extensions::ExtensionMethod
{
public:
	PipeClose()
	: ExtensionMethod(0, "pipe_close", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			auto param_handle = (*it++).value().toInt();

			int error = 0;
			if ( param_handle > 0 && param_handle < static_cast<int32_t>( mPipes.size() ) ) {
				auto& p = mPipes[param_handle];

				close( p );
				p = 0;
			}
			else {
				error = -1;
			}

			*result = Runtime::Int32Type( error );
		}
		catch ( std::exception& e ) {
			auto *data = Controller::Instance().repository()->createInstance(Runtime::StringType::TYPENAME, ANONYMOUS_OBJECT);
			*data = Runtime::StringType(std::string(e.what()));

			Controller::Instance().thread(threadId)->exception() = Runtime::ExceptionData(data, token.position());
			return Runtime::ControlFlow::Throw;
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
