INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
    MQExtension.cpp
    Types.cpp
)

SET(HEADERS
    Defines.h
    MQClose.h
    MQExtension.h
    MQOpen.h
    MQReceive.h
    MQSend.h
    Types.h
)

SET(DEPENDENCIES
)

SET(MODULES
    oscript
)

add_include(Externals)

build_shared_lib(ExtMessageQueue "${MODULES}")

