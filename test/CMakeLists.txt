file(GLOB_RECURSE TEST_SRC_FILES *.cpp *.h)

list(APPEND ALL_TEST_SRC_FILES ${CORE_SRC_FILES} ${TEST_SRC_FILES})

message(STATUS "ALL_TEST_SRC_FILES = ${ALL_TEST_SRC_FILES}")

add_executable(test ${ALL_TEST_SRC_FILES})

target_link_libraries(test -fopenmp)
