
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


typedef std::map<int, /*result handle*/ CURL*> HandleMap;
typedef std::map<int, std::string> ResultMap;

extern HandleMap mHandles;
extern int mNumHandles;
extern ResultMap mResults;


}


#endif

