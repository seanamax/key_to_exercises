# CRB and His Birthday
TimeLimit: 2000/1000 MS (Java/Others)  MemoryLimit: 65536/65536 K (Java/Others)
64-bit integer IO format:%I64d
Problem Description
Today is CRB's birthday. His mom decided to buy many presents for her lovely son. 
She went to the nearest shop with M Won(currency unit). 
At the shop, there are N kinds of presents. 
It costs Wi Won to buy one present of i-th kind. (So it costs k × Wi Won to buy k of them.) 
But as the counter of the shop is her friend, the counter will give Ai × x + Bi candies if she buys x(x>0) presents of i-th kind. 
She wants to receive maximum candies. Your task is to help her. 
1 ≤ T ≤ 20
1 ≤ M ≤ 2000
1 ≤ N ≤ 1000
0 ≤ Ai, Bi ≤ 2000
1 ≤ Wi ≤ 2000

Input
There are multiple test cases. The first line of input contains an integer T, indicating the number of test cases. For each test case: 
The first line contains two integers M and N. 
Then N lines follow, i-th line contains three space separated integers Wi , Ai and Bi. 
Output
For each test case, output the maximum candies she can gain.
SampleInput
1
100 2
10 2 1
20 1 1
SampleOutput
21
 
Hint
CRB's mom buys 10 presents of first kind, and receives 2 × 10 + 1 = 21 candies.
Submit

----
这题， 由于 第一次 价值 为 Ai + Bi, 有逻辑 上的 买 第一次， 才有 第 2， 3， ， ， n 次。 而且如果 连第一次也选不上， 就不用说以后的次数了。
所以依据这种情况， 可以 划分为 第一次 和 后面的 n次购买。 自然， 先用 01背包搞， 再用 完全背包 搞

----

```` c++

// 该题 就是 拆分用 01背包 和 完全背包 做。
// 只能说明 自己 还不会完全理解 背包， 或者说 基础 还打不好
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int all = 2010;
int dp[ all ], a[ all ], b[ all ], w[ all ];
int n, m, t;
int main(void)
{

    //freopen( "d://test.txt", "rw+", stdin );
    scanf( "%d", &t );

    while( t -- ){

        scanf( "%d%d", &n, &m );
        memset( dp, 0, (n+1)*sizeof( int ) );

        for( int i=1; i <= m; ++ i ){
            scanf( "%d%d%d", w+i, a+i, b+i );
            b[i] += a[i];
        }

        // 当成 01背包 做
        for( int i=1; i <= m; ++ i ){
            for( int j=n; j >= w[i]; -- j ){
                dp[j] = max( dp[j], dp[ j-w[i] ] + b[i] );
            }
        }

        //  当成 完全背包做
        for( int i=1; i <= m; ++ i ){
            for( int j=w[i]; j <= n; ++ j ){
                dp[j] = max( dp[j], dp[ j-w[i] ] + a[i] );
            }
        }

        printf( "%d\n", dp[n] );
    }
    return 0;
}

````
