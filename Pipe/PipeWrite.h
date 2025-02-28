
#ifndef Extensions_PipeWrite_h
#define Extensions_PipeWrite_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Pipe {


class PipeWrite : public Extensions::ExtensionMethod
{
public:
	PipeWrite()
	: ExtensionMethod(0, "pipe_write", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::Int32Type::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("message", Designtime::StringType::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			auto param_handle  = (*it++).value().toInt();
			auto param_message = (*it++).value().toStdString();

			int error = 0;
			if ( param_handle > 0 && param_handle < static_cast<int32_t>( mPipes.size() ) ) {
				auto& p = mPipes[param_handle];

				write( p, param_message.c_str(), param_message.size() );
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
