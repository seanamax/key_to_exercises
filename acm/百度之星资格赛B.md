# Problem B  
##### Accepts: 2515   Submissions: 9216
##### Time Limit: 2000/1000 MS (Java/Others)   Memory Limit: 65536/65536 K (Java/Others)
##### Problem Description
###### 度熊面前有一个全是由1构成的字符串，被称为全1序列。你可以合并任意相邻的两个1，从而形成一个新的序列。对于给定的一个全1序列，请计算根据以上方法，可以构成多少种不同的序列。

##### Input
###### 这里包括多组测试数据，每组测试数据包含一个正整数NN，代表全1序列的长度。

##### 1\leq N \leq 2001≤N≤200

##### Output
###### 对于每组测试数据，输出一个整数，代表由题目中所给定的全1序列所能形成的新序列的数量。

##### Sample Input
###### 1
###### 3
###### 5
##### Sample Output
###### 1
###### 3
###### 8

##### Hint

###### 如果序列是：(111)。可以构造出如下三个新序列：(111), (21), (12)。

----
##### // 其实该题就是一个 fibo 数列而已， 通过举例 的时候， 会发现 1， 2， 3， 5， 8， ... ,
##### // 由于 该题是需要 到200 位的 fibo， 所以现有的 数据类型都会爆， 没办法。 我又不会 java， 自己写个 大数 加法运算吧
##### // 被坑了好几次， 自己写的 大数运算没问题， 只能说有毒了。（ 现在的代码是过的 ）， fibo数列初始化时，只能初始化fibo[1],fibo[2].
##### // 初始化 fibo[0], fibo[1], 就 一直 wa。 真是神奇。。。
----

`` code ``  `` c ++ ``
```` c++
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int all = 210;
string fibo[ all ];

void ___strrev( char str[] );
string add( string x, string y );

int main(void)
{
    fibo[1] = "1";
    fibo[2] = "2";
    for( int i=3; i < all; ++ i ){
        fibo[i] = add( fibo[i-1], fibo[i-2] );
        //cout << fibo[i] << endl;
    }

    int n;
    while( scanf( "%d", &n ) != EOF ){
        cout << fibo[n] << endl;
    }

    return 0;
}

string add( string x, string y )
{
    string result;
    int strLen = max( x.size(), y.size() ) + 10;
    char strTmp[ strLen ];
    char *strX = new char [ strlen( x.c_str() ) +3 ];
    char *strY = new char [ strlen( y.c_str() ) +3 ];
    strcpy( strX, x.c_str() );
    strcpy( strY, y.c_str() );
    ___strrev( strX );
    ___strrev( strY );

    memset( strTmp, 0, strLen*sizeof( char ) );
    int store = 0;
    for( int i=0; strX[i] != '\0' && strY[i] != '\0'; ++ i ){
        strTmp[i] += strX[i] + strY[i] - '0';
    }

    for( int i=strlen( strTmp ); i < strlen( strX ); ++ i ){
        strTmp[i] += strX[i];
    }

    for( int i=strlen( strTmp ); i < strlen( strY ); ++ i ){
        strTmp[i] += strY[i];
    }

    int len = strlen( strTmp );
    for( int i=0; i < len; ++ i ){
        strTmp[i] -= '0';
        strTmp[i+1] += (strTmp[i])/10;
        strTmp[i] = ( strTmp[i] )%10 + '0';
    }

    if( strTmp[len] ){
        strTmp[len] += '0';
    }//cout << "test " << strTmp << endl;

    ___strrev( strTmp );
    result = strTmp;
    delete [] strX;
    delete [] strY;
    return result;
}

void ___strrev( char str[] )
{
    int len = strlen( str );
    for( int i=0, j=len-1; i != j && i != j+1; ++ i, -- j ){
        swap( str[i], str[j] );
    }
}
````
