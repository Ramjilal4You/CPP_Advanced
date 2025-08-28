// C++ template metaprogramming
#include <iostream>
using namespace std;

/*
    C++ Template Metaprogramming
    ============================
    * Template metaprogramming allows us to perform computations at compile-time using templates.
    * This can lead to more efficient code by avoiding runtime calculations.
*/

// Base Case : Specialization for Factorial<0>
template <> 
struct Factorial<0>
{
  static const int value = 1;
};

// Template metaprogramming for calculating factorial at compile-time
template <int N> 
struct Factorial
{
  static const int value = N * Factorial<N - 1>::value;
};

// Function to calculate factorial using the Factorial template
int CalFact(int n){
  return Factorial<5>::value;
}

int main()
{
  // Factorial computation happens at compile-time
  int res = CalFact(5);
  cout << "Factorial of 5 is: " << res << endl;
  return 0;
}





/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/