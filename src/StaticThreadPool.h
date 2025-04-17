#ifndef threadpool_src_staticthreadpool_h
#define threadpool_src_staticthreadpool_h


#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>


namespace stp {

using Task = std::function<void(void)>;
    
class StaticThreadPool {
public:
    StaticThreadPool(uint16_t);
public:
    void putTask(Task&&); 
private:
    void runTasks();
    std::vector<std::thread> m_workers;

};


};
#endif