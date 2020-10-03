
#ifndef Extensions_Curl_Types_h
#define Extensions_Curl_Types_h


// Library includes
#include <curl/curl.h>
#include <map>
#include <string>

// Project includes

// Forward declarations

// Namespace declarations


namespace Curl {


struct CurlRequest {
	CURL*		Handle { nullptr };
	std::string	Header;
	std::string	Result;
};


typedef std::map<int, CurlRequest> Requests;

extern size_t mNumRequests;
extern Requests mRequests;


}


#endif

