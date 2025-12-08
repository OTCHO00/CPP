#pragma once
#include <tuple>
#include <string>
#include <vector>

class Roi {

    public:

        std::string image;
        std::vector<std::tuple<int, int>> direction;

        Roi();

};