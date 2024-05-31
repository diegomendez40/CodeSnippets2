#include "shared_buffer.h"
#include <gtest/gtest.h>

TEST(SharedBufferTest, PushAndPop) {
    // Test pushing and popping elements
    SharedBuffer buffer(10);
    auto now = std::chrono::system_clock::now();
    StockQuote quote(now, "AAPL", 100.0, 100.5, 1000, 1500);
    buffer.push(quote);
    StockQuote poppedQuote = buffer.pop();
    EXPECT_EQ(poppedQuote.symbol, "AAPL");
    EXPECT_EQ(poppedQuote.bidPrice, 100.0);
    EXPECT_EQ(poppedQuote.askPrice, 100.5);
    EXPECT_EQ(poppedQuote.bidVolume, 1000);
    EXPECT_EQ(poppedQuote.askVolume, 1500);
}