cmake_minimum_required(VERSION 3.10)
project(multithreaded_producer_consumer)

set(CMAKE_CXX_STANDARD 17)

# Agregar la ruta de la carpeta include
include_directories(include)

# Agregar los archivos fuente del ejecutable principal
set(MAIN_SOURCE_FILES
    src/main.cpp
    src/producer.cpp
    src/consumer.cpp
    src/shared_buffer.cpp
)

# Agregar el ejecutable principal
add_executable(producer_consumer ${MAIN_SOURCE_FILES})

# Agregar GTest
add_subdirectory(tests/gtest)
include_directories(tests/gtest/include)

# Agregar los archivos de prueba
set(TEST_FILES
    tests/stock_quote_test.cpp
    tests/shared_buffer_test.cpp
    tests/producer_test.cpp
    tests/consumer_test.cpp
    src/producer.cpp
    src/consumer.cpp
    src/shared_buffer.cpp
)

# Crear el ejecutable de pruebas
add_executable(test_runner ${TEST_FILES})

# Enlazar GTest
target_link_libraries(test_runner gtest gtest_main)

# Enlazar la biblioteca pthread para soporte de hilos
target_link_libraries(producer_consumer pthread)
target_link_libraries(test_runner pthread)