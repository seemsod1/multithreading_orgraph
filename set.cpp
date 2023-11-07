#include <string>
#include "helpers.h"


void f(const std::string& setName, int action) {
    synchronizedOut("From set " + setName + " do action: " + std::to_string(action) + ".\n");
}