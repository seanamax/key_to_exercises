# QAQ和木棍
#### TimeLimit:1000MS  MemoryLimit:128MB
#### 64-bit integer IO format:%I64d
#### Problem Description
##### QAQ有n个木棍，老板要求他把这n根木棍重新组成两根新木根L1和L2,每根新木棍的长度为组成他木棍长度的总和(每根木棍只能用一次)。然后，你需要重新购买一个新的木棍L3，能买到的木棍也只能是正整数,能够通过L1,L2,L3三根木棍组成一个三角形,要求这根购买的木棍的长度最短、
#
#### Input
##### 有多组测试案例
#
##### 第一行输入n（2<=n<100),表示有n个木棍。
#
##### 第二行输入n个正整数a1~an（1<ai<100），表示这N根木棍的长度。
#
#### Output
##### 对于每组测试案例,输出需要购买木棍的最小长度。
#
#### SampleInput
##### 2
##### 1 2
##### 5
##### 1 2 3 4 5
#
#### SampleOutput
##### 2
##### 2

----
// 此题策略就是尽可能的找 两段相同长度的木棍。 因为根据 三角形组成 条件， 即是任意三边关系为 a + b > c。 所以， 假设两边为 a， c。那么， a 和 c尽可能的相等。 所需要的 b值 就为最小值。 观察到这里的数据范围是 [ 100 : 100000 ] 而已， 所以不大， 直接 01背包 开干。 其实，就算 数据大， 那也没办法， 只能干， 此题之所以 dfs 能过， 就是 数据恰好没卡到。

----

`` code ``  `` c++ ``
```` c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int all = 105;
int _m[ all ];
int _n[ 10010 ];
int main(void)
{
    int n, ans = 0;
    while( scanf( "%d", &n ) != EOF ){
        ans = 0;
        for( int i=0; i < n; ++ i ){
            scanf( "%d", _m+i );
            ans += _m[i];
        }


        for( int i=0; i < n; ++ i ){
            for( int j=ans/2; j >= _m[i]; -- j ){
                _n[j] = max( _n[j], _n[ j-_m[i] ] + _m[i] );
            }
        }

        printf( "%d\n", abs( 2*_n[ans/2] - ans ) + 1 );
        memset( _n, 0, sizeof( _n ) );
    }
}
````
