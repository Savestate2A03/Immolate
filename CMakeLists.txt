cmake_minimum_required(VERSION 3.21)

project(Immolate
    VERSION 0.0.1
    DESCRIPTION "Immolate ported to C"
    LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(IMMOLATE_SEED 1234WOLF CACHE STRING "The starting seed for the searcher")
set(IMMOLATE_FILTER filters/perkeo_observatory.c CACHE FILEPATH "The filter file to build")

set(SOURCES
    lib/src/consts.c
    lib/src/cache.c
    lib/src/debug.c
    lib/src/functions.c
    lib/src/instance.c
    lib/src/items.c
    lib/src/seed.c
    lib/src/util.c
    src/immolate.c
    ${IMMOLATE_FILTER}
)

set(HEADERS
    lib/include/immolate.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

if(NOT ${IMMOLATE_SEED} STREQUAL "")
    string(TOUPPER ${IMMOLATE_SEED} IMMOLATE_SEED)
    target_compile_definitions(${PROJECT_NAME} PRIVATE IMMOLATE_STARTING_SEED=${IMMOLATE_SEED})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
        ${CMAKE_CURRENT_BINARY_DIR}/lib/include
)

source_group(
    TREE ${CMAKE_CURRENT_SOURCE_DIR}
    PREFIX "Source Files"
    FILES ${SOURCES}
)

source_group(
    TREE ${CMAKE_CURRENT_SOURCE_DIR}
    PREFIX "Header Files"
    FILES ${HEADERS}
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)