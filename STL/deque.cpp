#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
void display(const std::deque<T> &d){
 cout<<"[ ";
 for(const auto &v:d)
 {
     cout<<v<<" ";
 }
 cout<<" ]"<<endl;
}

void test1()
{
    cout<<"test1=========================="<<endl;
    std::deque<int>d{1,2,3,4,5};
    display(d);
    d={2,4,5,6};
    display(d);
    std::deque<int>d1(10,100);
    display(d1);
    d.at(1)=200;
    d[0]=100;
    display(d);
     cout<<endl;
}

void test2()
{
    cout<<"test2=========================="<<endl;
    std::deque<int>d(3,0);
    display(d);
    d.push_back(10);
    d.push_back(20);
    display(d);
    d.push_front(100);
    d.push_front(200);
    display(d);
    cout<<"Front: "<<d.front()<<endl;
    cout<<"Back: "<<d.back()<<endl;
    cout<<"Size: "<<d.size()<<endl;
    d.pop_front();
    d.pop_back();
    display(d);
     cout<<endl;
}

void test3()
{
    cout<<"test3=========================="<<endl;
    std::deque<int>d1{1,2,3,4,5,6,7,8,9,10};
    std::deque<int>d;
    for(const auto v:d1)
    {
        if(v%2==0)
            d.push_back(v);
        else
            d.push_front(v);
    }
    display(d);
 cout<<endl;
}

void test4()
{
    cout<<"test4=========================="<<endl;
    std::deque<int>d1{1,2,3,4,5,6,7,8,9,10};
    std::deque<int>d;
    for(const auto v:d1)
      d.push_front(v);
    display(d);
      d.clear();
      for(const auto v:d1)
      d.push_back(v);
    display(d);
 cout<<endl;
}

void test5()
{
    cout<<"test5========================="<<endl;
      std::deque<int>d1{1,2,3,4,5,6,7,8,9,10};
    std::deque<int>d;
    std::copy(d1.begin(),d1.end(),std::front_inserter(d));
    display(d);
    d.clear();
    std::copy(d1.begin(),d1.end(),std::back_inserter(d));
    display(d);
 cout<<endl;
}

  int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
