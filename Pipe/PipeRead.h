
#ifndef Extensions_PipeRead_h
#define Extensions_PipeRead_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Pipe {


class PipeRead : public Extensions::ExtensionMethod
{
public:
	PipeRead()
	: ExtensionMethod(0, "pipe_read", Designtime::StringType::TYPENAME)
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

			std::string method_result;

			if ( param_handle > 0 && param_handle < static_cast<int32_t>( mPipes.size() ) ) {
				char buffer[PIPE_BUF];

				auto& p = mPipes[param_handle];
				auto length = read( p, buffer, PIPE_BUF );
				buffer[length] = '\0';

				method_result = std::string( buffer );
			}

			*result = Runtime::StringType( method_result );
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
