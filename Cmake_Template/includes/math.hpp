

#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <string>

using namespace std;
/**
* Provide function ----> sum two integers.
*/

// two templates parameters.

// Variadic Template ----> template can take more than one argument, 
    // caller ---> determine number of arguments.

// Number of arguments (base case):

    // 1. 0 or more argument.
int sum ()
{
    return 0; // return value without any side-effect.
}
    // 2. 1 or more argument (DONE).
// Template overloading.
template < typename T>
T sum(const T& a)
{
    return a;
}
    // 3. 2 or more argument (DONE).

// T: int ,     U: int ,      Ts: {int, double, int}     
template < typename T , typename U, typename ... Ts > // parameter packing.
auto sum (const T& a, const U & b, const Ts & ... values)
{
    // Solution 1: Tail recursion.
    // 1. check number of arguments ---> values.
        // values ---> 0 ---> add a + b.
        
    // if constexpr ( sizeof...(Ts) > 0 )
    // {
    //     // values > 0 ---> 
    //         // 1. add a + b ---> result.
    //         // 2. sum (result , values ...)
    //         auto r = a + b;
    //         return sum( r , values ... ); // parameters un-pack.
    // }
    // else 
    // {
    //     return a + b;
    // }
    // Solution 2: Folding expression.
    auto r = a + b;
    return  r + sum(values ...);
}

// function template specialization
template <>
auto sum<string, string> (const string & a, const string & b)
{
    return a.length() + b.length();
}

#endif 