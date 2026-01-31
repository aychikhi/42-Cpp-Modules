#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(std::string s)
{
	if (str.length() != 1)
		return false;
	char c = str[0];
	if (!std::isprint(c) || std::isdigit(c))
		return false;
	return true;
}

bool ScalarConverter::isInt(std::string s)
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

bool ScalarConverter::isDouble(std::string s)
{
    if (s == "nan" || s == "inf" || s == "+inf" || s == "-inf")
        return true;
    if (s.find('.') == std::string::npos)
        return false;
    char *end;
    std::strtod(s.c_str(), &end);
    return (*end == '\0');
}

bool ScalarConverter::isFloat(std::string s)
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

void ScalarConverter::convert(const std::string& literal)
{
    if ()
}

