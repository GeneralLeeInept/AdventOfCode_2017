// Day 2: Corruption Checksum
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        std::ifstream input(argv[1]);

        if (input)
        {
            int checksum = 0;
            std::string line;

            while (std::getline(input, line))
            {
                std::stringstream line_parser(line);
                int min = std::numeric_limits<int>::max();
                int max = std::numeric_limits<int>::min();

                while (!line_parser.eof())
                {
                    int value;
                    line_parser >> value;
                    min = std::min(min, value);
                    max = std::max(max, value);
                }

                if (min < std::numeric_limits<int>::max() && max > std::numeric_limits<int>::min())
                {
                    int spread = max - min;
                    checksum += spread;
                }
            }

            printf("%d\n", checksum);
        }
    }

    getchar();

    return 0;
}