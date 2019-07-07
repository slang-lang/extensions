
#ifndef Extensions_Pipe_Types_h
#define Extensions_Pipe_Types_h


// Library includes
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


// Project includes

// Forward declarations

// Namespace declarations


namespace Pipe {


typedef std::map<int, /*file descriptor*/ int> Pipes;

extern Pipes mPipes;


}


#endif

