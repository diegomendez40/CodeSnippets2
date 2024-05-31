#include "producer.h"
#include <gtest/gtest.h>

TEST(ProducerTest, Run) {
    // Test the run function
    SharedBuffer buffer(10);
    std::mutex startMutex;
    std::condition_variable startCondition;
    bool producerStarted = false;
    Producer producer(buffer, 5, 10, startMutex, startCondition, producerStarted);
    producer.run();
    EXPECT_EQ(buffer.size(), 5);
}