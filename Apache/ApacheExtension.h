
#ifndef Slang_Extensions_Apache_ApacheExtension_h
#define Slang_Extensions_Apache_ApacheExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Apache {


class ApacheExtension : public Slang::Extensions::AExtension
{
public:
	ApacheExtension();
    ~ApacheExtension() = default;

	void initialize( Slang::Extensions::ExtensionNamespace* scope );
	void provideMethods( Slang::Extensions::ExtensionMethods& methods );

private:
	void readGetData();
	void readPostData();
};


}


#endif
