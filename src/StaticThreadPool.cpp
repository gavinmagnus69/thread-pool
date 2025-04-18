#include <iostream>


#include "StaticThreadPool.h"


stp::StaticThreadPool::StaticThreadPool(uint16_t threadCount)
: m_threadCount(threadCount)
{   
    initAll(threadCount);
}


stp::StaticThreadPool::~StaticThreadPool() {
    joinAll();
}


void stp::StaticThreadPool::putTask(Task&& task) {
    m_taskQueue.put(std::move(task));
}


void stp::StaticThreadPool::runWorker() {
    while(m_releaseAllWorkers == false) {
        Task task = m_taskQueue.take();
        task();
    }
}



void stp::StaticThreadPool::initAll(uint16_t threadCount) {
    m_releaseAllWorkers.store(false);
    for(int i = 0; i < threadCount; ++i) {
        m_workers.emplace_back([this]() { this->runWorker(); });
    }
}


void stp::StaticThreadPool::joinAll() {
    m_releaseAllWorkers.store(true);
    for(auto& worker : m_workers) {
        if(worker.joinable()) {
            worker.join();
        }
    }
}

