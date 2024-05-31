#ifndef SHARED_BUFFER_H
#define SHARED_BUFFER_H

/**
 * @file shared_buffer.h
 * @brief Declarations for the SharedBuffer class.
 * @details
 * This class provides a thread-safe buffer for storing stock quotes.
 * 
 * @author diegomendez40 (Diego Méndez Romero)
 * @date May 31, 2024
 * @version 1.0
 */

#include <deque>
#include <mutex>
#include <condition_variable>
#include "stock_quote.h"

/**
 * @brief A thread-safe buffer to store stock quotes with a fixed maximum size.
 */
class SharedBuffer {
public:
    /**
     * @brief Constructs a SharedBuffer with a specified maximum size.
     * @param maxSize The maximum number of stock quotes the buffer can hold.
     */
    explicit SharedBuffer(size_t maxSize);

    /**
     * @brief Adds a stock quote to the buffer.
     * @param quote The stock quote to add.
     * @note This function will block if the buffer is full.
     */
    void push(const StockQuote& quote);
    
    /**
     * @brief Removes and returns the first stock quote from the buffer.
     * @return The first stock quote in the buffer.
     * @note This function will block if the buffer is empty.
     */
    StockQuote pop();
    
    /**
     * @brief Checks if the buffer is full.
     * @return true if the buffer is full, false otherwise.
     */
    bool isFull() const;
    
    /**
     * @brief Checks if the buffer is empty.
     * @return true if the buffer is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Returns the size of the buffer.
     * @return Number of currently stored elements in the buffer.
     */
    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex);
        return buffer.size();
    }

private:
    std::deque<StockQuote> buffer; ///< The buffer storing stock quotes.
    mutable std::mutex mutex; ///< Mutex for thread safety.
    std::condition_variable condVar; ///< Condition variable for synchronization.
    size_t maxSize; ///< Maximum size of the buffer.
};

#endif // SHARED_BUFFER_H