set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES big_integer.cpp big_integer.h)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})