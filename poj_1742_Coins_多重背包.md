# Coins
Time Limit: 3000MS		Memory Limit: 30000K
Total Submissions: 33587		Accepted: 11402
Description

People in Silverland use coins.They have coins of value A1,A2,A3...An Silverland dollar.One day Tony opened his money-box and found there were some coins.He decided to buy a very nice watch in a nearby shop. He wanted to pay the exact price(without change) and he known the price would not more than m.But he didn't know the exact price of the watch. 
You are to write a program which reads n,m,A1,A2,A3...An and C1,C2,C3...Cn corresponding to the number of Tony's coins of value A1,A2,A3...An then calculate how many prices(form 1 to m) Tony can pay use these coins. 
Input

The input contains several test cases. The first line of each test case contains two integers n(1<=n<=100),m(m<=100000).The second line contains 2n integers, denoting A1,A2,A3...An,C1,C2,C3...Cn (1<=Ai<=100000,1<=Ci<=1000). The last test case is followed by two zeros.
Output

For each test case output the answer on a single line.
## Sample Input

### 3 10
### 1 2 4 2 1 1
### 2 5
### 1 4 2 1
### 0 0
## Sample Output

### 8
### 4

---- 
这题 就是 多重背包， 注意的是， 同样的价值， 只算一次（看样例得出）。所以， 即使有 重叠也没关系。 用 01背包 做， 肯定超时。
用 二进制改进的 多重背包， 也超时。 注意前面说说的， 即使重叠也没关系， 所以 可以 开个数组 记录 个数。 在上限下 操作即可。

----

```` c++
// 比 拆分 二进制数 更好的 剪枝， 起码那个 超时了， 或是我 剪枝 姿势不对
// 时间 复杂度 是 n*m， 而 拆分 二进制的 dp 的复杂度是 O( n*m*( log[ v[0] : v[n] ]  )

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int all = 100005;
const int _all = 105;
int sum[ all ];
bool dp[ all ];
int v[ all ], c[ all ];
int main(void)
{
    //freopen( "d://test.txt", "rw+", stdin );
    int n, m;
    while( scanf( "%d%d", &n, &m ) != EOF && m+n ){
        for( int i=0; i < n; ++ i ){
            scanf( "%d", v+i );
        }
        for( int i=0; i < n; ++ i ){
            scanf( "%d", c+i );
        }

        int ans=0;
        memset( dp, 0, (m+1)*sizeof( bool ) );
        dp[0] = true;
        for( int i=0; i < n; ++ i ){
            memset( sum, 0, (m+1)*sizeof( int ) );

            for( int j=v[i]; j <= m; ++ j ){
                int tmp = j - v[i];
                if( !dp[j] && dp[ tmp ] && sum[ tmp ] < c[i] ){
                    ++ ans;
                    dp[ j ] = true;
                    sum[ j ] = sum[ tmp ] + 1;
                    //printf( "%d ", j );
                }

            }
        }//putchar( '\n' );

        printf( "%d\n", ans );
    }
    return 0;
}

````
