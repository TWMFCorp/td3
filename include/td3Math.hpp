#ifndef TD3_MATH_HPP_INCLUDED
#define TD3_MATH_HPP_INCLUDED

#include <vector>
#include <string>
#include <map>

class td3Math
{
private:
    std::map<std::string, std::string (*)(std::vector<std::vector<std::string> >) > functions;
    static std::string plus(std::vector<std::vector<std::string> >);
    static std::string minus(std::vector<std::vector<std::string> >);
    static std::string mult(std::vector<std::vector<std::string> >);
    static std::string div(std::vector<std::vector<std::string> >);
    static std::string exponent(std::vector<std::vector<std::string> >);
    static std::string mod(std::vector<std::vector<std::string> >);
public:
    void setFunctions(std::string);
    void setFunctions(std::string, std::string (* func)(std::vector<std::vector<std::string> >));
    std::string wrapper(std::vector<std::vector<std::string> >, std::string);
};

#endif // TD3_MATH_HPP_INCLUDED
