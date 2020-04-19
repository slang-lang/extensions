
#ifndef Slang_Extensions_Apache_ApacheExtension_h
#define Slang_Extensions_Apache_ApacheExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Apache {


class ApacheExtension : public AExtension
{
public:
	ApacheExtension();

	void initialize(Slang::IScope* scope);
	void provideMethods(Slang::Extensions::ExtensionMethods &methods);

private:
	void readGetData();
	void readPostData();
};


}


#endif
