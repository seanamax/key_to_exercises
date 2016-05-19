# Feel Good
### TimeLimit:3000MS  MemoryLimit:65536K
### 64-bit integer IO format:%lld
### Special Judge
## Problem Description
 Bill is developing a new mathematical theory for human emotions. His recent investigations are dedicated to studying how good or bad days influent people's memories about some period of life. 

A new idea Bill has recently developed assigns a non-negative integer value to each day of human life. 

Bill calls this value the emotional value of the day. The greater the emotional value is, the better the daywas. Bill suggests that the value of some period of human life is proportional to the sum of the emotional values of the days in the given period, multiplied by the smallest emotional value of the day in it. This schema reflects that good on average period can be greatly spoiled by one very bad day. 

Now Bill is planning to investigate his own life and find the period of his life that had the greatest value. Help him to do so.
## Input
### The first line of the input contains n - the number of days of Bill's life he is planning to investigate(1 <= n <= 100 000). The rest of the file contains n integer numbers a1, a2, ... an ranging from 0 to 10 6 - the emotional values of the days. Numbers are separated by spaces and/or line breaks.
## Output
### Print the greatest value of some period of Bill's life in the first line. And on the second line print two numbers l and r such that the period from l-th to r-th day of Bill's life(inclusive) has the greatest possible value. If there are multiple periods with the greatest possible value,then print any one of them.
## SampleInput
### 6
### 3 1 6 4 5 2
## SampleOutput
### 60
### 3 5

----
#### 此题贴的标签是单调栈， 可是我从这个角度切不进去， 就用了线段树去搞RMQ。 
#### 题意， 求一段区间和， 与这个区间内最小值的乘积， 乘积为最大。
#### 于是， 很容易就想到了， 如果这点是最小值， 那么这段区间可以被这个最小值分割成 两个子区间（都不包含该点， 否则区间和与最小值乘积就无法出现最大值），
#### 所以， 用线段树做RMQ， 返回 查询区间的最小值的数组下标， 分隔成两个 子区间， 继续分治下去即可。
#### 在此之前， 先离线处理 区间和， 即是先累加。
----

`` code ``  ``c++``
```` c++
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair < int, int > P;
typedef long long ll;
const int all = 400010;
const int _all = 100010;
const int _max = 0xfffffff;
P _m[ all ];
ll _n[ _all ];
int ansl, ansr;
ll ans;

P build( int store, int l, int r );
P query( int ql, int qr, int _l, int _r, int store );
void unitTest();
void solve( int n );
void divide( int l, int r, int _1, int _r );

int main(void)
{
//    freopen( "e://test.txt", "rw+", stdin );
//    unitTest();
    int n;
    while( scanf( "%d", &n ) != EOF ){
        solve( n );
    }
    return 0;
}

// 建线段树
P build( int store, int l, int r )
{
    if( l == r ){
        _m[store].first = (int)_n[l];
        _m[store].second = l;
        return _m[store];

    }

    int mid = (l+r)>>1;
    P tmp = build( (store<<1)+1, l, mid );
    _m[store] = build( (store<<1)+2, mid+1, r );
    _m[store] = ( _m[store].first < tmp.first ? _m[store] : tmp );
    return _m[store];
}

// 线段树， 区间查询最小值， 返回一个包含最小值下标结构体
P query( int ql, int qr, int _l, int _r, int store )
{
    P tmp;
    tmp.first = _max;
    if( ql > _r || _l > qr ){
        return tmp;
    }

    if( ql <= _l && _r <= qr ){
        return _m[store];
    }

    int mid = ( _l + _r )>>1;
    tmp = query( ql, qr, _l, mid, (store<<1)+1 );
    P tmp2 = query( ql, qr, mid+1, _r, (store<<1)+2 );
    return tmp.first < tmp2.first ? tmp : tmp2;
}

// 测试各个部分函数是否正常
void unitTest()
{
    cout << _max << endl;
    freopen( "e://test.txt", "rw+", stdin );
    int n;
    while( scanf( "%d", &n ) != EOF ){
        for( int i=1; i <= n; ++ i ){
            scanf( "%I64d", _n+i );
        }

        build( 0, 1, n );
        for( int i=1; i <= n; ++ i ){
            printf( "%d %d\n", query( i, i, 1, n, 0 ).first, query( i, i, 1, n, 0 ).second );
        }putchar( '\n' );

    }
}

void solve( int n )
{
    for( int i=1; i <= n; ++ i ){
        scanf( "%I64d", _n+i );
    }

    // 离线处理， 区间求和， 用_n[n] - _n[m], 即可得到 [ m : n ] 区间的和
    _n[0] = 0;
    build( 0, 1, n );
    for( int i=1; i <= n; ++ i ){
        _n[i] += _n[i-1];
    }

    ans = 0;
    ansl = ansr = 1;
    divide( 1, n, 1, n );

    printf( "%I64d\n%d %d\n", ans, ansl, ansr );
}

void divide( int l, int r, int _l, int _r )
{
    if( l <= r ){
        // 查询最小值， sum 得出此段区间的结果
        P tmp = query( l, r, _l, _r, 0 );
        ll sum = _n[r] - _n[l-1];
        sum *= tmp.first;

        // 更新 答案
        if( sum > ans ){
            ans = sum;
            ansl = l;
            ansr = r;
        }

        // 分割成两个子区间， 分治下去
        divide( l, tmp.second-1, _l, _r );
        divide( tmp.second+1, r, _l, _r );
    }
}
````
