#include <iostream>
#include <thread>
#include "Reader_class.cpp"
#include "Writer_class.cpp"
#include "Queue_class.cpp"

int main()
{
    BufferQueue queue;
    std::mutex queueMutex;
    std::condition_variable cv;

    Reader reader(queue);
    Writer writer(queue, reader);

    std::thread input(reader);
    std::thread output(writer);

    input.join();
    output.join();

    return 0;
}
