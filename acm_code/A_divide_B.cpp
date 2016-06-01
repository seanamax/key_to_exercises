#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 9973;
int main(void)
{
    LL a, b;
    int t;
    scanf( "%d", &t );
    while( t -- ){
        scanf( "%I64d%I64d", &a, &b );

        for( LL i=1; i < mod; ++ i ){
            if( (i*b)%mod == a ){
                printf( "%I64d\n", i );
                break;
            }
        }
    }
    return 0;
}
