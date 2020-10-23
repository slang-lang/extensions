
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
	~CurlExtension() override;

public:
	void initialize(Slang::IScope* scope) override;
	void provideMethods(Slang::Extensions::ExtensionMethods &methods) override;

public:
	static size_t write_data( void *contents, size_t size, size_t nmemb, void *stream );
};


}


#endif

