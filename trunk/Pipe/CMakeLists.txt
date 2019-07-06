INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
    PipeExtension.cpp
    Types.cpp
)

SET(HEADERS
    Defines.h
    PipeClose.h
    PipeCreate.h
    PipeExtension.h
    PipeRead.h
    PipeWrite.h
    Types.h
)

SET(DEPENDENCIES
)

SET(MODULES
    oscript
)

add_include(Externals)

build_shared_lib(ObjectiveScriptPipe "${MODULES}")

