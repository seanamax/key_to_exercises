#Happy Matt Friends ——北京H
----
TimeLimit: 6000/6000 MS (Java/Others)  MemoryLimit: 510000/510000 K (Java/Others)
64-bit integer IO format:%I64d
Problem Description
Matt has N friends. They are playing a game together. 

Each of Matt’s friends has a magic number. In the game, Matt selects some (could be zero) of his friends. If the xor (exclusive-or) sum of the selected friends’magic numbers is no less than M , Matt wins. 

Matt wants to know the number of ways to win.
Input
The first line contains only one integer T , which indicates the number of test cases. 

For each test case, the first line contains two integers N, M (1 ≤ N ≤ 40, 0 ≤ M ≤ 10 6). 

In the second line, there are N integers ki (0 ≤ k i ≤ 10 6), indicating the i-th friend’s magic number.
Output
For each test case, output a single line “Case #x: y”, where x is the case number (starting from 1) and y indicates the number of ways where Matt can win.
SampleInput
2
3 2
1 2 3
3 3
1 2 3
SampleOutput
Case #1: 4
Case #2: 2

 
Hint
In the ﬁrst sample, Matt can win by selecting: friend with number 1 and friend with number 2. The xor sum is 3. friend with number 1 and friend with number 3. The xor sum is 2. friend with number 2. The xor sum is 2. friend with number 3. The xor sum is 3. Hence, the answer is 4.

----
给定一个区间 [ 0 : n ]
求区间内的数与另外一个指定的数进行异或， 大于 另外一个数 的总共 几种， 很显然， 对于 异或一个数， 之前产生这个数的结果加到
异或结果的数的结果上， 但由于可能发生重叠， 另开数组保留结果， 最后再整合.

----

```` c++
// 完全背包 的暴力做法。 需要注意的是， 10^6的 满二进制数 为1048575， 所以我取 1048580， 这是个坑。
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int all = 1048580;
int main(void){
    int _n[ 45 ];
    ll *_m = new ll [ all ];
    ll *_m1 = new ll [ all ];
    int n, m;
    ll ans;
    int t;
    //freopen( "d://test.txt", "rw+", stdin );
    scanf( "%d", &t );
    for( int l=1; l <= t; ++ l ){
        scanf( "%d%d", &n, &m );
        for( int i=0; i < n; ++ i ){
            scanf( "%d", _n+i );
        }

        memset( _m, 0, all*sizeof( ll ) );
        _m[0] = 1;
        ans = 0;

        for( int i=0; i < n; ++ i ){
            memset( _m1, 0, all*sizeof( ll ) );
            for( int j=0; j < all; ++ j ){
                if( _m[j] ){
                    _m1[ _n[i]^j ] += _m[ j ];
                }
            }

            for( int j=0; j < all; ++ j ){
                 _m[j] += _m1[j];
            }
        }

        for( int i=m; i < all; ++ i ){
            ans += _m[i];
        }

        printf( "Case #%d: %I64d\n", l, ans );
    }

    delete [] _m;
    delete [] _m1;

    return 0;
}
````

