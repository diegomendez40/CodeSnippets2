#include "stock_quote.h"
#include <gtest/gtest.h>

TEST(StockQuoteTest, ConstructorWithArguments) {
    auto now = std::chrono::system_clock::now();
    StockQuote quote(now, "AAPL", 100.0, 100.5, 1000, 1500);

    EXPECT_EQ(quote.symbol, "AAPL");
    EXPECT_EQ(quote.bidPrice, 100.0);
    EXPECT_EQ(quote.askPrice, 100.5);
    EXPECT_EQ(quote.bidVolume, 1000);
    EXPECT_EQ(quote.askVolume, 1500);
}