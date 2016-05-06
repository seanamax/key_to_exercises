# Piggy-Bank
TimeLimit: 2000/1000 MS (Java/Others)  MemoryLimit: 65536/32768 K (Java/Others)
64-bit integer IO format:%I64d
Problem Description
Before ACM can do anything, a budget must be prepared and the necessary financial support obtained. The main income for this action comes from Irreversibly Bound Money (IBM). The idea behind is simple. Whenever some ACM member has any small money, he takes all the coins and throws them into a piggy-bank. You know that this process is irreversible, the coins cannot be removed without breaking the pig. After a sufficiently long time, there should be enough cash in the piggy-bank to pay everything that needs to be paid. 

But there is a big problem with piggy-banks. It is not possible to determine how much money is inside. So we might break the pig into pieces only to find out that there is not enough money. Clearly, we want to avoid this unpleasant situation. The only possibility is to weigh the piggy-bank and try to guess how many coins are inside. Assume that we are able to determine the weight of the pig exactly and that we know the weights of all coins of a given currency. Then there is some minimum amount of money in the piggy-bank that we can guarantee. Your task is to find out this worst case and determine the minimum amount of cash inside the piggy-bank. We need your help. No more prematurely broken pigs! 
Input
The input consists of T test cases. The number of them (T) is given on the first line of the input file. Each test case begins with a line containing two integers E and F. They indicate the weight of an empty pig and of the pig filled with coins. Both weights are given in grams. No pig will weigh more than 10 kg, that means 1 <= E <= F <= 10000. On the second line of each test case, there is an integer number N (1 <= N <= 500) that gives the number of various coins used in the given currency. Following this are exactly N lines, each specifying one coin type. These lines contain two integers each, Pand W (1 <= P <= 50000, 1 <= W <=10000). P is the value of the coin in monetary units, W is it's weight in grams. 
Output
Print exactly one line of output for each test case. The line must contain the sentence "The minimum amount of money in the piggy-bank is X." where X is the minimum amount of money that can be achieved using coins with the given total weight. If the weight cannot be reached exactly, print a line "This is impossible.". 
SampleInput
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
SampleOutput
The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.

// 存储罐的质量， 求最小金币钱， 典型的01背包
```c++
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
void solve( int n, int m );
int main(void)
{
    //freopen( "d://test.txt", "rw+", stdin );
    int t, n, m;
    while( scanf( "%d", &t ) != EOF ){
        while( t -- ){
            scanf( "%d%d", &n, &m );
            solve( n, m );
        }
    }
    return 0;
}

void solve( int n, int m )
{
    m -= n;
    int t;
    scanf( "%d", &t );
    int dp[m+5];
    int bag[t+5][2];
    int _max = 0xf;
    int tmp;

    memset( &tmp, _max, sizeof( tmp ) );
    memset( dp, _max, sizeof( dp ) );
    for( int i=1; i <= t; ++ i ){
        scanf( "%d%d", &bag[i][0], &bag[i][1] );
        if( bag[i][1] <= m ){
            dp[ bag[i][1] ] = min( dp[ bag[i][1] ], bag[i][0] );
        }
    }

    for( int i=1; i <= t; ++ i ){
        for( int j=0; j <= m; ++ j ){
            if( j >= bag[i][1] ){
                dp[ j ] = min( dp[j], dp[j-bag[i][1]] + bag[i][0] );
            }
        }
    }

    if( dp[m] == tmp ){
        puts( "This is impossible." );
    }
    else{
        printf( "The minimum amount of money in the piggy-bank is %d.\n", dp[m] );
    }
}
```
