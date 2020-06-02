#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool is_palindrome(const std::string& s)
{
    std::stack<char>s1;
   std::queue<char>q;
    for(char c:s)
    {
        if(isalpha(c))
       {
           q.push(tolower(c));
       s1.push(tolower(c));
       }
    }
    while(!q.empty())
    {
        if(s1.top()!=q.front())
        {
             return false;
        }
        s1.pop();q.pop();
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
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
