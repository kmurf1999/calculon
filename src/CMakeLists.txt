file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.cc)

add_library(supremus STATIC ${SOURCES})

target_link_libraries(supremus ompeval)
