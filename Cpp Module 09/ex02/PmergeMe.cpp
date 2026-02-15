#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <utility> 
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) : vec(obj.vec), deq(obj.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if(this != &obj)
    {
        vec = obj.vec;
        deq = obj.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int ac, char **av)
{
    for(int i = 1; i < ac; i++)
    {
        std::string arg(av[i]);
        if(arg.empty())
            throw std::invalid_argument("Error");
        for(size_t j = 0; j < arg.size(); j++)
        {
            if(!std::isdigit(arg[j]))
                throw std::invalid_argument("Error"); 
        }
        long n = std::atol(arg.c_str());
        if(n <= 0 || n > INT_MAX)
            throw std::invalid_argument("Error");
        vec.push_back(static_cast<int>(n));
        deq.push_back(static_cast<int>(n));
    }
}

int PmergeMe::jacobsthal(int n)
{
    if(n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::binaryInsert(std::deque<int>& chain, int val, int end)
{
    int low = 0;
    int high = end;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (chain[mid] < val)
            low = mid + 1;
        else
            high = mid;
    }
    chain.insert(chain.begin() + low, val);
}

void PmergeMe::fjSort(std::deque<int>& d)
{
    if(d.size() <= 1)
        return;
    bool odd = (d.size() % 2 != 0);
    int lastElement = 0;
    if (odd)
        lastElement = d.back();
    std::deque<int> winners;
    std::deque<int> losers;
    for(size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if(d[i] > d[i + 1])
        {
            winners.push_back(d[i]);
            losers.push_back(d[i + 1]);
        }
        else
        {
            winners.push_back(d[i + 1]);
            losers.push_back(d[i]);
        }
    }
    std::deque<std::pair<int, int> > pairs;
    for(size_t i = 0; i < winners.size(); i++)
        pairs.push_back(std::make_pair(winners[i], losers[i]));
    fjSort(winners);
    losers.clear();
    for(size_t i = 0; i < winners.size(); i++)
    {
        for(size_t j = 0; j < pairs.size(); j++)
        {
            if(pairs[j].first == winners[i])
            {
                losers.push_back(pairs[j].second);
                pairs[j].first = -1;
                break;
            }
        }
    }
    std::deque<int> chain;
    chain.push_back(losers[0]);
    for(size_t i = 0; i < winners.size(); i++)
        chain.push_back(winners[i]);
    std::deque<int> toInsert;
    for(size_t i = 1; i < losers.size(); i++)
        toInsert.push_back(losers[i]);
    if(odd)
        toInsert.push_back(lastElement);
    std::deque<int> insertOrder;
    int jk = 2;
    int prev = 0;
    while (insertOrder.size() < toInsert.size())
    {
        int curr = jacobsthal(jk);
        int pos = curr;
        if (pos > (int)toInsert.size())
            pos = toInsert.size();
        while (pos > prev)
        {
            insertOrder.push_back(pos - 1);
            pos--;
        }
        prev = curr;
        jk++;
    }
    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        int indx = insertOrder[i];
        if(indx >= (int)toInsert.size())
            continue;
        binaryInsert(chain, toInsert[indx], chain.size());
    }
    d = chain;
}

void PmergeMe::binaryInsert(std::vector<int>& chain, int val, int end)
{
    int low = 0;
    int high = end;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (chain[mid] < val)
            low = mid + 1;
        else
            high = mid;
    }
    chain.insert(chain.begin() + low, val);
}

void PmergeMe::fjSort(std::vector<int>& v)
{
    if(v.size() <= 1)
        return;
    bool odd = (v.size() % 2 != 0);
    int lastElement = 0;
    if (odd)
        lastElement = v.back();
    std::vector<int> winners;
    std::vector<int> losers;
    for(size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if(v[i] > v[i + 1])
        {
            winners.push_back(v[i]);
            losers.push_back(v[i + 1]);
        }
        else
        {
            winners.push_back(v[i + 1]);
            losers.push_back(v[i]);
        }
    }
    std::vector<std::pair<int, int> > pairs;
    for(size_t i = 0; i < winners.size(); i++)
        pairs.push_back(std::make_pair(winners[i], losers[i]));
    fjSort(winners);
    losers.clear();
    for(size_t i = 0; i < winners.size(); i++)
    {
        for(size_t j = 0; j < pairs.size(); j++)
        {
            if(pairs[j].first == winners[i])
            {
                losers.push_back(pairs[j].second);
                pairs[j].first = -1;
                break;
            }
        }
    }
    std::vector<int> chain;
    chain.push_back(losers[0]);
    for(size_t i = 0; i < winners.size(); i++)
        chain.push_back(winners[i]);
    std::vector<int> toInsert;
    for(size_t i = 1; i < losers.size(); i++)
        toInsert.push_back(losers[i]);
    if(odd)
        toInsert.push_back(lastElement);
    std::vector<int> insertOrder;
    int jk = 2;
    int prev = 0;
    while (insertOrder.size() < toInsert.size())
    {
        int curr = jacobsthal(jk);
        int pos = curr;
        if (pos > (int)toInsert.size())
            pos = toInsert.size();
        while (pos > prev)
        {
            insertOrder.push_back(pos - 1);
            pos--;
        }
        prev = curr;
        jk++;
    }
    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        int indx = insertOrder[i];
        if(indx >= (int)toInsert.size())
            continue;
        binaryInsert(chain, toInsert[indx], chain.size());
    }
    v = chain;
}

static double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void PmergeMe::sort()
{
    std::cout << "Before:";
    for(size_t i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];
    std::cout << std::endl;
    double t1 = getTime();
    fjSort(vec);
    double t2 = getTime();

    double t3 = getTime();
    fjSort(deq);
    double t4 = getTime();
    std::cout << "After:";
    for(size_t i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " element with std::vector : " << (t2 - t1) << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " element with std::deque : " << (t4 - t3) << " us" << std::endl;
}