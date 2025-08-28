// 05Ostream.hxx
// Custom ostream class definition mimicking std::ostream interface 
#pragma once
#include <streambuf>
#include <ios>
#include <locale>
/**
 * @class ostream
 * @brief Custom output stream class, similar to std::ostream.
 *
 * Inherits from std::ios and provides overloaded operator<< functions
 * for various data types, enabling formatted output to a stream buffer.
 * Also supports manipulators and direct character/byte output.
 *
 * @note This class is intended for demonstration or extension purposes,
 * and mimics the interface of the standard ostream.
 *
 * @constructor
 *  - explicit ostream(std::streambuf* sb): Constructs an ostream with the given stream buffer.
 *  - protected ostream(): Default constructor, protected for inheritance.
 *
 * @destructor
 *  - virtual ~ostream(): Cleans up resources.
 *
 * @deleted
 *  - ostream(const ostream&) = delete: Copy constructor is deleted.
 *  - ostream& operator=(const ostream&) = delete: Copy assignment is deleted.
 *
 * @overloads
 *  - operator<<: Overloaded for bool, short, unsigned short, int, unsigned int,
 *    long, unsigned long, long long, unsigned long long, float, double,
 *    long double, const void*, const char*, char, signed char, unsigned char.
 *    Enables output of these types to the stream.
 *
 * @manipulators
 *  - operator<<(ostream& (*pf)(ostream&)): Accepts manipulators like endl.
 *  - operator<<(std::ios& (*pf)(std::ios&)): Accepts ios manipulators.
 *  - operator<<(std::ios_base& (*pf)(std::ios_base&)): Accepts ios_base manipulators.
 *
 * @methods
 *  - put(char c): Writes a single character to the stream.
 *  - write(const char* s, std::streamsize n): Writes n characters from s to the stream.
 *  - flush(): Flushes the stream buffer.
 */
class ostream : public std::ios {
public:
    // Constructors & Destructor
    explicit ostream(std::streambuf* sb);
    virtual ~ostream();

    // Overloaded operator<< for various types
    // Each function returns a reference to the ostream to allow chaining
    ostream& operator<<(bool val);
    ostream& operator<<(short val);
    ostream& operator<<(unsigned short val);
    ostream& operator<<(int val);
    ostream& operator<<(unsigned int val);
    ostream& operator<<(long val);
    ostream& operator<<(unsigned long val);
    ostream& operator<<(long long val);
    ostream& operator<<(unsigned long long val);
    ostream& operator<<(float val);
    ostream& operator<<(double val);
    ostream& operator<<(long double val);
    ostream& operator<<(const void* val);
    ostream& operator<<(const char* val);
    ostream& operator<<(char val);
    ostream& operator<<(signed char val);
    ostream& operator<<(unsigned char val);

    // Direct character/byte output
    // Note: These functions return ostream& to allow chaining
    ostream& put(char c);
    ostream& write(const char* s, std::streamsize n);
    ostream& flush();

    // Manipulators
    // Note: These should be non-member functions, but are declared here for simplicity
    ostream& operator<<(ostream& (*pf)(ostream&));
    ostream& operator<<(std::ios& (*pf)(std::ios&));
    ostream& operator<<(std::ios_base& (*pf)(std::ios_base&));

protected:
    // Protected default constructor for inheritance
    ostream();  // Protected default constructor
    ostream(const ostream&) = delete;   // Copy constructor is deleted
    ostream& operator=(const ostream&) = delete;    // Copy assignment is deleted
};
