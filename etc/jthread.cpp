// Run with in g++
/*
g++ jthread_interrupt.cpp -Wall -Wextra -std=gnu++2a
*/

#include <chrono>
#include <iostream>
#include <thread>

using namespace ::std::literals;

void SomeThread(std::stop_token itoken, int* value)
{
    int v = *value;
    while (true)
    {
        std::this_thread::sleep_for(0.2s);
        if (itoken.stop_requested())
            break;
        std::cout << "v = " << v << std::endl;
    }
}

int main()
{
    std::cout << std::endl;

    std::jthread nonInterruptable([] {  // (1)
        int counter{0};
        while (counter < 10)
        {
            std::this_thread::sleep_for(0.2s);
            std::cerr << "nonInterruptable: " << counter << std::endl;
            ++counter;
        }
    });

    std::jthread interruptable([](std::stop_token itoken) {  // (2)
        int counter{0};
        while (counter < 10)
        {
            std::this_thread::sleep_for(0.2s);
            if (itoken.stop_requested())
                return;  // (3)
            std::cerr << "interruptable: " << counter << std::endl;
            ++counter;
        }
    });
    
    int v = 100;
    std::jthread jt = std::jthread(&SomeThread, (int*)&v);

    std::this_thread::sleep_for(1s);

    std::cerr << std::endl;
    std::cerr << "Main thread interrupts both jthreads" << std::endl;
    nonInterruptable.request_stop();
    interruptable.request_stop();  // (4)
    
    jt.request_stop();

    std::cout << std::endl;

    return 0;
}