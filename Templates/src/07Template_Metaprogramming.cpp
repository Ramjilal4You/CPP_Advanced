// C++ template metaprogramming
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Template metaprogramming for calculating factorial at compile-time
template <int N> 
struct Factorial
{
  static const int value = N * Factorial<N - 1>::value;
};

// Specialization for the base case (Factorial<0>)
template <> 
struct Factorial<0>
{
  static const int value = 1;
};

int main()
{
  // Factorial computation happens at compile-time
  cout << "Factorial of 5 is: " << Factorial<5>::value;
  return 0;
}

/* In powershell window
g++ [option] <input file> -o <output file>
-E                       Preprocess only; do not compile, assemble or link. (.i)
-S                       Compile only; do not assemble or link. (.s)
-c                       Compile and assemble, but do not link. (.o)
-o <file>                Place the output into <file>. (.exe)
*/