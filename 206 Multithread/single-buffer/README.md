# Multithreaded Producer-Consumer Project in C++

This project implements a basic producer-consumer system using a single shared buffer showcasing synchronization primitives, thread safety, and data sharing between threads.

C++17, std::mutex and std::condition_variable for synchronization between threads, Linux platform as a target, Google C++ Style Guide for coding conventions and style.

## Example of Setup, Running and Testing
Here's a summarized workflow:

### Setup

1. Clone the CppCodeSnippets repository:
    ```sh
    git clone https://github.com/diegomendez40/CppCodeSnippets.git
    ```

2. Download Google Test:
    - Download the latest release of Google Test from the [Google Test GitHub releases page](https://github.com/google/googletest/releases).
    - Extract the contents of the downloaded archive into the `206 Multithread/single-buffer/tests/gtest` directory.

3. Create a build directory and navigate to it:
    ```sh
    mkdir build && cd build
    ```

4. Run CMake and build the project:
    ```sh
    cmake ..
    make
    ```

### Running the Program

```sh
./producer_consumer
```

### Running the Tests

```sh
./tests
```

By following these steps, you should be able to see your producer-consumer implementation in action and ensure that everything is working as expected.

## Project Structure

- `src/`: Contains the source files for the producer, consumer, and shared buffer implementations.
- `include/`: Contains the header files for the producer, consumer, and shared buffer classes.
- `tests/`: Contains the test files and the GTest framework.

## Dependencies

- [Google Test](https://github.com/google/googletest): The project uses Google Test for unit testing. You need to download and extract it into the `tests/gtest` directory.

## Notes

- Ensure that you have CMake and a compatible C++ compiler installed on your system.
- The project is configured to use C++17 standard.