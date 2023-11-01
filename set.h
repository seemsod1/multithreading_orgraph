//
// Created by admin on 01.11.2023.
//

#ifndef INC_3LAB_SET_H
#define INC_3LAB_SET_H

#include <string>
#include <vector>

struct Set {
    std::string setName;  // Назва набору дій
    std::vector<int> actionsIds;  // Вектор ідентифікаторів дій
};

void f(const std::string& set, int action);
#endif //INC_3LAB_SET_H
