# 5. Longest Palindromic Substring  
### My Submissions QuestionEditorial Solution
#### Total Accepted: 108487 Total Submissions: 468241 Difficulty: Medium
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

----
#### // 此题就是求 一段母串中， 最长回文串。
#### // 用马拉车做法做， 构造 马拉车的串， 记录并更新 最大长度及其下标， 用最大长度及其下标， 回构最长回文串， 返回即可
----

`` code ``  `` c++ ``
```` c++
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size()*2 + 2;
        char *_sus = new char [ len+100 ];
        int *next = new int [ len+100 ];

        for( int i=0; i < len; ++ i ){
            next[i] = 1;
        }

        // 构建 马拉车所指定的串， 例如 串 “aaaa”， 构造后为 “$#a#a#a#a#", $符号为防止匹配时内存溢出。
        _sus[0] = '$';
        for( int i=0, j=1; i <= s.size(); ++ i, j += 2 ){
            _sus[j] = '#';
            _sus[j+1] = s[i];
        }//print( _sus );

        int midr, mid, ans = 0, store = 0;
        midr = mid = 0;
        for( int i=1; i < len; ++ i ){
            if( i <= midr ){
                next[i] = min( next[i], next[ (mid<<1) - i ] );
            }
            while( _sus[i + next[i] ] == _sus[ i - next[i] ] ){
                ++ next[i];
            }

            if( next[i] + i >= midr ){
                midr = i + next[i];
                mid = i;
            }

            // 更新 最长长度及其下标
            if( ans < next[i] ){
                ans = next[i];
                store = i;
            }
        }

//      cout << ans << ' ' << store  << ' ' << _sus[ store ] << endl;
//      printnum( next, 10 );

        len = next[store] + store;
        for( int i=0, j = store-next[store]+1; j < len; ++ i, ++ j ){
            if( _sus[j] != '#' ){
                _sus[i] = _sus[j];
            }

            ++ j;
            if( _sus[j] != '#' ){
                _sus[i] = _sus[j];
            }
        }_sus[ next[ store ] - 1 ] = '\0';


        string _s = _sus;
        delete [] _sus;
        delete [] next;
        return _s;
    }
      
      // 调试内容， 不必理会
//    void print( char *_m ){
//        int len = strlen( _m );
//        for( int i=1; i < len; ++ i ){
//            putchar( _m[i] );
//            putchar( ' ' );
//        }putchar( '\n' );
//    }
//
//    void printnum( int *_next, int n ){
//        for( int i=1; i < n; ++ i ){
//            printf( "%d ", _next[i] );
//        }putchar( '\n' );
//    }
};

````
