/**
 * @file main.cpp
 * @brief Main function demonstrating the producer-consumer pattern.
 * @details
 * This file creates and starts producer and consumer threads to simulate concurrent production and consumption of stock quotes.
 * 
 * @author diegomendez40 (Diego Méndez Romero)
 * @date May 31, 2024
 * @version 1.0
 */

#include "shared_buffer.h"
#include "producer.h"
#include "consumer.h"
#include <thread>
#include <mutex>
#include <condition_variable>

/**
 * @brief Main function demonstrating the producer-consumer pattern.
 * Creates and starts producer and consumer threads to simulate concurrent production and consumption of stock quotes.
 * @return int Exit status.
 */
int main() {
    const size_t bufferSize = 10; ///< Size of the shared buffer.
    const size_t numItems = 100; ///< Number of items to produce and consume.

    SharedBuffer buffer(bufferSize); ///< Shared buffer instance.

    std::mutex startMutex; ///< Mutex to coordinate the start.
    std::condition_variable startCondition; ///< Condition variable to coordinate the start.
    bool producerStarted = false; ///< Flag to indicate if the producer has started.

    Producer producer(buffer, numItems, 100, startMutex, startCondition, producerStarted); ///< Producer instance.
    Consumer consumer(buffer, numItems, startMutex, startCondition, producerStarted); ///< Consumer instance.

    // Create and start producer and consumer threads
    std::thread producerThread(&Producer::run, &producer);
    std::thread consumerThread(&Consumer::run, &consumer);

    // Wait for both threads to finish
    producerThread.join();
    consumerThread.join();

    return 0;
}