//! схема No6, nt=6, a=6, b=7, c=9, d=8, e=5, f=9, g=7, h=4, i=9, j=6

#include <vector>
#include <iostream>
#include "set.h"
#include "helpers.h"
#include <latch>
#include <thread>
#include <barrier>

const int nt =6;
std::barrier final(6, []{ synchronizedOut("----------------------------------------------\n"); });


void executeAction(std::string set, int id) {
    synchronizedOut("Thread started\n");
    f(set, id);
    final.arrive_and_wait();
}

int main() {
    std::latch l(6);
    std::vector<Set> sets = {
            { "a", {1,2,3,4,5,6} },
            { "b", {1,2,3,4,5,6,7} },
            { "c", {1,2,3,4,5,6,7,8,9} },
            { "d", {1,2,3,4,5,6,7,8} },
            { "e", {1,2,3,4,5} },
            { "f", {1,2,3,4,5,6,7,8,9} }
    };
    synchronizedOut("Start Working\n");
    std::vector<std::jthread> threads;
    int remainingElements = 0;

    for (const Set& set : sets) {


        for (int i = 0; i < set.actionsIds.size(); i++) {
            if (remainingElements == nt) {
                remainingElements = 0;
            }

            threads.emplace_back(executeAction, set.setName, set.actionsIds[i]);
            remainingElements++;
        }

        }
    l.wait();
    std::cout<<"End Working\n";
    return 0;
}


