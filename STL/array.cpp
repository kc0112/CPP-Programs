#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>
using namespace std;

void display(std::array<int,5>&arr)
{
    for(auto &i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void test1()
{
    cout<<"===============test1=========================="<<endl;
    std::array<int,5>arr1{1,2,3,4,5};
    std::array<int,5>arr2;
    display(arr1);
    display(arr2);
    arr2= {10,20,30,40,50};
    display(arr1);
    display(arr2);

    cout<<"Size of arr1 is : "<<arr1.size()<<endl;
    cout<<"Size of arr2 is : "<<arr2.size()<<endl;

    arr1.at(0)=1000;
    arr1[1]=2000;
    display(arr1);

    cout<<"Front of arr2 is : "<<arr2.front()<<endl;
    cout<<"Back of arr2 is : "<<arr2.back()<<endl;

}

void test2()
{
    cout<<endl<<"===============test2=========================="<<endl;
    std::array<int,5>arr1{1,2,3,4,5};
    std::array<int,5>arr2{10,20,30,40,50};
    display(arr1);
    display(arr2);
    arr1.fill(0);
    display (arr1);
    display(arr2);
    arr1.swap(arr2);
    display (arr1);
    display(arr2);
}

void test3()
{
    cout<<endl<<"===============test3=========================="<<endl;
    std::array<int,5>arr1{1,2,3,4,5};
    std::array<int,5>arr2{10,20,30,40,50};
    int *d=arr1.data();
    cout<<d<<endl;
    *d=10000;
    display(arr1);
}

void test4()
{
    cout<<endl<<"================test4==================================="<<endl;
    std::array<int,5>arr{2,1,4,3,5};
    display(arr);
    std::sort(arr.begin(),arr.end());
    display(arr);
}

void test5()
{
    cout<<endl<<"================test5=================================="<<endl;
    std::array<int,5>arr{2,1,3,4,0};
    std::array<int,5>::iterator it=std::min_element(arr.begin(),arr.end());
    cout<<"min: "<<*it<<endl;
    it=std::max_element(arr.begin(),arr.end());
    cout<<"max: "<<*it<<endl;
}

void test6()
{
     cout<<endl<<"================test6=================================="<<endl;
    std::array<int,5>arr{2,1,3,3,4};
    auto it=adjacent_find(arr.begin(),arr.end());
    if(it!=arr.end())
        cout<<"Adjacent element found : "<<*it<<endl;
    else cout<<"Adjacent element not found"<<endl;
}

void test7()
{
     cout<<endl<<"================test7=================================="<<endl;
     std::array<int,5>a{2,1,4,5,6};
     int it=accumulate(a.begin(),a.end(),0);
     cout<<"sum: "<<it<<endl;
}

void test8()
{
     cout<<endl<<"================test8=================================="<<endl;
     std::array<int,10>a{1,2,3,3,3,3,4,4,4,3};
     int c=std::count(a.begin(),a.end(),3);
     cout<<"Found 3: "<<c<<" times"<<endl;
}

void test9()
{
     cout<<endl<<"================test9=================================="<<endl;
     std::array<int,10>a{1,2,3,50,60,70,80,200,300,400};
     int c=std::count_if(a.begin(),a.end(),[](int x){return x>10&&x<200;});
                         cout<<"Found "<<c<<" matches"<<endl;
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
