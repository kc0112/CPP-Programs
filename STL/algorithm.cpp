#include<iostream>
#include<vector>
#include<list>
#include<cctype>
#include<algorithm>
#include<string>

class Person
{
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

void find_test()
{
    std::vector<int>vec{1,2,3,4,5};
    std::vector<int>::iterator loc=std::find(std::begin(vec),std::end(vec),9);

    if(loc!=std::end(vec))
        std::cout<<"FOUND KEY : "<<*loc<<std::endl;
    else
        std::cout<<"KEY NOT FOUND"<<std::endl;

        std::list<Person>player{
            {30,"Sapan"},{35,"Tapan"},{19,"Khushi"}};
            auto loc1=std::find(player.begin(),player.end(),Person{19,"Khushi"});
            if(loc1!=std::end(player))
        std::cout<<"FOUND KEY : "<<loc1->name<<std::endl;
    else
        std::cout<<"KEY NOT FOUND"<<std::endl;
}

void count_test()
{
    std::vector<int>vec{1,2,3,1,1,3,4,5};
    int it=std::count(vec.begin(),vec.end(),1);
    std::cout<<it<<" times occoured"<<std::endl;
}

void count_if_test()
{
    std::vector<int>vec{1,2,3,1,1,3,4,5,6,8,9};
  auto it=std::count_if(vec.begin(),vec.end(),[](int x){return (x%2==0);});
    std::cout<<it<<" even no.occoured"<<std::endl;
  it=std::count_if(vec.begin(),vec.end(),[](int x){return (x%2!=0);});
  std::cout<<it<<" odd no.occoured"<<std::endl;
  it=std::count_if(vec.begin(),vec.end(),[](int x){return (x>=5);});
  std::cout<<it<<" no.occoured"<<std::endl;
}

void replace_test()
{
    std::vector<int>vec{1,2,3,1,1,3,4,5,6,8,9};
    for(int v:vec)
    {
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;
    std::replace(vec.begin(),vec.end(),1,7);
    for(int v:vec)
    {
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;

}

void all_of_test()
{
    std::vector<int>vec{1,2,3,1,1,3,4,5,6,8,9};
    if(std::all_of(vec.begin(),vec.end(),[](int x){return (x<=20);}))
        std::cout<<"ALL NO. ARE LESS THAN 20"<<std::endl;
    else
         std::cout<<"ALL NO. ARE GREATER THAN 20"<<std::endl;
}

void string_transform_test()
{
    std::string str{"This is a test"};
    std::cout<<"STRING BEFORE TRANSFORM: "<<str<<std::endl;
    std::transform(str.begin(),str.end(),str.begin(),::toupper);
    std::cout<<"STRING AFTER TRANSFORM: "<<str<<std::endl;
}

int main()
{
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();
}
