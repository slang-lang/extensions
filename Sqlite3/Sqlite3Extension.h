
#ifndef Extensions_Sqlite3Extension_h
#define Extensions_Sqlite3Extension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Sqlite3 {


class Sqlite3Extension : public AExtension
{
public:
    Sqlite3Extension();
    ~Sqlite3Extension();

public:
    void initialize(ObjectiveScript::IScope* scope);
    void provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods);
};


}


#endif
