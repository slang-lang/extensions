
#ifndef Extensions_MQ_Types_h
#define Extensions_MQ_Types_h


// Library includes
#include <cerrno>
#include <climits>
#include <fcntl.h>
#include <map>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Project includes

// Forward declarations

// Namespace declarations


namespace MQ {


struct Message_t {
	long mType;
	char mText[512];
};

typedef std::map<int, /*message queue id*/ int> MQs;

extern MQs mMQs;


}


#endif

