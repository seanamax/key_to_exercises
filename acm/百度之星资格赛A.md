# Problem A  
##### Accepts: 1829   Submissions: 12436
##### Time Limit: 2000/1000 MS (Java/Others)   Memory Limit: 65536/65536 K (Java/Others)
##### Problem Description
###### 度熊手上有一本字典存储了大量的单词，有一次，他把所有单词组成了一个很长很长的字符串。现在麻烦来了，他忘记了原来的字符串都是什么，神奇的是他竟然记得原来那些字符串的哈希值。一个字符串的哈希值，由以下公式计算得到：

###### H(s)=\prod_{i=1}^{i\leq len(s)}(S_{i}-28)\ (mod\ 9973)H(s)=∏
###### ​i=1
###### ​i≤len(s)
###### ​​ (S
###### ​i
###### ​​ −28) (mod 9973)

###### S_{i}S
###### ​i
###### ​​ 代表 S[i] 字符的 ASCII 码。

###### 请帮助度熊计算大字符串中任意一段的哈希值是多少。

##### Input
###### 多组测试数据，每组测试数据第一行是一个正整数NN，代表询问的次数，第二行一个字符串，代表题目中的大字符串，接下来NN行，每行包含两个正整数aa和bb，代表询问的起始位置以及终止位置。

##### 1\leq N\leq 1,0001≤N≤1,000

##### 1\leq len(string)\leq 100,0001≤len(string)≤100,000

##### 1\leq a,b\leq len(string)1≤a,b≤len(string)

##### Output
###### 对于每一个询问，输出一个整数值，代表大字符串从 aa 位到 bb 位的子串的哈希值。

##### Sample Input
###### 2
###### ACMlove2015
###### 1 11
###### 8 10
###### 1
###### testMessage
###### 1 1
##### Sample Output
###### Copy
###### 6891
###### 9240
###### 88

----
##### // 老思路， 先进行离线处理打表再说， 毕竟看测试数据就知道有压力测试。
##### // 离线处理后， 由于保留的是余数，所以， 需要数论知识， 利用表里的信息， 快速计算出区间的计算结果。
##### // 这里， 我是用了最原始版本， 直接根据 原有的式子去推算出结果来。
----

`` code `` `` c++ ``
```` c++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int all = 100010;
const int mod = 9973;
char str[ all ];
int ans[ all ];
int main(void)
{
    //freopen( "e://test.txt", "rw+", stdin );
    int n, l, r, len;
    while( scanf( "%d%s", &n, str+1 ) != EOF ){
        ans[0] = 1;
        len = strlen( str+1 );
        for( int i=1; i <= len; ++ i ){
            ans[i] = ( ans[i-1]*( str[i] - 28 ) )%mod;

        }

        while( n -- ){
            scanf( "%d%d", &l, &r );
            int k;
            for( k=0; 1; ++ k ){
                int tmp = k*mod + ans[r];
                if( tmp%ans[l-1] ==0 ){
                    printf( "%d\n", ( tmp/ans[l-1] )%mod );
                    break;
                }
            }
        }
    }
    return 0;
}
````
