#ifndef TD3_UTILITY_HPP_INCLUDED
#define TD3_UTILITY_HPP_INCLUDED

#include <string>
#include <vector>

class td3Utility
{
public:
    static std::string toString(int, bool);
    static std::string toString(double, bool);
    static std::vector<std::vector<std::string> > makeVector(std::string, std::string);
    static bool isFloat(std::string);
    static int stoi(std::string);
    static double stof(std::string);
};

#endif // TD3_UTILITY_HPP_INCLUDED
