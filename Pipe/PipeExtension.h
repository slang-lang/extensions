
#ifndef Extensions_PipeExtension_h
#define Extensions_PipeExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Pipe {


class PipeExtension : public Slang::Extensions::AExtension
{
public:
    PipeExtension();
    ~PipeExtension();

public:
    void initialize( Slang::IScope* scope );
    void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}


#endif

