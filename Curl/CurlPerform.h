
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
			auto it = params.cbegin();
			auto paramHandle = (*it++).value().toInt();

			int32_t methodResult = 0;
			if ( paramHandle > 0 && paramHandle < static_cast<int32_t>( mRequests.size() ) ) {
				auto& request = mRequests[paramHandle];

				curl_easy_setopt( request.Handle, CURLOPT_WRITEDATA, &request.Result );

				methodResult = curl_easy_perform( request.Handle );
			}

			*result = Runtime::IntegerObject( methodResult );
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
