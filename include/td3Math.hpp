#ifndef TD3_MATH_HPP_INCLUDED
#define TD3_MATH_HPP_INCLUDED

#include <vector>
#include <string>
#include <map>

//Work around for scoped using statements
#define map std::map
#define string std::string
#define vector std::vector

class td3Math
{
private:
    static map<string, string (*)(vector<vector<string> >) > functions;
    static string plus(vector<vector<string> >);
    static string minus(vector<vector<string> >);
    static string mult(vector<vector<string> >);
    static string div(vector<vector<string> >);
    static string exponent(vector<vector<string> >);
    static string mod(vector<vector<string> >);
public:
    static void setFunctions(string);
    static void setFunctions(string, string (* func)(vector<vector<string> >));
    static string wrapper(vector<vector<string> >, string);
};

//undefine the previously defined aliases
#undef map
#undef string
#undef vector

#endif // TD3_MATH_HPP_INCLUDED
