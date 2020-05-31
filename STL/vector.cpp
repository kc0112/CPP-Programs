#include<iostream>
#include<vector>
#include<list>
#include<cctype>
#include<algorithm>
#include<string>
using namespace std;
class Person
{
    friend std::ostream& operator<<(ostream &out,const Person &p);
public:
    int age;
    std::string name;

    Person()=default;
    Person(int age,std::string name):age{age},name{name}{}
     bool operator <(const Person&rhs)const{
    return this->age>rhs.age;}
    bool operator ==(const Person &rhs)const{
    return ((this->age==rhs.age)&&(this->name==rhs.name));}
};

std::ostream&operator<<(ostream&out,const Person&p)
{
    out<<p.name<<":"<<p.age;
    return out;
}

template <typename T>
void display(std::vector<T>&vec)
{
    cout<<"[ ";
    for(const auto &v:vec)
      cout<<v<<" ";
    cout<<" ]"<<endl;
}

void test1()
{
    cout<<"test1=========================="<<endl;
    std::vector<int>vec{1,2,3,4,5};
    display(vec);
    vec={2,3,4,5};
    display(vec);
    std::vector<int>vec1(10,100);
    display(vec1);
    cout<<endl;
}

void test2()
{
    cout<<"test2=========================="<<endl;
  std::vector<int>vec{1,2,3,4,5};
  display(vec);
  cout<<"vec size :"<<vec.size()<<endl<<"vec capacity: "<<vec.capacity()<<endl;
  vec.push_back(6);
  display(vec);
  cout<<"vec size :"<<vec.size()<<endl<<"vec capacity: "<<vec.capacity()<<endl;
  vec.shrink_to_fit();
  display(vec);
  cout<<"vec size :"<<vec.size()<<endl<<"vec capacity: "<<vec.capacity()<<endl;
   vec.reserve(100);
   display(vec);
  cout<<"vec size :"<<vec.size()<<endl<<"vec capacity: "<<vec.capacity()<<endl;
   cout<<endl;
}

void test3()
{
    cout<<"test3=========================="<<endl;
    std::vector<int>vec{1,2,3,4,5};
  display(vec);
  vec.at(0)=100;
  vec[1]=200;
  display(vec);
 cout<<endl;
}

void test4()
{
    cout<<"test4=========================="<<endl;
    std::vector<Person>vec;
    display(vec);
    Person p1{19,"Moe"};
    vec.push_back(p1);
    display(vec);
    vec.push_back(Person{17,"Curly"});
    display(vec);
    vec.emplace_back(18,"Larry");
    display(vec);
 cout<<endl;
}

void test5()
{
    cout<<"test5=========================="<<endl;
    std::vector<Person>vec{{18,"Larry"},{18,"Curly"},{17,"Moe"}};
    display(vec);
    cout<<"Front : "<<vec.front()<<endl;
    cout<<"Back : "<<vec.back()<<endl;
    vec.pop_back();
    display(vec);
 cout<<endl;
}

void test6()
{
    cout<<"test6=========================="<<endl;
     std::vector<int>vec{1,2,3,4,5};
  display(vec);
  vec.clear();
  display(vec);
  std::vector<int>vec1{1,2,3,4,5,6,7,8,9,10};
  vec1.erase(vec1.begin(),vec1.begin()+2);
  display(vec1);
vec={1,2,3,4,5,6,7,8,9,10};
auto it=vec.begin();
while(it!=vec.end())
{
    if(*it%2==0)
    vec.erase(it);
    else
    it++;
}
display(vec);
 cout<<endl;
}

void test7()
{
    cout<<"test7=========================="<<endl;
    std::vector<int>vec{1,2,3,4,5};
  display(vec);
  std::vector<int>vec1{10,20};
  display(vec1);

  std::copy(vec.begin(),vec.end(),std::back_inserter(vec1));
  display(vec);
  display(vec1);
  vec={1,2,3,4,5};
  vec1={10,20};
  std::copy_if(vec.begin(),vec.end(),std::back_inserter(vec1),[](int x){return x%2==0;});
  display(vec);
  display(vec1);

 cout<<endl;
}

void test8()
{
    cout<<"test8=========================="<<endl;
    std::vector<int>vec{1,2,3,4,5};
    std::vector<int>vec1{10,20,30,40,50};
    std::vector<int>vec2;

    std::transform(vec.begin(),vec.end(),vec1.begin(),std::back_inserter(vec2),[](int x,int y){return x*y;});
display(vec2);
cout<<endl;
}



  int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
}

