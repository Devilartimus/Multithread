#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H

#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>

class BufferQueue
{
private:
    std::queue<std::string> m_bufferQueue;
    mutable std::mutex m_queueMutex;
    std::condition_variable m_cv;

public:
    void push(const std::string& str);
    std::string pop();
    bool empty() const;
    void clear();
};

#endif
