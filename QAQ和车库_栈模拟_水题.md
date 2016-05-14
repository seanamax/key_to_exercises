# QAQ和车库
#### TimeLimit:5000MS  MemoryLimit:128MB
#### 64-bit integer IO format:%I64d
#### Problem Description
##### QAQ作为车库的管理人员，他管理的车库有以下三个特点：

1. 只有一个门;

2. 长度无限长;

3. 车库的宽度正好能单辆小车入库或者出库，既车库不能够并排多辆小车。

##### 每辆进入车库的小车都一样，只是小车的价值不一样。
##### 他老板每次询问QAQ，车库里面价值最高的小车的价值是多少，由于工作量比较大，QAQ需要你的帮忙。


#### Input
##### 有多组测试案例。
##### 第一行输入一个数K，表示有K次操作(1<=K<=1000000)。

##### 接下来有K行，每行输入有三种形式：

1. v 表示此时车库进入一两价值为v的小车(1<=v<1000 000 000)；

2. 表示此时车库有一辆小车出库；

3. 表示询问小明此时车库里面价值最大的小车的价值是多少,如果车库里面没有小车,则输出 -1.



#### Output
##### 对于每次询问，输出车库中价值最大的车，如果没有小车，则输出 -1.



#### SampleInput
##### 6
##### 1 3
##### 1 2
##### 1 4
##### 3
##### 2
##### 3

#### SampleOutput
##### 4
##### 3

----
// 看题意， 很显然就是栈的模拟， 只是他的问题就是需要查询 栈里的最大值。 此时就可以每次加入栈时， 与最后栈顶的元素比较， 更新即可。详细看代码。

----

`` code ``  ``c++``
```` c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
int main(void)
{
    int n, op, num;
    stack < int > _stack;
    while( scanf( "%d", &n ) != EOF ){
        while( n -- ){
            scanf( "%d", &op );
            if( op == 1 ){
                scanf( "%d", &num );
                
                // 加入栈顶时的具体操作， 只是需要跟之前的栈顶元素做比较更新数据
                _stack.push( max( num, _stack.size() ? _stack.top() : 0 ) );
            }
            else if( op == 2 ){
                if( _stack.size() ){
                    _stack.pop();
                }
            }
            else{
                if( _stack.size() ){
                    printf( "%d\n", _stack.top() );
                }
                else{
                    puts( "-1" );
                }
            }
        }
    }
    return 0;
}

````
