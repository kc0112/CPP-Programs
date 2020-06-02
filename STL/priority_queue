#include<iostream>
#include<queue>
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
void display(std::priority_queue<T> pq)
{
    cout<<"[ ";
    while(!pq.empty())
    {
        T elem=pq.top();
        pq.pop();
        cout<<elem<<" ";

    }
    cout<<" ]"<<endl;
}

void test1()
{
    cout<<"test1=========================="<<endl;
 std::priority_queue<int>pq;
    for(int i:{3,5,7,12,23,12,4,100,0,3,5,7})
      {
        pq.push(i);
      }

    cout<<"Size : "<<pq.size()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    display(pq);
    pq.pop();
    display(pq);
     cout<<endl;
}

void test2()
{
    cout<<"test2=========================="<<endl;
     std::priority_queue<Person>pq;
     pq.push(Person("A",10));
     pq.push(Person("B",1));
     pq.push(Person("C",14));
     pq.push(Person("D",18));
     pq.push(Person("E",7));
     pq.push(Person("F",27));
     display(pq);
     cout<<endl;
}

int main()
{
    test1();
    test2();
}

