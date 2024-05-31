/**
 * @file consumer.cpp
 * @brief Implementations for the Consumer class.
 * @details
 * This class represents a consumer that retrieves stock quotes from a shared buffer and processes them.
 * The implementation includes waiting for the producer to start.
 * 
 * @author diegomendez40 (Diego Méndez Romero)
 * @date May 31, 2024
 * @version 1.0
 */

#include "consumer.h"
#include <iostream>

// Implementation

Consumer::Consumer(SharedBuffer& buffer, size_t numItems,
                   std::mutex& startMutex, std::condition_variable& startCondition, bool& producerStarted)
    : buffer(buffer), numItems(numItems),
      startMutex(startMutex), startCondition(startCondition), producerStarted(producerStarted) {}

void Consumer::run() {
    {
        std::unique_lock<std::mutex> lock(startMutex);
        startCondition.wait(lock, [this] { return producerStarted; });
    }

    for (size_t i = 0; i < numItems; ++i) {
        try {
            StockQuote quote = buffer.pop();
            processQuote(quote);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught while processing quote: " << e.what() << std::endl;
        }
    }
}

void Consumer::processQuote(const StockQuote& quote) {
    std::cout << "Consumed quote: " << quote.symbol << " - Bid: " << quote.bidPrice
              << " Ask: " << quote.askPrice << std::endl;
}