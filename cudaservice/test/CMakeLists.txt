add_executable(timeTaskLaunch task_service/time_task_launch.cpp)
set_target_properties(timeTaskLaunch PROPERTIES COMPILE_FLAGS "-std=c++14 -O3 -pthread")
add_test(NAME timeTaskLaunch COMMAND timeTaskLaunch)
  
add_executable(threadPoolExample task_service/threadPool_example.cpp)
add_test(NAME threadPoolExample COMMAND threadPoolExample)

add_executable(TEST_threadPoolSimple task_service/test_threadPool_simple.cpp)
add_test(NAME threadPoolSimple COMMAND TEST_threadPoolSimple)

CUDA_ADD_EXECUTABLE(TEST_threadPoolCUDA task_service/test_threadPool_CUDAtask.cu)
add_test(NAME threadPoolCUDA COMMAND TEST_threadPoolCUDA)

