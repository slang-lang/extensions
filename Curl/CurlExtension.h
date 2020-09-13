
#ifndef Extensions_Curl_CurlExtension_h
#define Extensions_Curl_CurlExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Curl {


class CurlExtension : public Slang::Extensions::AExtension
{
public:
	CurlExtension();
    ~CurlExtension();

public:
    void initialize(Slang::IScope* scope);
    void provideMethods(Slang::Extensions::ExtensionMethods &methods);
};


}


#endif

