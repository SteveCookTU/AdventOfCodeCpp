#include <vector>
#include <map>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstdint>
#include <utility>
#include "../../util.hpp"

namespace adventofcode2015 
{
    
    class Index
    {
        public:
            Index(int x, int y);
            ~Index();
            
            bool operator <(const Index &rhs) const
            {
                std::size_t str_hashl = std::hash<std::string>{}(std::to_string(x) + "," + std::to_string(y));
                std::size_t str_hashr = std::hash<std::string>{}(std::to_string(rhs.x) + "," + std::to_string(rhs.y));
                return str_hashl < str_hashr;
            }

            bool operator ==(const Index &rhs) const
            {
                return x == rhs.x && y == rhs.y;
            }
            
        private:
            int x;
            int y;
    };

    Index::Index(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Index::~Index()
    {

    }

    void solution1()
    {
        std::vector<char> input_data = getInput("input1.txt");

        int currX = 0;
        int currY = 0;

        Index i(currX, currY);
        std::map<Index, int> presentTracker;
        presentTracker.insert(std::pair<Index, int>(i, 1));
        for(auto c : input_data)
        {
            if(c == '<')
                currX -= 1;
            else if(c == '>')
                currX += 1;
            else if(c == '^')
                currY += 1;
            else if(c == 'v')
                currY -= 1;

            i = Index(currX, currY);
            std::pair<std::map<Index, int>::iterator, bool> ret;
            ret = presentTracker.insert(std::pair<Index, int>(i, 1));
            if(ret.second == false)
            {
                ret.first->second += 1;
            }
        }
        std::cout << presentTracker.size() << std::endl;
    }

    void solution2()
    {
        std::vector<char> input_data = getInput("input1.txt");

        bool robo = false;
        int currX = 0;
        int currY = 0;
        int roboX = 0;
        int roboY = 0;
        Index i(currX, currY);
        std::map<Index, int> presentTracker;
        presentTracker.insert(std::pair<Index, int>(i, 2));
        for(auto c : input_data)
        {
            
            if(c == '<')
                robo ? roboX -= 1 : currX -= 1;
            else if(c == '>')
                robo ? roboX += 1 : currX += 1;
            else if(c == '^')
                robo ? roboY += 1 : currY += 1;
            else if(c == 'v')
                robo ? roboY -= 1 : currY -= 1;

            i = robo ? Index(roboX, roboY) : Index(currX, currY);
            std::pair<std::map<Index, int>::iterator, bool> ret;
            ret = presentTracker.insert(std::pair<Index, int>(i, 1));
            if(ret.second == false)
            {
                ret.first->second += 1;
            }
            robo = !robo;
        }
        std::cout << presentTracker.size() << std::endl;
    }
}

int main()
{
    adventofcode2015::solution1();
    adventofcode2015::solution2();
    return 0;
}