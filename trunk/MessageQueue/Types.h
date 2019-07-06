
#ifndef Extensions_MQ_Types_h
#define Extensions_MQ_Types_h


// Library includes
#include <limits.h>
#include <map>
#include <unistd.h>

// Project includes

// Forward declarations

// Namespace declarations


namespace MQ {


struct Message_t {
	long mtype;
	char mtext[512];
};

typedef std::map<int, /*message queue id*/ int> MQs;

extern MQs mMQs;


}


#endif

