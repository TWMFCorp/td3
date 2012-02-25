#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "include/td3Math.hpp"
#include "include/td3Utility.hpp"
#include "include/testcases.hpp"

using namespace std;

int test(string);

int main()
{
    srand(time(NULL));
    td3Math::setFunctions("all");
    string ops [] = {"+","-","*","/","^","%"};
    int error = 0;
    for (unsigned int i = 0; i < 6; ++i)
        error += test(ops[i]);
    return error;
}

template <typename T, typename Y>
string realResult(T op1, Y op2, string op)
{
    bool floating = !(op1 == floor(op1) && op2 == floor(op2));
    if (op == "+")
        return td3Utility::toString(op1 + op2, floating);
    else if (op == "-")
        return td3Utility::toString(op1 - op2, floating);
    else if (op == "*")
        return td3Utility::toString(op1 * op2, floating);
    else if (op == "/")
        return td3Utility::toString(op1 / op2, floating);
    else if (op == "^")
        return td3Utility::toString( pow((double)op1, op2), floating);
    else if (op == "%")
        return td3Utility::toString( fmod((double)op1, (double)op2), floating);
    else
        return "";
}

int test(string op)
{
    int error = 0;
    int i1 = testcases::randi(), i2 = testcases::randi(), i3 = testcases::randi(), i4 = testcases::randi();
    double d1 = testcases::randd(), d2 = testcases::randd(), d3 = testcases::randd(), d4 = testcases::randd();
    cout << "Testing " << op << ": ";
    error += (td3Math::wrapper({{td3Utility::toString(i1,0)},{td3Utility::toString(i2,0)}},op) != realResult(i1,i2,op));
//    cout << endl << "\"" 
//         << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(i1,0),td3Utility::toString(i2,0)),op)
//         << "\" should be \""
//         << realResult(i1,i2,op) << "\"";
    error += (td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(i3,0),td3Utility::toString(d1,1)),op) != realResult(i3,d1,op));
//    cout << endl << "\""
//         << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(i3,0),td3Utility::toString(d1,0)),op) 
//         << "\" should be \"" 
//         << result(i3,d1,op) << "\"";
    error += (td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d2,1),td3Utility::toString(i4,0)),op) != realResult(d2,i4,op));
//    cout << endl << "\""
//         << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d2,0),td3Utility::toString(i4,0)),op)
//         << "\" should be \""
//         << result(d2,i4,op) << "\"";
    error += (td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d3,1),td3Utility::toString(d4,1)),op) != realResult(d3,d4,op));
//    cout << endl << "\""
//         << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d3,0),td3Utility::toString(d4,0)),op)
//         << "\" should be \""
//         << result(d3,d4,op) << "\"";
//    cout << endl;
    cout <<  error << " errors" << endl;
    return error;
}
