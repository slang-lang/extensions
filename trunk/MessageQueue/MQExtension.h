
#ifndef Extensions_MQExtension_h
#define Extensions_MQExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace MQ {


class MQExtension : public AExtension
{
public:
    MQExtension();
    ~MQExtension();

public:
    void initialize(ObjectiveScript::IScope* scope);
    void provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods);
};


}


#endif

