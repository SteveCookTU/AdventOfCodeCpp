#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstdint>
#include "../../util.hpp"

namespace adventofcode2015
{
    void solution1()
    {
        std::vector<std::string> input_data = getInputAsLines("input1.txt");

        int total = 0;

        for(auto i : input_data)
        {
            std::istringstream ss(i);
            std::string token;
            std::vector<int> dimensions;
            while(std::getline(ss, token, 'x'))
            {
                if(token != "\n")
                {
                    dimensions.push_back(std::atoi(token.c_str()));
                }
            }

            int length = dimensions[0];
            int width = dimensions[1];
            int height = dimensions[2];

            total += (2 * length * width) + (2 * width * height) + (2 * length * height) + std::min({length * width, width * height, length * height});
        }

        std::cout << total << std::endl;

    }

    void solution2()
    {
        std::vector<std::string> input_data = getInputAsLines("input1.txt");

        int total = 0;

        for(auto i : input_data)
        {
            std::istringstream ss(i);
            std::string token;
            std::vector<int> dimensions;
            while(std::getline(ss, token, 'x'))
            {
                if(token != "\n")
                {
                    dimensions.push_back(std::atoi(token.c_str()));
                }
            }

            int length = dimensions[0];
            int width = dimensions[1];
            int height = dimensions[2];

            total += (2 * std::min(length, width)) + (2 * (std::min(length, width) == length ? std::min(width, height) : std::min(length, height))) + (length * width * height);
        }

        std::cout << total << std::endl;
    }
}

int main()
{
    adventofcode2015::solution1();
    adventofcode2015::solution2();
    return 0;
}