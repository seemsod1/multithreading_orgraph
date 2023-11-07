#include <string>
#include <thread>
#include "helpers.h"
#include <syncstream>
#include <iostream>

void f(const std::string& setName, int action) {
   // std::thread::id this_id = std::this_thread::get_id();
    //std::osyncstream(std::cout) << "From set " + setName + " do action: " + std::to_string(action) + "." <<"Thread " << this_id << "\n";
  synchronizedOut("From set " + setName + " do action: " + std::to_string(action) + ". \n");
}