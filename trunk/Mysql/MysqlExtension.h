
#ifndef Mysql_MysqlExtension_h
#define Mysql_MysqlExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>

// Forward declarations

// Namespace declarations


namespace Mysql {


class MysqlExtension : public AExtension
{
public:
	MysqlExtension();

public:
	void initialize(ObjectiveScript::IScope* scope);
	void provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods);
};


}



#endif
