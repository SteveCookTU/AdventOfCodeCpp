#include <iostream>
#include <fstream>
#include <vector>
#include <string>

static std::vector<char> getInput(std::string path)
{
    std::ifstream input(path);
    input.seekg(0, std::ios_base::end);
    const unsigned int file_length = input.tellg();
    input.seekg(0);
    std::vector<char> input_data(file_length);
    input.read(&input_data[0], file_length);
    input.close();

    return input_data;
}

static std::vector<std::string> getInputAsLines(std::string path)
{
    std::vector<std::string> lines;
    std::fstream inputFile;
    inputFile.open(path, std::ios::in);
    if(inputFile.is_open())
    {
        std::string line;
        while(std::getline(inputFile, line))
        {
            lines.push_back(line);
        }
        inputFile.close();
    }
    return lines;
}