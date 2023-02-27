/*  
 *  Description : 
 *  Created by 旋风冲锋龙卷风 on 2023/01/31 22:17
 *  个人博客 : http://letsgofun.cn/
 */
//

#include <iostream>

using namespace std;

class A
{

};
class GamePlayer
{
public:
    static const int NumTurns; //声明,定义和初始化在类外
    static const int C = 3; //声明,且没有定义,初始化再类内
    static const double d_A;
    constexpr static const double d_B = 3.13; //如果是非整数型, 类内初始化需要constexpr关键字

    static int B;
};
int GamePlayer::B = 1;
const int GamePlayer::NumTurns = 3; //定义

void test01()
{
    // const int* p = &(GamePlayer().NumTurns);
    // cout << *p << endl;
    cout << GamePlayer::NumTurns << endl;
    GamePlayer g;
}

class C
{
public:
    enum {NumTurns = 4};
    int c[NumTurns];
};

#define CALL_WITH_MAX(a, b) (a) > (b) ? (a) : (b)
void test02()
{
    int a = C::NumTurns;
    int b = 3;
    int c = CALL_WITH_MAX(a, b);
}

void test03()
{
    int a = 3;
    const int& rb = a;
    int &rc = rb;

}
int main()
{
    test01();
    return EXIT_SUCCESS;
}
