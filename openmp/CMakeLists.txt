file(GLOB_RECURSE OPENMP_SRC_FILES *.cpp *.h)

list(APPEND ALL_OPENMP_SRC_FILES ${CORE_SRC_FILES} ${OPENMP_SRC_FILES})

message(STATUS "ALL_OPENMP_SRC_FILES = ${ALL_OPENMP_SRC_FILES}")

add_executable(openmp ${ALL_OPENMP_SRC_FILES})

#target_link_libraries(openmp -fopenmp)
