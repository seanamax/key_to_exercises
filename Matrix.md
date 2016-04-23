
// segement tree && Binary Indexed Trees 
practice

------

# Matrix
TimeLimit:3000MS  MemoryLimit:65536K
64-bit integer IO format:%lld
Problem Description
Given an N*N matrix A, whose elements are either 0 or 1. A[i, j] means the number in the i-th row and j-th column. Initially we have A[i, j] = 0 (1 <= i, j <= N). 

We can change the matrix in the following way. Given a rectangle whose upper-left corner is (x1, y1) and lower-right corner is (x2, y2), we change all the elements in the rectangle by using "not" operation (if it is a '0' then change it into '1' otherwise change it into '0'). To maintain the information of the matrix, you are asked to write a program to receive and execute two kinds of instructions. 

1. C x1 y1 x2 y2 (1 <= x1 <= x2 <= n, 1 <= y1 <= y2 <= n) changes the matrix by using the rectangle whose upper-left corner is (x1, y1) and lower-right corner is (x2, y2). 
2. Q x y (1 <= x, y <= n) querys A[x, y]. 
Input
The first line of the input is an integer X (X <= 10) representing the number of test cases. The following X blocks each represents a test case. 

The first line of each block contains two numbers N and T (2 <= N <= 1000, 1 <= T <= 50000) representing the size of the matrix and the number of the instructions. The following T lines each represents an instruction having the format "Q x y" or "C x1 y1 x2 y2", which has been described above.
Output
For each querying output one line, which has an integer representing A[x, y]. 

There is a blank line between every two continuous test cases. 

------

SampleInput
1
2 10
C 2 1 2 2
Q 2 2
C 2 1 2 1
Q 1 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
Q 1 1
C 1 1 2 1
Q 2 1

------

SampleOutput
1
0
0
1

------

Obviously, this is a tmplate question just for matrix segment tree or binary indexed trees.

-----

### [ OJ link ](http://210.34.193.66:8080/vj/Problem.jsp?pid=2077) please enjoy!

#Use matrix segment tree code to AC :
``code`` `` C ++ ``

````

// just use one-dimensional segment tree to express the column of 
// matrix, and every node of line segment tree. that's the matrix 
// segment trees.
#include <cstdio>
#include <cstring>
using namespace std;
bool _m[4005][4005];
int _x1, _x2, _y1, _y2, ans;

// function prototype
void ud( int x1, int x2, int store_x, int y1, int y2, int store_y );
void sud( int store_x, int y1, int y2, int store_y );
void qu( int x1, int x2, int store_x, int y1, int y2, int store_y );
void squ( int store_x, int y1, int y2, int store_y );
void solve();

int main(void)
{
    //freopen( "d://test.txt", "rw+", stdin );
    int t;
    scanf( "%d", &t );
    while( t -- ){
        solve();
        putchar( '\n' );
    }
    return 0;
}

void solve()
{
    int n, m;
    memset( _m, 0, sizeof( _m ) );
    char str[] = "Hello_world";
    scanf( "%d%d", &n, &m );
    while( m -- ){
        scanf( "%s", str );
        if( str[0] == 'Q' ){
            ans = 0;
            scanf( "%d%d", &_x1, &_y1 );
            qu( 1, n, 1, 1, n, 1 );
            printf( "%d\n", ans&1 );
        }
        else{
            scanf( "%d%d%d%d", &_x1, &_y1, &_x2, &_y2 );
            ud( 1, n, 1, 1, n, 1 );
        }
    }
}

// uodate date for column of matrix segment tree
void ud( int x1, int x2, int store_x, int y1, int y2, int store_y )
{
    if( x1 > _x2 || _x1 > x2 ){
        return ;
    }
    if( _x1 <= x1 && x2 <= _x2 ){
        sud( store_x, y1, y2, store_y );
        return ;
    }

    int mid = ( x1+x2 )>>1;
    ud( x1, mid, store_x<<1, y1, y2, store_y );
    ud( mid+1, x2, (store_x<<1)+1, y1, y2, store_y );
}

// update date for line of matrix segment tree
void sud( int store_x, int y1, int y2, int store_y )
{
    if( y1 > _y2 || _y1 > y2 ){
        return ;
    }
    if( _y1 <= y1 && y2 <= _y2 ){
        _m[store_x][store_y] = _m[store_x][store_y] == false;
        return ;
    }

    int mid = ( y1+y2 )>>1;
    sud( store_x, y1, mid, store_y<<1 );
    sud( store_x, mid+1, y2, (store_y<<1)+1 );
}


// query column of matrix segment tree
void qu( int x1, int x2, int store_x, int y1, int y2, int store_y )
{
    if( _x1 < x1 || _x1 > x2 ){
        return ;
    }
    if( x1 == x2 ){
        if( x1 == _x1 ){
            squ( store_x, y1, y2, store_y );
        }
        return ;
    }

    if( x1 <= _x1 && _x1 <= x2 ){
        squ( store_x, y1, y2, store_y );
    }

    int mid = ( x1+x2 )>>1;
    qu( x1, mid, store_x<<1, y1, y2, store_y );
    qu( mid+1, x2, (store_x<<1)+1, y1, y2, store_y );
}

// query line of matrix segment tree
void squ( int store_x, int y1, int y2, int store_y )
{
    if( _y1 < y1 || _y1 > y2 ){
        return ;
    }

    if( y1 == y2 ){
        if( y1 == _y1 ){
            ans += _m[store_x][store_y];
        }
        return ;
    }

    if( y1 <= _y1 && _y1 <= y2 ){
        ans += _m[store_x][store_y];
    }

    int mid = ( y1+y2 )>>1;
    squ( store_x, y1, mid, store_y<<1 );
    squ( store_x, mid+1, y2, (store_y<<1)+1 );
}
```


### Besides, this question also can ACed by matrix binary indexed trees. By the way, use time 500+ ms can AC by matrix binary indexed trees AND use time 1000+ ms by matrix segment tree.
### And their time complex rate as same as O( n*logn ）.

# Use matrix indexed trees for AC.
` code ` ` c ++ `
```

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define low_bit( x )    \
        ( x & ( - x ) )

void solve( int n, int m );
void update( bool **_n, int n, int m, int t );
bool query( bool **_n, int n, int m );

int main(void)
{
    //freopen( "e://test.txt","rw+", stdin );
    int t, n, m;
    while( scanf( "%d", &t ) != EOF ){
        while( t -- ){
            scanf( "%d%d", &n,&m );
            solve( n, m );
            putchar( '\n' );
        }
    }
    return 0;
}

void solve( int n, int m )
{
    bool **_n = new bool *[ n+1 ];
    for( int i=0; i <= n; ++ i ){
        _n[i] = new bool [ n+1 ];
        memset( _n[i], 0, (n+1)*sizeof( bool ) );
    }

    char str[] = "Hello_world";
    while( m -- ){
        scanf( "%s", str );
        if( str[0] == 'Q' ){
            int x, y;
            scanf( "%d%d", &x, &y );
            printf( "%d\n", query( _n, x, y ) );
        }
        else{
            int x1, x2, y1, y2;
            scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
            update( _n, x1, y1, n );
            update( _n, x1, y2+1, n );
            update( _n, x2+1, y1, n );
            update( _n, x2+1, y2+1, n );
        }
    }

    for( int i=0; i <= n; ++ i ){
        delete [] _n[i];
    }
    delete [] _n;
}

// to update date for matrix binary indexed trees
void update( bool **_n, int n, int m, int t )
{
    for( int i=n; i <= t; i += low_bit( i )  ){
        for( int j=m; j <= t; j += low_bit( j ) ){
            _n[i][j] = _n[i][j] == false;
        }
    }
}

// to query answer for matrix binary indexed trees
bool query( bool **_n, int n, int m )
{
    int ans = 0;
    for( int i=n; i; i -= low_bit( i ) ){
        for( int j=m; j; j -= low_bit( j ) ){
            ans += _n[i][j];
        }
    }
    //cout << "test " << ans << endl;
    return ans&1;
}

```
