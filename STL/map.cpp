#include<iostream>
#include<map>
#include<set>
using namespace std;

void display(const std::map<std::string,std::set<int>> &m)
{
    cout<<"[ ";
    for(const auto &t:m)
    {
        cout<<t.first<<":[";
        for(const auto & s:t.second)
            std::cout<<s<<" ";
        std::cout<<"]";
    }
    cout<<"]"<<endl;
}

template <typename T1,typename T2>
void display(const std::map<T1,T2> &l)
{
    cout<<"[ ";
    for(const auto &t:l)
    {
        cout<<t.first<<":"<<t.second<<" ";
    }
    cout<<" ]"<<endl;
}

void test1()
{
    cout<<"test1=========================="<<endl;
    std::map<std::string,int>m{
    {"Larry",3},{"Moe",1},{"Curly",2}};
    display(m);
    m.insert(std::make_pair("Anna",10));
      display(m);
    m["Joe"]=5;
      display(m);
    m["Frank"]=18;
      display(m);
    m["Frank"]+=10;
      display(m);
      m.erase("Frank");
        display(m);
        cout<<"Count for Frank:"<<m.count("Frank")<<endl;
        cout<<"Count for Joe:"<<m.count("Joe")<<endl;
        if(m.find("Larry")!=m.end())
            cout<<"Found Larry"<<endl;
        auto it=m.find("Larry");
        if(it!=m.end())
            cout<<it->first<<":"<<it->second<<endl;
        m.clear();
          display(m);
      cout<<endl;
}

void test2()
{
    cout<<"test2=========================="<<endl;
     std::map<std::string,std::set<int>>m{
     {"Larry",{100,90}},{"Moe",{94}},{"Curly",{80,90,100}}};
       display(m);
       m["Larry"].insert(95);
         display(m);
         auto it=m.find("Moe");
         if(it!=m.end())
            it->second.insert(1000);
           display(m);
      cout<<endl;
}

int main()
{
    test1();
    test2();
}
