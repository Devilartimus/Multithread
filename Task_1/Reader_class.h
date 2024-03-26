#ifndef READER_CLASS_H
#define READER_CLASS_H

#include "Queue_class.h"

class Reader
{
private:
    bool isValid(const std::string& str) const;

    BufferQueue& bufferQueue;

public:
    Reader(BufferQueue& bufferQueue)
        : bufferQueue(bufferQueue) {}

    void operator()();
};

#endif

