file(GLOB_RECURSE PTHREAD_SRC_FILES *.cpp *.h)

list(APPEND ALL_PTHREAD_SRC_FILES ${CORE_SRC_FILES} ${PTHREAD_SRC_FILES})

message(STATUS "ALL_PTHREAD_SRC_FILES = ${ALL_PTHREAD_SRC_FILES}")

add_executable(pthread ${ALL_PTHREAD_SRC_FILES})

target_link_libraries(pthread -fopenmp)
