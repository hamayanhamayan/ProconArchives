//https://atcoder.jp/contests/abc158/tasks/abc158_b
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














ll N, A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> A >> B;

	ll len = A + B;
	ll ans = (N / len) * A + min(A, N % len);

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
先頭からN個のボール列は、
AAAABBBBAAAABBBBAAAABBBBと青ボール赤ボールのグループが最初に続く、
そして、AAAで終わるか、AAAABBとAは置ききってBで終わるかという感じになる。

グループはA+B個分になる。len=A+Bとしておく。
すると、グループの個数はN/lenとなる。
このグループの個数×Aがグループで存在するボールの個数である。

残りはN%len個となるが、青いボールはそのうち先頭のA個であるため、min(N % len, A)が残りでの青ボールの個数。

これの和が答え。
///////////////////////// writeup2 end */
