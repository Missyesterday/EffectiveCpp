/*  
 *  Description : 二级指针
 *  Created by 旋风冲锋龙卷风 on 2023/02/02 20:07
 *  个人博客 : http://letsgofun.cn/
 */
//

#include <iostream>

using namespace std;

void func(int *val)
{
    *val = 20;
    val = (int*)1;
}

void test01()
{
    int* a = new int(10);
    func(a);
    cout << *a << endl;
}

int main()
{
    test01();
    return EXIT_SUCCESS;
}