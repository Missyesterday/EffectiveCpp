/*  
 *  Description : 条款04：确定对象被使用前已被初始化
 *  Created by 旋风冲锋龙卷风 on 2023/02/05 13:12
 *  个人博客 : http://letsgofun.cn/
 */
//

#include <vector>
#include <iostream>

using namespace std;

void test01()
{
    int x = 0;
    const char* text = "A C-style string"; //对指针进行手工初始化

    double d;
    cin >> d; //以读取 inputstream的方式完成初始化
}

class Person
{
public:
    Person() : age(0), name(), addr(), IPs()
    {}

    Person(const string &name, const string &addr, const vector<int>& IPs)
    {
        age = 0;
        this->name = name;
        this->addr = addr;
        this->IPs = IPs;
    }

    Person(const string &addr) : addr(addr)
    {}

    int age;
    string name;
    string addr =   "hyf";

    int B[10];

    Person(int age, const string &name, const string &addr, int *b, const vector<int> &iPs) : age(age), name(name),
                                                                                              addr(addr), IPs(iPs)
    {}

    vector<int> IPs;
};

void test02()
{
    Person p;
    cout << p.addr << endl;
}

class A
{
public:
    int a;
    int b;
    constexpr static const double c = 3.12;
public:
    A(int val) : b(val), a(b)
    {}
};

void test03()
{
    A a(1);

    cout << a.a << endl; // 0
    cout << a.b << endl; // 1
}
int main()
{
    test03();
    return EXIT_SUCCESS;
}
