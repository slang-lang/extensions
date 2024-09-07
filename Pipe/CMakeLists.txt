INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
    PipeExtension.cpp
    Types.cpp
)

SET(HEADERS
    Defines.h
    PipeClose.h
    PipeExtension.h
    PipeOpen.h
    PipeRead.h
    PipeWrite.h
    Types.h
)

SET(DEPENDENCIES
    CoreExtensions
)

SET(MODULES
    slang
)

add_include(Externals)

build_shared_lib(SlangPipe "${MODULES}")

