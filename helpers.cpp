#include <string>
#include <iostream>
#include <syncstream>
#include <map>


void synchronizedOut(const std::string& message) {
    std::osyncstream(std::cout) << message;
}

std::map<int, std::multimap<std::string, int>> CreateMap(){
    std::map<int, std::multimap<std::string, int>> result;

    std::multimap<std::string, int> set1{
            {"a",1},
            {"b",1},
            {"b",7},
            {"c",6},
            {"d",3},
            {"e",1},
            {"f",2},
            {"f",8},
            {"g",5},
            {"h",4},
            {"i",6},
            {"j",3}
    };

    std::multimap<std::string, int> set2{
            {"a",2},
            {"b",2},
            {"c",1},
            {"c",7},
            {"d",4},
            {"e",2},
            {"f",3},
            {"f",9},
            {"g",6},
            {"i",1},
            {"i",7},
            {"j",4}
    };
    std::multimap<std::string, int> set3{
            {"a",3},
            {"b",3},
            {"c",2},
            {"c",8},
            {"d",5},
            {"e",3},
            {"f",4},
            {"g",1},
            {"g",7},
            {"i",2},
            {"i",8},
            {"j",5}
    };
    std::multimap<std::string, int> set4{
            {"a",4},
            {"b",4},
            {"c",3},
            {"c",9},
            {"d",6},
            {"e",4},
            {"f",5},
            {"g",2},
            {"h",1},
            {"i",3},
            {"i",9},
            {"j",6}
    };
    std::multimap<std::string, int> set5{
            {"a",5},
            {"b",5},
            {"c",4},
            {"d",1},
            {"d",7},
            {"e",5},
            {"f",6},
            {"g",3},
            {"h",2},
            {"i",4},
            {"j",1}
    };
    std::multimap<std::string, int> set6{
            {"a",6},
            {"b",6},
            {"c",5},
            {"d",2},
            {"d",8},
            {"f",1},
            {"f",7},
            {"g",4},
            {"h",3},
            {"i",5},
            {"j",2}
    };
    result[1]=set1;
    result[2]=set2;
    result[3]=set3;
    result[4]=set4;
    result[5]=set5;
    result[6]=set6;
    return result;
}