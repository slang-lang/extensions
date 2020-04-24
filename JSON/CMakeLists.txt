INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
	JsonExtension.cpp
)

SET(HEADERS
	FromJson.h
	JsonExtension.h
	ToJson.h
)

SET(DEPENDENCIES
	CoreExtensions
)

SET(MODULES
	json
	oscript
)

build_shared_lib(ExtJson "${MODULES}")
