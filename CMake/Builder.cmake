
function(build_shared_lib target modules)

    _handle_modules_pre_linker("${modules}")

    add_library(${target} SHARED ${SOURCES} ${HEADERS})

    LIST(LENGTH DEPENDENCIES num_dependencies)
    if ( num_dependencies GREATER 0 )
        target_link_libraries(${target} ${DEPENDENCIES})
    endif()

    _handle_modules_post_linker("${modules}" ${target})

endfunction()


function(build_static_lib target modules)

    _handle_modules_pre_linker("${modules}")

    add_library(${target} STATIC ${SOURCES} ${HEADERS})

    LIST(LENGTH DEPENDENCIES num_dependencies)
    if ( num_dependencies GREATER 0 )
        target_link_libraries(${target} ${DEPENDENCIES})
    endif()

    _handle_modules_post_linker("${modules}" ${target})

endfunction()


function(build_app target modules)

    _handle_modules_pre_linker("${modules}")

    SET(CMAKE_CXX_FLAGS "-Wl,--as-needed")
    LIST(LENGTH HEADERS num_headers)

    add_executable(${target} ${SOURCES} ${HEADERS})

    # link against specified libs
    target_link_libraries(${target} ${DEPENDENCIES})

    _handle_modules_post_linker("${modules}" ${target})

endfunction()


function(_handle_modules_pre_linker modules)

    list(FIND modules "mysql" found)
    if ( ${found} GREATER -1 )
        _handle_pre_mysql()
    endif()

    list(FIND modules "oscript" found)
    if ( ${found} GREATER -1 )
        _handle_pre_oscript()
    endif()

    list(FIND modules "sqlite3" found)
    if ( ${found} GREATER -1 )
        _handle_pre_sqlite3()
    endif()

endfunction()


function(_handle_modules_post_linker modules target)

    list(FIND modules "mysql" found)
    if ( ${found} GREATER -1 )
        _handle_post_mysql(${target})
    endif()

    list(FIND modules "oscript" found)
    if ( ${found} GREATER -1 )
        _handle_post_oscript(${target})
    endif()

    list(FIND modules "sqlite3" found)
    if ( ${found} GREATER -1 )
        _handle_post_sqlite3()
    endif()

endfunction()


###############################
### MYSQL

function(_mysql_check_existence)

    # make sure the appropriate environment variable is set!
    if("${BUILD_MYSQL_INC}" STREQUAL "")
        MESSAGE(FATAL_ERROR "BUILD_MYSQL_INC needed for mysql!")
    endif()

    if("${BUILD_MYSQL_LIB}" STREQUAL "")
        MESSAGE(FATAL_ERROR "BUILD_MYSQL_LIB needed for mysql!")
    endif()

endfunction()

function(_handle_post_mysql target)

    _mysql_check_existence()
    target_link_libraries(${target} mysqlclient)

endfunction()

function(_handle_pre_mysql)

    _mysql_check_existence()
    include_directories(${BUILD_MYSQL_INC})
    link_directories(${BUILD_MYSQL_LIB})

endfunction()

### MYSQL
###############################


###############################
### ObjectiveScript

function(_oscript_check_existence)

    # make sure the appropriate environment variable is set!
    if("${BUILD_OSCRIPT_INC}" STREQUAL "")
        MESSAGE(FATAL_ERROR "BUILD_OSCRIPT_INC needed for ObjectiveScript!")
    endif()

    if("${BUILD_OSCRIPT_LIB}" STREQUAL "")
        MESSAGE(FATAL_ERROR "BUILD_OSCRIPT_LIB needed for ObjectiveScript!")
    endif()

endfunction()

function(_handle_post_oscript target)

    _oscript_check_existence()
    target_link_libraries(${target} UtilsTools)
    target_link_libraries(${target} Utils)
    target_link_libraries(${target} CoreVirtualMachine)
    target_link_libraries(${target} CoreRuntimeBuildInTypes)
    target_link_libraries(${target} CoreRuntime)
    target_link_libraries(${target} CoreExtensions)
    target_link_libraries(${target} CoreDesigntimeParser)
    target_link_libraries(${target} CoreDesigntimeBuildInTypes)
    target_link_libraries(${target} CoreDesigntime)
    target_link_libraries(${target} CoreDebugger)
    target_link_libraries(${target} CoreCommon)
    target_link_libraries(${target} CoreAttributes)
    target_link_libraries(${target} CoreAST)
    target_link_libraries(${target} Core)

endfunction()

function(_handle_pre_oscript)

    _oscript_check_existence()
    include_directories(${BUILD_OSCRIPT_INC})
    link_directories(${BUILD_OSCRIPT_LIB})

endfunction()

### ObjectiveScript
###############################

###############################
### sqlite3

function(_sqlite3_check_existence)

    # make sure the appropriate environment variable is set!
    if("${BUILD_SQLITE3_INC}" STREQUAL "")
        MESSAGE(FATAL_ERROR "BUILD_SQLITE3_INC needed for sqlite3!")
    endif()

    if("${BUILD_SQLITE3_LIB}" STREQUAL "")
        MESSAGE(FATAL_ERROR "BUILD_SQLITE3_LIB needed for sqlite3!")
    endif()

endfunction()

function(_handle_post_sqlite3 target)

    _sqlite3_check_existence()
    target_link_libraries(${target} sqlite)

endfunction()

function(_handle_pre_sqlite3)

    _sqlite3_check_existence()
    include_directories(${BUILD_SQLITE3_INC})
    link_directories(${BUILD_SQLITE3_LIB})

endfunction()

### sqlite3
###############################

