
// Header
#include "JsonExtension.h"

// Library includes

// Project includes
#include "FromJson.h"
#include "ToJson.h"

// Namespace declarations


namespace Json {


JsonExtension::JsonExtension()
: AExtension("Json")
{
}

void JsonExtension::initialize(Slang::IScope* /*scope*/)
{
	// nothing to do here
}

void JsonExtension::provideMethods(Slang::Extensions::ExtensionMethods &methods)
{
	assert(methods.empty());

	methods.push_back(new FromJson());
	methods.push_back(new ToJson());
}


}


extern "C" AExtension* factory(void) {
	return dynamic_cast<AExtension*>( new Json::JsonExtension() );
}

