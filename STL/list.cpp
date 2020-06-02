#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;

class Person
{
    friend ostream&operator<<(std::ostream &out,Person &obj);
private :
    std::string name;
    int age;
public:
    Person():name{"Unknown"},age{0}{}
    Person(std::string name,int age):name{name},age{age}{}
    bool operator <(const Person&rhs)const
    {
        return this->age<rhs.age;
    }
    bool operator ==(const Person &rhs)const
    {
        return (this->name==rhs.name&&this->age==rhs.age);
    }
    ~Person()=default;
};

ostream&operator<<(std::ostream &out,Person &obj)
{
    out<<obj.name<<" : "<<obj.age;
    return out;
}
template <typename T>
void display(std::list<T> &l)
{
    cout<<"[ ";
    for(auto &t:l)
    {
        cout<<t<<" ";
    }
    cout<<" ]"<<endl;
}

void test1()
{
    cout<<"test1=========================="<<endl;
    std::list<int>l{1,2,3,4,5};
    display(l);
    std::list<std::string>l1;
    l1.push_front("Front");
    l1.push_back("Back");
    display(l1);
    std::list<int>l3{1,2,3,4,5,6,7,8,9,10};
    std::list<int>l4(10,100);
    display(l3);
    display(l4);
    cout<<endl;
}

void test2()
{
    cout<<"test2=========================="<<endl;
   std::list<int>l{1,2,3,4,5,6,7,8,9,10};
    display(l);
    cout<<"size : "<<l.size()<<endl;
    cout<<"Front : "<<l.front()<<endl;
    cout<<"Back : "<<l.back()<<endl;
    l.clear();
    display(l);
    cout<<"size : "<<l.size()<<endl;
    cout<<endl;
}

void test3()
{
    cout<<"test3=========================="<<endl;
    std::list<int>l{1,2,3,4,5,6,7,8,9,10};
    display(l);
    l.resize(5);
    display(l);
    l.resize(10);
    display(l);
    std::list<Person>p;
    p.resize(5);
    display(p);
    cout<<endl;
}

void test4()
{
    cout<<"test4=========================="<<endl;
    std::list<int>l{1,2,3,4,5,6,7,8,9,10};
    display(l);
    std::list<int>::iterator it=std::find(l.begin(),l.end(),5);
    if(it!=l.end())
        l.insert(it,100);
    display(l);
    std::list<int>l2{1000,2000,3000};
    l.insert(it,l2.begin(),l2.end());
    display(l);
    std::advance(it,-4);
    cout<<*it<<endl;
    l.erase(it);
    display(l);
    cout<<endl;
}

void test5()
{
    cout<<"test5=========================="<<endl;
     std::list<Person>p{{"Larry",19},{"Curly",19},{"Moe",19}};
     display(p);
     string name;
     int age;
     cout<<"Enter name of next person :";
     getline(std::cin,name);
     cout<<"Enter age: ";
     cin>>age;
     p.emplace_back(name,age);
     display(p);
    auto it=std::find(p.begin(),p.end(),Person("Moe",19));
    if(it!=p.end())
        p.emplace(it,"Frank",18);
    display(p);
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
