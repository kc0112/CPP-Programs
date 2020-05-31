#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<cctype>
#include<algorithm>
using namespace std;


bool is_palindrome(const std::string& s)
{
    std::deque<char>d;
    for(char c:s)
    {
        if(std::isalpha(c))
        {
            d.push_back(std::toupper(c));
        }
    }
    std:deque<char>d1;
    for(auto k:d)
    {
        d1.push_front(k);
    }

    while(d.size()>1)
    {
        if(d.front()==d1.front())
        {
            d.pop_front();d1.pop_front();
        }
        else return false;
    }
   return true;
}


int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    cout<<"========================================================================="<<endl;
    for(const auto& s : test_strings){
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

