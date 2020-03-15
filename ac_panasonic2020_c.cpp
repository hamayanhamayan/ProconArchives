//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c
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
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













using ld = long double;
ld a, b, c;
const ld EPS = 1e-14;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> a >> b >> c;

	if (sqrtl(a) + sqrtl(b) < sqrtl(c) - EPS) cout << "Yes" << endl;
	else cout << "No" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
sqrt(a) + sqrt(b) < sqrt(c)を普通に比較することでも通すことができる。
B問題でWAをもらってこの解法に警戒したが、念のためlong doubleにしてEPSをつけて祈ったら通った。
その場合は、以下のことを行う。

- long doubleを使う
- EPSを適切に設定して比較に使う（誤差対策でA < BはA < B - EPSとするテンプレがある）

より安全な解法として、全部整数にして比較する解法がある。
こちらの解説は、[公式解説](https://img.atcoder.jp/panasonic2020/editorial.pdf)に任せることにする。
（そんなに難しくない。高校1年くらいの数学知識があれば大丈夫）
///////////////////////// writeup2 end */
