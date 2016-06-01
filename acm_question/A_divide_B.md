# A/B
----
#### TimeLimit:1000MS  MemoryLimit:32768KB
#### 64-bit integer IO format:%I64d
----
### Problem Description
#### 要求(A/B)%9973，但由于A很大，我们只给出n(n=A%9973)(我们给定的A必能被B整除，且gcd(B,9973) = 1)。
----
### Input
#### 数据的第一行是一个T，表示有T组数据。 
#### 每组数据有两个数n(0 <= n < 9973)和B(1 <= B <= 10^9)。
----
### Output
#### 对应每组数据输出(A/B)%9973。
----
### SampleInput
##### 2
##### 1000 53
##### 87 123456789
----
### SampleOutput
##### 7922
##### 6060

----
#### // we can solve this question by:
##### suspose valiable t = (A/B), we already know n = A%9973, so we can equal to turn A = B*t, and if ( B * (t%9973) )%9973 is equal to n, then find the t%9973.
----

----
[ code link ](  https://github.com/seanamax/key_to_exercises/acm_code/A_divide_B.cpp  )
----
