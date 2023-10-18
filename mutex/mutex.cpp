#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx; // mutex
std::condition_variable cv; // condition_variable
bool data_ready = false;

void producer()
{
    std::this_thread::sleep_for(std::chrono::seconds(4)); // simulating production data time

    // data is ready, notify the consumer
    std::cout << "Producer: data is ready!" << std::endl;
    {
        std::lock_guard<std::mutex> lock(mtx);
        data_ready = true;
    }
    cv.notify_one();
}

void consumer()
{
    std::cout << "Consumer waiting for data..." << std::endl;

    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return data_ready; });

    // consume data
    std::cout << "Consumer: data is ready!" << std::endl;
}

int main()
{
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();
    
    std::cout << "Main: waiting for thread completion" << std::endl;

    return 0;
}


/* compile command: g++ mutex.cpp -o mutex -pthread */