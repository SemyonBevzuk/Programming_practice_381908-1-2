set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES dictionary.h dictionary.cpp word.h word.cpp)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})