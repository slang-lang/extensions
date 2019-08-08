
#ifndef Extensions_Apache_Types_h
#define Extensions_Apache_Types_h


// Library includes
#include <map>
#include <string>

// Project includes

// Forward declarations

// Namespace declarations


namespace Apache {


typedef std::map<std::string, std::string> StringMap;


extern const char* QUERY_STRING;
extern StringMap mGetQueryString;
extern StringMap mPostQueryString;


}


#endif
