#ifndef CONSUMER_H
#define CONSUMER_H

/**
 * @file consumer.h
 * @brief Declarations for the Consumer class.
 * @details
 * This class represents a consumer that retrieves stock quotes from a shared buffer and processes them.
 * 
 * @author diegomendez40 (Diego Méndez Romero)
 * @date May 31, 2024
 * @version 1.0
 */

#include "shared_buffer.h"
#include <mutex>
#include <condition_variable>

/**
 * @brief Class representing a consumer that retrieves stock quotes from a shared buffer and processes them.
 */
class Consumer {
public:
    /**
     * @brief Constructs a Consumer instance.
     * @param buffer Reference to a SharedBuffer where the consumed quotes will be retrieved from.
     * @param numItems Number of stock quotes to consume.
     * @param startMutex Mutex to coordinate the start with the producer.
     * @param startCondition Condition variable to wait for the producer.
     * @param producerStarted Flag to check if the producer has started.
     */
    Consumer(SharedBuffer& buffer, size_t numItems,
             std::mutex& startMutex, std::condition_variable& startCondition, bool& producerStarted);

    /**
     * @brief Starts the consumption of stock quotes.
     * Retrieves stock quotes from the shared buffer and processes them.
     */
    void run();

private:
    /**
     * @brief Processes a stock quote.
     * This function simulates processing by printing the quote details.
     * @param quote The stock quote to process.
     */
    void processQuote(const StockQuote& quote);

    SharedBuffer& buffer; ///< Reference to the shared buffer.
    size_t numItems; ///< Number of stock quotes to consume.
    std::mutex& startMutex; ///< Mutex to coordinate the start with the producer.
    std::condition_variable& startCondition; ///< Condition variable to wait for the producer.
    bool& producerStarted; ///< Flag to check if the producer has started.
};

#endif