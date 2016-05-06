#Ignatius and the Princess III
TimeLimit: 2000/1000 MS (Java/Others)  MemoryLimit: 65536/32768 K (Java/Others)
64-bit integer IO format:%I64d
Problem Description
"Well, it seems the first problem is too easy. I will let you know how foolish you are later." feng5166 says. 

"The second problem is, given an positive integer N, we define an equation like this: 
  N=a[1]+a[2]+a[3]+...+a[m]; 
  a[i]>0,1<=m<=N; 
My question is how many different equations you can find for a given N. 
For example, assume N is 4, we can find: 
  4 = 4; 
  4 = 3 + 1; 
  4 = 2 + 2; 
  4 = 2 + 1 + 1; 
  4 = 1 + 1 + 1 + 1; 
so the result is 5 when N is 4. Note that "4 = 3 + 1" and "4 = 1 + 3" is the same in this problem. Now, you do it!" 
Input
The input contains several test cases. Each test case contains a positive integer N(1<=N<=120) which is mentioned above. The input is terminated by the end of file. 
Output
For each test case, you have to output a line contains an integer P which indicate the different equations you have found. 
SampleInput
4
10
20
SampleOutput
5
42
627

----
问你一个数n， 可以由区间内 [ 1 : n ] 的数组合相加等于 n 的 个数是多少。
做法：
  - [ ] dp 数组全 赋值为 0
  - [ ] 将 dp[0] = 1
  - [ ] 然后 按照 完全背包做法做
  
----

```` c++
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int main(void){
    const int _all = 120;
    ll _m[ _all+2 ];
    memset( _m, 0, sizeof( _m ) );

    _m[0] = 1;
    for( int i=1; i <= _all; ++ i ){
        for( int j=i; j <= _all; ++ j ){
            _m[j] += _m[j-i];
        }
    }

    //freopen( "d://test.txt", "rw+", stdin );
    int n;
    while( scanf( "%d", &n ) != EOF ){
        printf( "%I64d\n", _m[n] );
    }

    return 0;
}
````
