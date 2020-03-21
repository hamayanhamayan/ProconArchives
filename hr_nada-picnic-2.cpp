//https://www.hackerrank.com/contests/75th/challenges/nada-picnic-2
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
string ans[3] = { "1491", "12095", "841341" };
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    cout << ans[N - 1] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
手で計算してみたが、全然わからん。
ズルをすると、以下のサイトが見つかる。
[Cryptarithmetic Puzzle Solver](http://bach.istc.kobe-u.ac.jp/llp/crypt-jp.html)
これで答えた。
///////////////////////// writeup2 end */
//　