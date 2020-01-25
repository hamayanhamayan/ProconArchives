//https://atcoder.jp/contests/abc152/tasks/abc152_d
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














int N;
ll cnt[10][10];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;

	rep(i, 1, N + 1) {
		int btm = i % 10;

		int top = -1, x = i;
		while (0 < x) {
			top = x % 10;
			x /= 10;
		}

		cnt[top][btm]++;
	}

	ll ans = 0;
	rep(Atop, 0, 10) rep(Abtm, 0, 10) ans += cnt[Atop][Abtm] * cnt[Abtm][Atop];
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、全列挙を考えると難しそう。
片方のAを固定すると、もう片方のBの先頭数と末尾数は決定する。
これで2桁減るので、全体10^8通りくらい考えることになる。
ちょっと怪しい。
では、決定する、Aの先頭数と末尾数を固定にするとどうだろうか。
これでもBの先頭数と末尾数は決定する。
こっちの方針の方が全探索数が少ないので、良さそうか。

Aの先頭数をAtop, 末尾数をAbtmとすると、Bは先頭数がAbtm, 末尾数がAtopとなる。
この場合の(A,B)の組み合わせは、
(先頭がAtop, 末尾がAbtmである数の個数)×(先頭がAbtm, 末尾がAtopである数の個数)
となる。
よって、あとは、以下の配列が用意できれば答えられる。
cnt[top][btm] := 先頭がtopで、末尾がbtmである数の個数

これはtop,btm視点で数えるのではなく、1～Nを全探索して、先頭と末尾の数を抜き出して、
それを使って、cnt[top][btm]++していくのが簡単。
///////////////////////// writeup2 end */
