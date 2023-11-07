#include <set>
#include <thread>
#include <barrier>
#include <map>
#include <latch>
#include "set.h"
#include "helpers.h"

const int nt = 6;
std::latch allwork(70);
std::barrier workerThreadStoppedBarrier(nt);
//[]{ synchronizedOut("Barrier reached!\n"); }

class WorkerThread{
private:
    std::multimap<std::string,int> m;
public:
    WorkerThread(const std::multimap<std::string,int> &s) : m(s){};
    void operator()(){
        for (const auto& [key, value]: m){
            if(key=="j"){
                f(key, value);
                allwork.count_down();
                workerThreadStoppedBarrier.arrive_and_drop();
            }else {
                f(key, value);
                allwork.count_down();
                workerThreadStoppedBarrier.arrive_and_wait();
            }
        }
    }
};




int main() {
    std::map<int, std::multimap<std::string, int>> setmap=CreateMap();

    synchronizedOut("Start Working\n");
    std::jthread t1(( WorkerThread( setmap[1] ) ) );
    std::jthread t2(( WorkerThread( setmap[2] ) ) );
    std::jthread t3(( WorkerThread( setmap[3] ) ) );
    std::jthread t4(( WorkerThread( setmap[4] ) ) );
    std::jthread t5(( WorkerThread( setmap[5] ) ) );
    std::jthread t6(( WorkerThread( setmap[6] ) ) );

    allwork.wait();
    synchronizedOut("End Working\n");


return 0;
}


