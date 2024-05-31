#include "shared_buffer.h"
#include "producer.h"
#include "consumer.h"
#include <gtest/gtest.h>

TEST(IntegrationTest, ProducerConsumer) {
    // Test the complete producer-consumer system
    const size_t bufferSize = 10;
    const size_t numItems = 100;
    SharedBuffer buffer(bufferSize);
    std::mutex startMutex;
    std::condition_variable startCondition;
    bool producerStarted = false;
    Producer producer(buffer, numItems, 10, startMutex, startCondition, producerStarted);
    Consumer consumer(buffer, numItems, startMutex, startCondition, producerStarted);

    std::thread producerThread(&Producer::run, &producer);
    std::thread consumerThread(&Consumer::run, &consumer);

    producerThread.join();
    consumerThread.join();

    EXPECT_EQ(buffer.size(), 0);
}