#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        int jacobsthal(int n);
        void binaryInsert(std::vector<int>& chain, int val, int end);
        void binaryInsert(std::deque<int>& chain, int val, int end);
        void fjSort(std::vector<int>& v);
        void fjSort(std::deque<int>& d);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();
        void parse(int ac, char **av);
        void sort();
        void display();
};