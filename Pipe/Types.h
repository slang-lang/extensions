
#ifndef Extensions_Pipe_Types_h
#define Extensions_Pipe_Types_h


// Library includes
#include <limits.h>
#include <map>
#include <unistd.h>

// Project includes

// Forward declarations

// Namespace declarations


namespace Pipe {


class Pipe
{
public:
	int fd[2];
};

typedef std::map<int, Pipe> Pipes;

extern Pipes mPipes;


}


#endif

