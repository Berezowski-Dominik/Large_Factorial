// Large_Factorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
In mathematics, the factorial of integer n is written as n!. It is equal to the product of n and every integer preceding it. For example: 5! = 1 x 2 x 3 x 4 x 5 = 120

Your mission is simple: write a function that takes an integer n and returns the value of n!.

You are guaranteed an integer argument. For any values outside the non-negative range, return null, nil or None (return an empty string "" in C and C++). For non-negative numbers a full length number is expected for example, return 25! = "15511210043330985984000000" as a string.

For more on factorials, see http://en.wikipedia.org/wiki/Factorial

NOTES:

The use of BigInteger or BigNumber functions has been disabled, this requires a complex solution

I have removed the use of require in the javascript language.

*/

#include <iostream>
#include <string>

using namespace std;

string factorial(int factorial);

int main()
{
    cout << factorial(4);
}

string factorial(int factorial)
{
    string returnNumber = "";           //  start value

    int arrayValue[500];                //  max elements in array is 500 it is large number

    arrayValue[0] = 1;   

    int res_size = 1;

    for (int x = 2; x <= factorial; x++)    
    {
        int carry = 0;

        for (int i = 0; i < res_size; i++)  //  if we have number smaller, then 10 we change this same element
        {   
            //  example 3! 1*2*3 = 6    arrayValue[0] = 6

            int prod = arrayValue[i] * x + carry;   

            arrayValue[i] = prod % 10;

            carry = prod / 10;
        }
        
        //  but example 4! 1*2*3*4 = 24    arrayValue[0] = 4 arrayValue[1] = 2

        //  use this metod we can calculate 100! if use long double we can't save this number normal. It is biggest

        while (carry)                  //   if element number is lagre, then 10
        {
            arrayValue[res_size] = carry % 10;
            carry = carry / 10;
            res_size++;
        }
    }
        
    //  we add element to value string return
    for (int i = res_size - 1; i >= 0; i--)
        returnNumber += to_string(arrayValue[i]);

    return returnNumber;
}