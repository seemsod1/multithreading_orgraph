#include <string>
#include <iostream>
#include <syncstream>

//
// Created by admin on 01.11.2023.
//

std::mutex ioMutex;

void synchronizedOut(const std::string& message) {
    std::lock_guard<std::mutex> lock(ioMutex);
    std::cout << message;
}