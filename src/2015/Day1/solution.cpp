#include <iostream>
#include <fstream>
#include <vector>
#include "../../util.hpp"

namespace adventofcode2015 {

    void solution1()
    {
        std::vector<char> input_data = getInput("input1.txt");

        int floor = 0;

        for(auto i : input_data)
        {
            if(i == '(')
                floor += 1;
            else if(i == ')')
                floor -= 1;
        }

        std::cout << floor << std::endl;

    }

    void solution2()
    {
        std::vector<char> input_data = getInput("input1.txt");

        int floor = 0;
        int pos = 0;

        for(auto i : input_data)
        {
            if(i == '(')
                floor += 1;
            else if(i == ')')
                floor -= 1;
            
            pos += 1;

            if(floor < 0)
                break;
        }

        std::cout << pos << std::endl;
    }

}

int main()
{
    adventofcode2015::solution1();
    adventofcode2015::solution2();
    return 0;
}