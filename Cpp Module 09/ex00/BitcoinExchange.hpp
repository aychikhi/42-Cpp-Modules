#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> db;
        bool isValiDate(const std::string& date);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();
        void load_db(const std::string& filename);
        void process(const std::string& filename);
};