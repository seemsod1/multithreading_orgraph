#include <string>
#include "helpers.h"

//
// Created by admin on 01.11.2023.
//
void f(const std::string& setName, int action) {
    synchronizedOut("From set " + setName + " do action: " + std::to_string(action) + ".\n");
}