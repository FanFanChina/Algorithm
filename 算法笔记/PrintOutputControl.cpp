#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a = 1;
    int l = 3;
    printf("%02d\n", a);
    printf("%0*d\n", l, a); // * : n | d : a
    printf("%-03d***", a);  // flags 无效等价于 -3
    return 0;
}

// printf(输出格式%[flags][宽度][.perc][F|N|h|I]类型)