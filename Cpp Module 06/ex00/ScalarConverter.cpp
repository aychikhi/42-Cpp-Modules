#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string& s)
{
	if (s.length() != 1)
		return false;
	char c = s[0];
	if (!std::isprint(c) || std::isdigit(c))
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string& s)
{
    if (s.empty())
        return false;
    char *end;
    long n = std::strtol(s.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    if (n < INT_MIN || n > INT_MAX)
        return false;
    return(true);
}

bool ScalarConverter::isDouble(const std::string& s)
{
    if (s == "nan" || s == "inf" || s == "+inf" || s == "-inf")
        return true;
    if (s.find('.') == std::string::npos)
        return false;
    char *end;
    std::strtod(s.c_str(), &end);
    return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string& s)
{
    if (s == "nanf" || s == "inff" || s == "+inff" || s == "-inff")
        return true;
    if (s.length() < 2 || s[s.length() - 1] != 'f')
        return false;
    std::string withoutF = s.substr(0, s.length() - 1);
    char *ptr;
    std::strtod(withoutF.c_str(), &ptr);
    return (*ptr == '\0');
}

void ScalarConverter::printChar(char c)
{
    if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl ;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) 
        << static_cast<float>(c) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) 
        << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(int i)
{
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) 
        << static_cast<float>(i) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) 
        << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (std::isnan(f) || std::isinf(f) || f < INT_MIN || f > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) 
              << f << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) 
        << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) 
              << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) 
              << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isCharLiteral(literal))
    {
        char c = literal[0];
        printChar(c);
        return;
    }
    else if (isInt(literal))
    {
        int i = std::atoi(literal.c_str());
        printInt(i);
        return;
    }
    else if (isFloat(literal))
    {
        float f = std::atof(literal.c_str());
        printFloat(f);
        return;
    }
    else if (isDouble(literal))
    {
        double d = std::atof(literal.c_str());
        printDouble(d);
        return;
    }
    else
        std::cout << "Invalid input!" << std::endl;

}

