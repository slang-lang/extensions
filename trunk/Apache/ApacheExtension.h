
#ifndef ObjectiveScript_Extensions_Apache_ApacheExtension_h
#define ObjectiveScript_Extensions_Apache_ApacheExtension_h


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

	void initialize(ObjectiveScript::IScope* scope);
	void provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods);

private:
	void readGetData();
	void readPostData();
};


}


#endif
