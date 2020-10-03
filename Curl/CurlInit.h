
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
			// duplicate base handle, since we want to inherit all of its already set options
			CURL* newHandle = curl_easy_duphandle( mRequests[0].Handle );

			int32_t methodResult = 0;
			if ( newHandle ) {
				CurlRequest request;
				request.Handle = newHandle;

				methodResult = static_cast<int32_t>( mRequests.size() );

				mRequests.insert( std::make_pair( mRequests.size(), request ) );
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
