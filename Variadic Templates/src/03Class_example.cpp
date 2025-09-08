// Variadic Templates - Class Example
#include <iostream>

template<typename... Args>
class Printer {
public:
    Printer() {}

    // Base case: when there's no argument left
    void printImpl() {
        // Base case: do nothing
    }

    // Recursive case: print the first argument and call printImpl with the rest
    template<typename First, typename... Rest>
    void printImpl(First first, Rest... rest) {
        std::cout << first << " ";
        printImpl(rest...);
    }

    template<typename... Args1>
    int print(Args1... args) {
        return sizeof...(args);
    }
};

int main() {
    Printer<int, double, std::string> printer;
    printer.printImpl(42, 3.14, "Hello, World!");

    int count = printer.print(1, 2.5, "Test", 'A', 100);
    std::cout << "\nTotal arguments printed: " << count << std::endl;

    return 0;
}
