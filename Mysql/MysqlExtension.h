
#ifndef Mysql_MysqlExtension_h
#define Mysql_MysqlExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>

// Forward declarations

// Namespace declarations


namespace Mysql {


class MysqlExtension : public Slang::Extensions::AExtension
{
public:
	MysqlExtension();

public:
	void initialize( Slang::IScope* scope );
	void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}



#endif
