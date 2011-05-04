#ifndef TD3_UTILITY_HPP_INCLUDED
#define TD3_UTILITY_HPP_INCLUDED

#include <string>
#include <vector>

//Work around for scoped using statements
#define string std::string
#define vector std::vector

class td3Utility
{
public:
    static string toString(int, bool);
    static string toString(double, bool);
    static vector<vector<string> > makeVector(string, string);
    static bool isFloat(string);
    static int stoi(string);
    static double stof(string);
};

//undefine the previously defined aliases
#undef string
#undef vector


#endif // TD3_UTILITY_HPP_INCLUDED
