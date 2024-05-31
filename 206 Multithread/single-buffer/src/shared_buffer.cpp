/**
 * @file shared_buffer.cpp
 * @brief Implementations for the SharedBuffer class.
 * @details
 * This class provides a thread-safe buffer for storing stock quotes.
 * 
 * @author diegomendez40 (Diego Méndez Romero)
 * @date May 31, 2024
 * @version 1.0
 */

#include "shared_buffer.h"

SharedBuffer::SharedBuffer(size_t maxSize) : maxSize(maxSize) {}

void SharedBuffer::push(const StockQuote& quote) {
    std::unique_lock<std::mutex> lock(mutex);
    condVar.wait(lock, [this] { return buffer.size() < maxSize; });
    buffer.push_back(quote);
    lock.unlock();
    condVar.notify_one();
}

StockQuote SharedBuffer::pop() {
    std::unique_lock<std::mutex> lock(mutex);
    condVar.wait(lock, [this] { return !buffer.empty(); });
    StockQuote quote = std::move(buffer.front());
    buffer.pop_front();
    lock.unlock();
    condVar.notify_one();
    return quote;
}

bool SharedBuffer::isFull() const {
    std::lock_guard<std::mutex> lock(mutex);
    return buffer.size() == maxSize;
}

bool SharedBuffer::isEmpty() const {
    std::lock_guard<std::mutex> lock(mutex);
    return buffer.empty();
}