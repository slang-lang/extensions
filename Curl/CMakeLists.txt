INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
    CurlExtension.cpp
    Types.cpp
)

SET(HEADERS
    Defines.h
    CurlCleanup.h
    CurlExtension.h
    CurlInit.h
    CurlPerform.h
    CurlReadResult.h
    CurlReset.h
    CurlSetBearer.h
    CurlSetHeader.h
    CurlSetOptInt.h
    CurlSetOptStr.h
    CurlSetPassword.h
    CurlSetProgress.h
    CurlSetUrl.h
    CurlSetUsername.h
    CurlSetVerbose.h
    Types.h
)

SET(DEPENDENCIES
    curl
)

SET(MODULES
    slang
    curl
)

add_include(Externals)

build_shared_lib(ExtCurl "${MODULES}")

