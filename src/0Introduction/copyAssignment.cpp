/*  
 *  Description : copy构造函数和copy assignment操作符
 *  Created by 旋风冲锋龙卷风 on 2023/01/31 19:40
 *  个人博客 : http://letsgofun.cn/
 */
//

#include <iostream>

using namespace std;

class Widget
{
private:
    int m_x;
    int m_y;
public:
    Widget(int mX, int mY) : m_x(mX), m_y(mY)
    {
        cout << "调用两个参数的构造函数" << endl;
    }

    Widget() : m_x(0), m_y(0)
    {
        cout << "调用默认构造函数" << endl;
    }

    //拷贝构造函数
    Widget(const Widget& rhs) : m_x(rhs.m_x), m_y(rhs.m_y)
    {
        cout << "调用copy 构造函数" << endl;

    }

    //copy assignment操作符重载
    Widget& operator=(const Widget& rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        cout << "调用copy assignment操作符的重载" << endl;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Widget &widget)
    {
        os << "m_x: " << widget.m_x << " m_y: " << widget.m_y;
        return os;
    }
};

void test01()
{
    Widget w1;//调用默认构造函数
    Widget w2(w1); //调用copy构造函数
    w1 = w2; //调用copy assignment操作符

    //如果有一个新的对象被定义,一定会有构造函数被调用,而不可能调用赋值操作
    Widget w3 = w1;//调用copy构造函数
    cout << w3 << endl;
}

//passed by value, aka值传递, 这个赋值动作是Widget的拷贝构造函数完成
void func(Widget w)
{
}
void test02()
{
    Widget w;
    func(w);
}
int main()
{
    test02();
    return EXIT_SUCCESS;
}
