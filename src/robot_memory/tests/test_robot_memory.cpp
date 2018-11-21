#include <catch_ros/catch.hpp>
#include <memory_bucket.h>

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

#include <custom_msgs/ImagesAndBoxes.h>

TEST_CASE("test_memory_buffer", "memory_node") {
    // check buffer empty
    MemoryBucket<custom_msgs::ImagesAndBoxes> memory;
    REQUIRE(memory.fetchDataFromBuffer(0) == nullptr);
    REQUIRE(memory.fetchDataFromBuffer(1) == nullptr);

    // add some dummy data to the buffer
    auto data = boost::make_shared<custom_msgs::ImagesAndBoxes const>(custom_msgs::ImagesAndBoxes());
    auto dataCopy = boost::make_shared<custom_msgs::ImagesAndBoxes const>(custom_msgs::ImagesAndBoxes());
    memory.storeDataInBuffer(data);
    memory.storeDataInBuffer(dataCopy);

    // check buffer has data and other buffers don't
    assert(data != dataCopy);
    REQUIRE(memory.fetchDataFromBuffer(0) == dataCopy);
    REQUIRE(memory.fetchDataFromBuffer(1) == data);
}

// test to make sure that old stored data is deleted after the buffer reaches max size of (5)
TEST_CASE("test_buffer_overflowing", "memory_node") {
    MemoryBucket<custom_msgs::ImagesAndBoxes> memory;

    // fill up the buffer and put dataCopy in first
    auto data = boost::make_shared<custom_msgs::ImagesAndBoxes const>(custom_msgs::ImagesAndBoxes());
    auto dataCopy = boost::make_shared<custom_msgs::ImagesAndBoxes const>(custom_msgs::ImagesAndBoxes());
    memory.storeDataInBuffer(dataCopy);
    memory.storeDataInBuffer(data);
    memory.storeDataInBuffer(data);
    memory.storeDataInBuffer(data);
    memory.storeDataInBuffer(data);

    // The oldest (last) item should be dataCopy
    assert(data != dataCopy);
    REQUIRE(memory.fetchDataFromBuffer(4) == dataCopy);

    // add to buffer to cause old dataCopy to get removed
    memory.storeDataInBuffer(data);
    // check old data removed and not pushed back farther
    REQUIRE(memory.fetchDataFromBuffer(4) == data);
    REQUIRE(memory.fetchDataFromBuffer(5) == nullptr);
}