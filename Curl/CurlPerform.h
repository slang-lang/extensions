
#ifndef Extensions_Curl_CurlPerform_h
#define Extensions_Curl_CurlPerform_h


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


class CurlPerform: public Extensions::ExtensionMethod
{
public:
	CurlPerform()
	: ExtensionMethod(0, "curl_perform", Designtime::IntegerObject::TYPENAME, Mutability::Modify)
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

			int method_result = CURLE_OK;
			if ( param_handle > 0 && param_handle < (int)mHandles.size() ) {
				CURL* handle = mHandles[param_handle];

				curl_easy_setopt( handle, CURLOPT_WRITEDATA, &mResults[param_handle] );

				method_result = curl_easy_perform(handle);
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
