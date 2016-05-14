# QAQ和题目
#### TimeLimit:1000MS  MemoryLimit:128MB
#### 64-bit integer IO format:%I64d
##### Problem Description
QAQ在oj上做题目,他通过某种途径得到他题目AC的列表,不过这列表内的题号可能有重复(因为他可能一题提交了很多次AC)

请问他一共通过了多少道题目、

#### Input
##### 有多组测试案例

##### 每组测试案例,第一行输入N(1<=N<=10000)、

##### 第二行输入N个整数Ai(1<=Ai<=10000)、

#### Output
##### 对于每组测试案例,输出有多少种的数字、

#### SampleInput
##### 3
##### 1 2 3
##### 3
##### 1 1 1
##### 4
##### 1 2 1 2
#### SampleOutput
##### 3
##### 1
##### 2

----
// 都是中文题， 只是打表查询而已。
----

`` code ``  `` c++ ``
```` c++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int all = 10010;
bool _m[ all ];
int main(void)
{
    int n, m, ans;
    while( scanf( "%d", &n ) != EOF ){
        memset( _m, 0, sizeof( _m ) );

        ans = 0;
        while( n -- ){
            scanf( "%d", &m );
            if( !_m[ m ] ){
                _m[ m ] = true;
                ++ ans;
            }
        }printf( "%d\n", ans );
    }
    return 0;
}
````
