file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.cc)
add_library(${CALCULON_LIB} STATIC ${SOURCES})
target_link_libraries(${CALCULON_LIB} ompeval)
