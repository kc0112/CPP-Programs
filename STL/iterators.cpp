#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>

using namespace std;

void display(const std::vector<int>&vec)
{
    cout<<"=========================================================="<<endl;
    for(int const &v:vec)
    {
        cout<<v<<endl;
    }

}

void test2()
{cout<<"=========================================================="<<endl;

std::vector<int>num1{1,2,3,4,5};
std::vector<int>::iterator it=num1.begin();
while(it!=num1.end())
{
    cout<<*it<<endl;
    it++;
}
it=num1.begin();
while(it!=num1.end())
{
    *it=0;
    it++;
}

display(num1);
}

void test3()
{
    cout<<"================================================"<<endl;
    std::vector<int>num{1,2,3,4,5};
    std::vector<int>::const_iterator it1=num.begin();
    //auto it1=num.cbegin();

    while(it1!=num.end())
    {
        cout<<*it1<<endl;
        it1++;
    }
}

void test4()
{
    cout<<"================================================"<<endl;
    std::vector<int>num{1,2,3,4,5};
    auto it2=num.rbegin();

    while(it2!=num.rend())
    {
        cout<<*it2<<endl;
        it2++;
    }

    cout<<"================================================"<<endl;
    std::list<std::string>name{"Tapan","Sapan","Khushi"};
    auto it3=name.rbegin();
    while(it3!=name.rend())
    {
        cout<<*it3<<endl;
        ++it3;
    }


    cout<<"================================================"<<endl;
    std::map<std::string,std::string>fav{{"Khushi","girl"},{"Tapan","boy"},{"Sapan","boy"}};
    auto it4=fav.begin();

    while(it4!=fav.end())
    {
        cout<<it4->first<<" "<<it4->second<<endl;
        it4++;
    }

}

void test1()
{
    cout<<"=========================================================="<<endl;
    std::vector<int>vec{1,2,3,4,5};
    auto it =vec.begin();
    cout<<*it<<endl;
    ++it;
    cout<<*it<<endl;
    --it;
    cout<<*it<<endl;
    it+=2;
    cout<<*it<<endl;
    it-=2;
    cout<<*it<<endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();

}
