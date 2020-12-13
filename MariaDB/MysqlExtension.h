
#ifndef Mysql_MariaDBExtension_h
#define Mysql_MariaDBExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>

// Forward declarations

// Namespace declarations


namespace Mysql {


class MariaDBExtension : public Slang::Extensions::AExtension
{
public:
	MariaDBExtension();

public:
	void initialize( Slang::IScope* scope );
	void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}



#endif
