
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
	struct curl_slist* HeaderList { nullptr };
	std::string	Result;

	~CurlRequest() {
		// free the list again
		curl_slist_free_all( HeaderList );
	}
};


typedef std::map<size_t, CurlRequest*> CurlRequests;

extern CurlRequests Requests;

void cleanup();
void init();


}


#endif

