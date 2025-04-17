#ifndef threadpool_src_unboundedmpmcqueue_h
#define threadpool_src_unboundedmpmcqueue_h


#include <deque>
#include <mutex>
#include <condition_variable>

template<typename T>
class UnboundedMPMCQueue {
public:
    void put(T task) {
        std::lock_guard lock(m_mutex);
        m_tasks.emplace_back(std:move(T));
    }


    T take() {

    }

private:
    std::mutex m_mutex;
    std::condition_variable m_notEmptyQueue;
    std::deque<T> m_tasks;
};




#endif
