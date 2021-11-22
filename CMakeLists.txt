PROJECT(Slang-Extensions)

cmake_minimum_required(VERSION 3.0)

# cmake policy changes. use "cmake --help-policy <policyid>" for details
if ( CMAKE_VERSION VERSION_LESS "3.0.0" )
else()
    cmake_policy(SET CMP0011 NEW)
endif()

# verbose makefiles
#SET(CMAKE_VERBOSE_MAKEFILE ON)

# this helps debugging dependencies - a lot :)
#SET_PROPERTY(GLOBAL PROPERTY GLOBAL_DEPENDS_DEBUG_MODE 1)

INCLUDE(CMake/Base.cmake)

ADD_SUBDIRECTORY(Apache)
#ADD_SUBDIRECTORY(Curl)		# extension has been moved to a separate repository
#ADD_SUBDIRECTORY(JSON)
ADD_SUBDIRECTORY(MessageQueue)
#ADD_SUBDIRECTORY(MariaDB)	# extension has been moved to a separate repository
#ADD_SUBDIRECTORY(Mysql)	# extension has been moved to a separate repository
ADD_SUBDIRECTORY(Pipe)
#ADD_SUBDIRECTORY(Sqlite3)	# extension has been moved to a separate repository

