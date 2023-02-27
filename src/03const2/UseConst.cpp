/*  
 *  Description : 尽可能使用const
 *  Created by 旋风冲锋龙卷风 on 2023/02/01 17:04
 *  个人博客 : http://letsgofun.cn/
 */
//

#include <pthread.h>
#include <iostream>

using namespace std;

void test01()
{
    static int a = 2;

}

class A
{

public:
    void func()
    {
    }
};

const A operator*(const A& lhs, const A& rhs)
{
    return lhs;
}

class TextBlock
{
public:

    TextBlock(const string &text) : text(text)
    {}


    char& operator[](size_t pos)
    {
        // return const_cast<char&>(static_cast<const TextBlock&>(*this)[pos]);
        return const_cast<char&> (static_cast<const TextBlock *const>(this)->operator[](pos));
    }

    const char& operator[](size_t pos) const
    {
        //边界判断
        //其他代码等
        //...
        return text[pos];
    }
    string text;
};

void test02()
{
    TextBlock tb("hello");
    cout << tb[0] << endl; //调用普通版本的[]
    tb[0] = 'r'; //可以写


    const TextBlock ctb("hello");
    cout << ctb[0] << endl; //调用const版本的[]
    // ctb[0] = 'x'; //错误!, 不能写
}

void test03()
{
    const int a = 1;
}

void test04()
{
    const TextBlock tb("hello");
    // int a = tb.textLength;
    const int b = 43;
}

class CTextBlock
{
public:
    //没有改变成员变量的值, const函数返回了非const的引用
    //注意这里只有C字符串能这样操作, string是不可以值,只能返回const引用
    int& operator[](std::size_t position)const {
        return pText[position];
    }
private:
    int *pText;
public:
    CTextBlock(int *pText) : pText(pText)
    {}
};

void test05()
{
    int a[] = {1, 2, 3};
    const CTextBlock ctb(a);
    int *pc = &ctb[0];//调用[]取得一个普通指针
    *pc = 12; //修改const对象的内容
}

int main()
{
     test02();
    return EXIT_SUCCESS;
}