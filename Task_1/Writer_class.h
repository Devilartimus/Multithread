#ifndef WRITER_CLASS_H
#define WRITER_CLASS_H


#include "Reader_class.h"
#include "Socket_class.h"

class Writer
{
private:
    BufferQueue& bufferQueue;
    Reader& reader;

public:
    Writer(BufferQueue& queue, Reader& reader)
        : bufferQueue(queue), reader(reader){}

    void operator()();
};

#endif

