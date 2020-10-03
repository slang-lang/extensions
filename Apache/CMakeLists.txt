INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
	ApacheExtension.cpp
	Types.cpp
)

SET(HEADERS
	ApacheExtension.h
	Get.h
	IsSet.h
	Post.h
	Pre.h
	Types.h
)

SET(DEPENDENCIES
)

SET(MODULES
	slang
)

add_include(Externals)

build_shared_lib(SlangApache "${MODULES}")

