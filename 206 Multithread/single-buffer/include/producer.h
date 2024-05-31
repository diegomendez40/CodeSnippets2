#ifndef PRODUCER_H
#define PRODUCER_H

/**
 * @file producer.h
 * @brief Declarations for the Producer class.
 * @details
 * This class represents a producer that generates stock quotes and pushes them to a shared buffer.
 * 
 * @author diegomendez40 (Diego Méndez Romero)
 * @date May 31, 2024
 * @version 1.0
 */

#include "shared_buffer.h"
#include <mutex>
#include <condition_variable>

/**
 * @brief Class representing a producer that generates stock quotes and pushes them to a shared buffer.
 */
class Producer {
public:
    /**
     * @brief Constructs a Producer instance.
     * @param buffer Reference to a SharedBuffer where the produced quotes will be stored.
     * @param numItems Number of stock quotes to produce.
     * @param sleepDurationMs Duration to sleep between producing quotes, in milliseconds.
     * @param startMutex Mutex to coordinate the start with the consumer.
     * @param startCondition Condition variable to notify the consumer.
     * @param producerStarted Flag to indicate if the producer has started.
     */
    Producer(SharedBuffer& buffer, size_t numItems, int sleepDurationMs,
             std::mutex& startMutex, std::condition_variable& startCondition, bool& producerStarted);

    /**
     * @brief Starts the production of stock quotes.
     * Generates random stock quotes and pushes them to the shared buffer.
     */
    void run();

private:
    SharedBuffer& buffer; ///< Reference to the shared buffer.
    size_t numItems; ///< Number of stock quotes to produce.
    int sleepDurationMs; ///< Duration to sleep between producing quotes, in milliseconds.
    std::mutex& startMutex; ///< Mutex to coordinate the start with the consumer.
    std::condition_variable& startCondition; ///< Condition variable to notify the consumer.
    bool& producerStarted; ///< Flag to indicate if the producer has started.
};

#endif