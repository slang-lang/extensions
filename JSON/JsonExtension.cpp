
// Header
#include "JsonExtension.h"

// Library includes

// Project includes
#include "FromJson.h"
#include "ToJson.h"

// Namespace declarations


namespace Json {


JsonExtension::JsonExtension()
: AExtension( "Json", "0.0.1")
{
}

void JsonExtension::initialize( Slang::IScope* /*scope*/ )
{
	// nothing to do here
}

void JsonExtension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	assert( methods.empty() );

	methods.push_back( new FromJson() );
	methods.push_back( new ToJson() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new Json::JsonExtension() );
}

