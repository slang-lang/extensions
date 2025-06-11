INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
	Extension.cpp
	Types.cpp
)

SET(HEADERS
	Extension.h
	Get.h
	IsSet.h
	Post.h
	Pre.h
	Types.h
)

SET(DEPENDENCIES
	CoreExtensions
)

SET(MODULES
	slang
)

add_include(Externals)

build_shared_lib(SlangApache "${MODULES}")

