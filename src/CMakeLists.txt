file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.cc)

add_library(libsupremus STATIC ${SOURCES})

# Specify here the include directories exported
# by this library
target_include_directories(libsupremus PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
