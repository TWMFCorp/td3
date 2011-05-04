#ifndef TD3_UTILITY_HPP_INCLUDED
#define TD3_UTILITY_HPP_INCLUDED

#include <string>
#include <vector>

class td3Utility
{
    using std::string;
    using std::vector;
public:
    static string toString(int, bool);
    static string toString(double, bool);
    static vector<vector<string> > makeVector(string, string);
    static bool isFloat(string);
    static int stoi(string);
    static double stof(string);
};

#endif // TD3_UTILITY_HPP_INCLUDED
