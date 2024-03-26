#ifndef QUEUE_CLASS_CPP
#define QUEUE_CLASS_CPP

#include "Queue_class.h"

void BufferQueue::push(const std::string& str)
{
    std::lock_guard<std::mutex> lock(m_queueMutex);
    m_bufferQueue.push(str);
    m_cv.notify_all();
}

std::string BufferQueue::pop()
{
    std::unique_lock<std::mutex> lock(m_queueMutex);
    m_cv.wait(lock, [this] { return !m_bufferQueue.empty(); });
    auto data = m_bufferQueue.front();
    m_bufferQueue.pop();
    return data;
}

bool BufferQueue::empty() const
{
    std::lock_guard<std::mutex> lock(m_queueMutex);
    return m_bufferQueue.empty();
}

void BufferQueue::clear()
{
    std::lock_guard<std::mutex> lock(m_queueMutex);
    while (!m_bufferQueue.empty())
    {
        m_bufferQueue.pop();
    }
}

#endif
