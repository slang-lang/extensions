
#ifndef Extensions_Pipe_PipeExtension_h
#define Extensions_Pipe_PipeExtension_h


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
    ~PipeExtension() = default;

public:
    void initialize( Slang::Extensions::ExtensionNamespace* scope );
    void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}


#endif

