#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) : db(obj.db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if(this != &obj)
        db = obj.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::load_db(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open database." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        size_t pos = line.find(',');
        if(pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        std::string price_str = line.substr(pos + 1);
        float price = std::atof(price_str.c_str());
        db[date] = price;
    }
    file.close();
}

bool BitcoinExchange::isValiDate(const std::string& date)
{
    if (date.length() != 10)
        return  false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if(i == 4 || i == 7) 
            continue;
        if(!std::isdigit(date[i]))
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if(month < 1 || month > 12)
        return false;
    if(day < 1 || day > 31)
        return false;
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        days[1] = 29;
    if (day > days[month - 1])
        return false;
    return true;
}

void BitcoinExchange::process(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pos = line.find(" | ");
        if(pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string value_str = line.substr(pos + 3 );
        if(!isValiDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        char *end;
        double value = std::strtod(value_str.c_str(), &end);
        if (*end != '\0' && *end != '\n')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if(value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = db.lower_bound(date);
        if(it == db.end() || it->first != date)
        {
            if ( it == db.begin())
            {
                std::cerr << "Error: date too early." << std::endl;
                continue;
            }
            --it;
        }
        double res = value * it->second;
        std::cout << date << " => " << value << " = " << res << std::endl;
    }
    file.close();
}