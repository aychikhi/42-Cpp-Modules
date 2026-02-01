#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <cstdlib>
#include <climits> 
#include <iomanip>
#include <cmath>  

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(const std::string& literal);
	private:
		static bool isCharLiteral(const std::string& s);
		static bool isInt(const std::string& s);
		static bool isFloat(const std::string& s);
		static bool isDouble(const std::string& s);
		static void printChar(char c);
		static void printInt(int i);
		static void printDouble(double d);
		static void printFloat(float f);
};

#endif