#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include "td3Math.hpp"
#include "td3Utility.hpp"

using std::string;
using std::vector;
using std::pow;
using std::fmod;

void td3Math::setFunctions(string operation)
{
    setFunctions(operation, static_cast<string (*)(vector<vector<string> >)>(0));
    return;
}

void td3Math::setFunctions(string operation, string (* func)(vector<vector<string> >))
{
    if (func != 0)
        functions[operation] = func;
    else 
    {
        if (operation == "+" || operation == "all")
            functions["+"] = plus;
        if (operation == "-" || operation == "all")
            functions["-"] = minus;
        if (operation == "*" || operation == "all")
            functions["*"] = mult;
        if (operation == "/" || operation == "all")
            functions["/"] = div;
        if (operation == "^" || operation == "all")
            functions["^"] = exponent;
        if (operation == "%" || operation == "all")
            functions["%"] = mod;
    }
    return;
}

string td3Math::wrapper(vector<vector<string> > operands,string operation)
{
    return functions[operation](operands);
}

string td3Math::plus(vector<vector<string> > operands)
{
    bool op1 = td3Utility::isFloat(operands.at(0).at(0));
    bool op2 = td3Utility::isFloat(operands.at(1).at(0));    
    return td3Utility::toString( (op1 ? td3Utility::stof(operands.at(0).at(0)) : td3Utility::stoi(operands.at(0).at(0))) + (op2 ? td3Utility::stof(operands.at(1).at(0)) : td3Utility::stoi(operands.at(1).at(0))), op1 || op2);
}

string td3Math::minus(vector<vector<string> > operands)
{
    bool op1 = td3Utility::isFloat(operands.at(0).at(0));
    bool op2 = td3Utility::isFloat(operands.at(1).at(0));
    return td3Utility::toString( (op1 ? td3Utility::stof(operands.at(0).at(0)) : td3Utility::stoi(operands.at(0).at(0))) - (op2 ? td3Utility::stof(operands.at(1).at(0)) : td3Utility::stoi(operands.at(1).at(0))), op1 || op2);
}

string td3Math::mult(vector<vector<string> > operands)
{
    bool op1 = td3Utility::isFloat(operands.at(0).at(0));
    bool op2 = td3Utility::isFloat(operands.at(1).at(0));
    return td3Utility::toString( (op1 ? td3Utility::stof(operands.at(0).at(0)) : td3Utility::stoi(operands.at(0).at(0))) * (op2 ? td3Utility::stof(operands.at(1).at(0)) : td3Utility::stoi(operands.at(1).at(0))), op1 || op2);
}

string td3Math::div(vector<vector<string> > operands)
{
    bool op1 = td3Utility::isFloat(operands.at(0).at(0));
    bool op2 = td3Utility::isFloat(operands.at(1).at(0));
    return td3Utility::toString( (op1 ? td3Utility::stof(operands.at(0).at(0)) : td3Utility::stoi(operands.at(0).at(0))) / (op2 ? td3Utility::stof(operands.at(1).at(0)) : td3Utility::stoi(operands.at(1).at(0))), op1 || op2);
}

string td3Math::exponent(vector<vector<string> > operands)
{
    bool op1 = td3Utility::isFloat(operands.at(0).at(0));
    bool op2 = td3Utility::isFloat(operands.at(1).at(0));
    return td3Utility::toString( pow(td3Utility::stof(operands.at(0).at(0)),(op2 ? td3Utility::stof(operands.at(1).at(0)) : td3Utility::stoi(operands.at(1).at(0)))), op1 || op2);
}

string td3Math::mod(vector<vector<string> > operands)
{
    bool op1 = td3Utility::isFloat(operands.at(0).at(0));
    bool op2 = td3Utility::isFloat(operands.at(1).at(0));
    return td3Utility::toString( fmod((op1 ? td3Utility::stof(operands.at(0).at(0)) : td3Utility::stoi(operands.at(0).at(0))), (op2 ? td3Utility::stof(operands.at(1).at(0)) : td3Utility::stoi(operands.at(1).at(0)))), op1 || op2);
}
