
#ifndef Extensions_PipeOpen_h
#define Extensions_PipeOpen_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Pipe {


class PipeOpen : public Extensions::ExtensionMethod
{
public:
	PipeOpen()
	: ExtensionMethod(0, "pipe_open", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("name", Designtime::StringType::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("mode", Designtime::StringType::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("block", Designtime::BoolType::TYPENAME, true, true));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			auto param_name  = (*it++).value().toStdString();
			auto param_mode  = (*it++).value().toStdString();
			auto param_block = (*it++).value().toBool();

			size_t pipe_handle = 0;

			if ( param_mode == "r" || param_mode == "w" ) {
				pipe_handle = mPipes.size();
				auto& p = mPipes[pipe_handle];

				if ( mknod( param_name.c_str(), S_IFIFO | 0666, 0 ) == 0 || errno == EEXIST ) {
					p = open( param_name.c_str(), (param_mode == "r" ? O_RDONLY : O_WRONLY) | (param_block ? 0 : O_NDELAY) );
				}
				else {
					// error while creating pipe
					pipe_handle = 0;
				}
			}

			*result = Runtime::Int32Type( static_cast<int32_t>( pipe_handle ) );
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
