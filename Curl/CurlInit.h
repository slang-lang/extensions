
#ifndef Extensions_Curl_CurlInit_h
#define Extensions_Curl_CurlInit_h


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


class CurlInit: public Extensions::ExtensionMethod
{
public:
	CurlInit()
	: ExtensionMethod(0, "curl_init", Designtime::IntegerObject::TYPENAME, Mutability::Modify)
	{
		ParameterList params;

		setSignature(params);
	}


	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& /*params*/, Runtime::Object* result, const Token& token)
	{
		try {
			//CURL* handle = curl_easy_init();
			CURL* handle = curl_easy_duphandle( mHandles[0] );

			int my_result = 0;
			if ( handle ) {
				my_result = ++mNumHandles;

				mHandles.insert(std::make_pair(my_result, handle));
				mResults.insert(std::make_pair(my_result, ""));
			}

			*result = Runtime::IntegerObject(my_result);
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
