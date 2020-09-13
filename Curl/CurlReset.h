
#ifndef Extensions_Curl_CurlReset_h
#define Extensions_Curl_CurlReset_h


// Library include

// Project includes
#include <Core/Designtime/BuildInTypes/IntegerObject.h>
#include <Core/Extensions/ExtensionMethod.h>
#include <Core/Runtime/BuildInTypes/IntegerObject.h>
#include <Core/Runtime/BuildInTypes/StringObject.h>
#include <Core/Tools.h>
#include "Types.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Curl {


class CurlReset: public Extensions::ExtensionMethod
{
public:
	CurlReset()
	: ExtensionMethod(0, "curl_reset", Designtime::IntegerObject::TYPENAME, Mutability::Modify)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::IntegerObject::TYPENAME));

		setSignature(params);
	}


	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		try {
			ParameterList::const_iterator it = params.begin();

			auto param_handle = (*it++).value().toInt();

			int method_result = 0;		// intialize with negative result
			if ( param_handle > 0 && param_handle < (int)mHandles.size() ) {
				CURL* handle = mHandles[param_handle];

				curl_easy_reset(handle);

				method_result = 1;		// positive result
			}

			*result = Runtime::IntegerObject( method_result );
		}
		catch ( std::exception &e ) {
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
