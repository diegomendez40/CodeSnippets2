#include "consumer.h"
#include <gtest/gtest.h>

TEST(ConsumerTest, Run) {
    // Test the run function
    SharedBuffer buffer(10);
    std::mutex startMutex;
    std::condition_variable startCondition;
    bool producerStarted = true;
    Consumer consumer(buffer, 5, startMutex, startCondition, producerStarted);
    auto now = std::chrono::system_clock::now();
    StockQuote quote(now, "AAPL", 100.0, 100.5, 1000, 1500);
    for (int i = 0; i < 5; ++i) {
        buffer.push(quote);
    }
    consumer.run();
    EXPECT_EQ(buffer.size(), 0);
}