#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef struct _node node;
struct _node
{
    char x;
    char y;
    char w;
    friend bool operator < ( node x, node y ){
        return x.w < y.w;
    }
};

const int limitLen = 52;
char un[ limitLen ];

void solve( int m, int n );
char union_find( char x );

int main(void)
{
    //freopen( "/home/seana/test.txt", "rw+", stdin );
    int n, m;
    while( scanf( "%d", &n ) != EOF && n ){
        scanf( "%d", &m );
        solve( n, m );
    }
    return 0;
}

char union_find( char x )
{
    if( x != un[x] ){
        return un[x] = union_find( un[x] );
    }
    return x;
}

void solve( int m, int n )
{
    int ans, edge;
    node *p = new node [ n ];

    for( int i=1; i <= m; ++ i ){
        un[i] = i;
    }

    for( int i=0; i < n; ++ i ){
        scanf( "%d%d%d", &p[i].x, &p[i].y, &p[i].w );
    }

    sort( p, p+n );

    ans = edge = 0;
    for( int i=0; i < n; ++ i ){
        p[i].x = union_find( p[i].x );
        p[i].y = union_find( p[i].y );
        if( p[i].x != p[i].y ){
            un[ p[i].x ] = un[ p[i].y ];
            ans += p[i].w;
        }
        if( edge+1 >= m ){
            break;
        }
    }

    delete [] p;
    printf( "%d\n", ans );
}
