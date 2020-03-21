//https://www.hackerrank.com/contests/oyamac/challenges/tiktak-1
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    
    int s = N % 60; N /= 60;
    int m = N % 60; N /= 60;
    int h = N;

    cout << h << endl;
    cout << m << endl;
    cout << s << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
順番に60のあまりを取って60で割るというのを繰り返して答えを求めていく方法でACした。

最初に60の余りをとると、秒が得られる。
これで60で切り捨てで割ると、秒が分に変換される。
次に60の余りをとると、分が得られる。
さらに60で切り捨てで割ると、分が時に変換される。
それで答える。

60進数への変換として考えてもいい。
///////////////////////// writeup2 end */
// 