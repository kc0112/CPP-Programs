#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

class Person
{
    friend ostream&operator<<(ostream &out,const Person &obj);
    std::string name;
    int age;

public:
    Person():name{"Unknown"},age{0}{}
    Person(string name,int age):name{name},age{age}{}

    bool operator <(const Person &rhs)const {
    return this->age<rhs.age;}

    bool operator ==(const Person &rhs)const{
    return this->name==rhs.name&&this->age==rhs.age;}
};

ostream&operator<<(ostream &out,const Person &obj)
{
    out<<obj.name<<":"<<obj.age;
    return out;
}

template <typename T>
void display(std::set<T> &s)
{
    std::cout<<"[ ";
    for(auto &e:s)
        cout<<e<<" ";
    cout<<" ]"<<endl;
}

void test1()
{
    cout<<"test1=========================="<<endl;
    std::set <int>s{1,4,3,5,2};
    display(s);
    s={1,2,3,1,1,1,1,3,3,4,5};
    display(s);

    s.insert(0);
    s.insert(10);

    display(s);
    if(s.count(10))
        cout<<"10 is in the set"<<endl;
        else
            cout<<"10 is not in the set"<<endl;
    auto it=s.find(5);
    if(it!=s.end())
        cout<<"found : "<<*it<<endl;
        else
            cout<<"not found"<<endl;

        s.clear();
        display(s);
    cout<<endl;
}

void test2()
{
    cout<<"test2=========================="<<endl;
    std::set<std::string>s{{"Larry",1},{"Moe",2},{"Curly",3}};
       display(s);
       s.emplace("James",50);
          display(s);
          s.emplace("Frank",50);
             display(s);
    cout<<endl;
}

void test3()
{
    cout<<"test3=========================="<<endl;
      std::set<string>s{"A","B","C"};
         display(s);
         s.insert("D");
            display(s);

    cout<<endl;
}

int main()
{
    test1();
    test2();
    test3();
}
