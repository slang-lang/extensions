
#ifndef Extensions_Json_JsonExtension_h
#define Extensions_Json_JsonExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>

// Forward declarations

// Namespace declarations


namespace Json {


class JsonExtension : public Slang::Extensions::AExtension
{
public:
	JsonExtension();

public:
	void initialize( Slang::IScope* scope );
	void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}


#endif
