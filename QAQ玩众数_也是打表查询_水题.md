# QAQ玩众数
#### TimeLimit:1000MS  MemoryLimit:128MB
#### 64-bit integer IO format:%I64d
#### Problem Description
##### 给你一个N个数，让你找出这N个数中出现次数最多的数以及出现的次数、

##### 如果只有一个数值出现的次数最多，先输出Unimodal，再输出这个数值以及出现的次数、

##### 如果有两个数值出现的次数最多且一样多，先输出Bimodal，再按数值大小升序输出这两个数值以及次数

##### 如果有三个数值出现的次数最多且一样多，先输出Trimodal，再按数值大小升序输出这三个数值以及次数

##### 如果有超过三个数值出现的次数最多，则输出Multimodal即可。



#### Input
##### 有多组测试案例

##### 对于每组测试案例，第一行输入N(1<=N<=10000)，表示有N个数值。

##### 第二行输入N个数值ai(1<=ai<=1000)



#### Output
###### 对于每组测试案例，输出题目所要求的答案、

#### SampleInput
##### 2
##### 1 1
##### 4
##### 1 2 2 1
##### 6
##### 1 2 2 1 3 3
##### 4
##### 1 2 3 4

#### SampleOutput
##### Unimodal 1 2
##### Bimodal 1 2 2
##### Trimodal 1 2 3 2
##### Multimodal

----
// 重复话， 中文题， 也只是打表， 记录出现的最大值，然后再遍历一次， 符合出现最大值次数的， 加入队列（FIFO）， 输出队列即可。

----


`` code ``  `` c++ ``
````c++
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int all = 10010;
int _m[ all ];
int main(void)
{
    int n, m, _max;
    queue < int > que;
    while( scanf( "%d", &n ) != EOF ){
        memset( _m, 0, sizeof( _m ) );
        _max = 0;
        while( n -- ){
            scanf( "%d", &m );
            ++ _m[ m ];
            _max = max( _max, _m[m] );
        }

        for( int i=0; i < all; ++ i ){
            if( _max == _m[i] ){
                que.push( i );
            }
        }

        if( que.size() == 1 ){
            printf( "%s %d %d\n", "Unimodal", que.front(), _max );
        }
        else if( que.size() == 2 ){
            m = que.front();
            que.pop();
            printf( "%s %d %d %d\n", "Bimodal", m, que.front(), _max );
        }
        else if( que.size() == 3 ){
            m = que.front();
            que.pop();
            n = que.front();
            que.pop();
            printf( "%s %d %d %d %d\n", "Trimodal", m, n, que.front(), _max );
        }
        else{
            puts( "Multimodal" );
        }

        while( que.size() ){
            que.pop();
        }
    }
    return 0;
}
````

