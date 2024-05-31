#ifndef STOCK_QUOTE_H
#define STOCK_QUOTE_H

/**
 * @file stock_quote.h
 * @brief Declarations for the StockQuote class.
 * @details
 * This struct represents a stock quote with details such as symbol (ticker), bid price, ask price, and volumes.
 * 
 * @author diegomendez40 (Diego Méndez Romero)
 * @date May 31, 2024
 * @version 1.0
 */

#include <chrono>
#include <string>

/**
 * @brief A structure representing a stock quote.
 */
struct StockQuote {
    std::chrono::system_clock::time_point timestamp; ///< The time of the quote.
    std::string symbol; ///< The stock symbol (ticker).
    double bidPrice; ///< The bid price of the stock.
    double askPrice; ///< The ask price of the stock.
    int64_t bidVolume; ///< The volume of stocks available at the bid price.
    int64_t askVolume; ///< The volume of stocks available at the ask price.

    /**
     * @brief Constructor to initialize all member variables.
     * @param ts Timestamp of the quote.
     * @param sym Stock symbol.
     * @param bidP Bid price.
     * @param askP Ask price.
     * @param bidV Bid volume.
     * @param askV Ask volume.
     */
    StockQuote(std::chrono::system_clock::time_point ts, const std::string& sym, double bidP, double askP, int64_t bidV, int64_t askV)
        : timestamp(ts), symbol(sym), bidPrice(bidP), askPrice(askP), bidVolume(bidV), askVolume(askV) {}
};

#endif // STOCK_QUOTE_H