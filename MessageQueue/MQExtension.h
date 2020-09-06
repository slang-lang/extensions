
#ifndef Extensions_MQExtension_h
#define Extensions_MQExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace MQ {


class MQExtension : public Slang::Extensions::AExtension
{
public:
    MQExtension();
    ~MQExtension();

public:
    void initialize( Slang::IScope* scope );
    void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}


#endif

