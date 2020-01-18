//https://yukicoder.me/problems/no/972
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
template<typename Func>
int findMax(int L, int R, Func f) { //[L, R)
	int lo = L, hi = R;
	while (lo + 1 != hi) {
		int mi = (lo + hi) / 2;
		if (f(mi) - f(mi - 1) > 0) lo = mi;
		else hi = mi;
	}
	return lo;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[201010];
//---------------------------------------------------------------------------------------------------
ll B[201010];
// [l,r]
ll get(int l, int r) {
	ll res = B[r];
	if (l) res -= B[l - 1];
	return res;
}
//---------------------------------------------------------------------------------------------------
int cent;
ll f(int s) {
	if (s == 0) return 0;
	ll res = get(cent - s, cent - 1) + get(N - s, N - 1) - 1LL * A[cent] * s * 2;
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N);

	B[0] = A[0];
	rep(i, 1, N) B[i] = B[i - 1] + A[i];

	ll ans = 0;
	rep(i, 0, N) {
		cent = i;

		int ma = min(i, N - i - 1);

		int s = findMax(0, ma + 1, f);
		chmax(ans, f(s));
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難しい問題でした。

まず、kは奇数個のみ考えればいい。
kが偶数個の場合は中央値の計算に使われる2つのうち、大きい方を削除してもSの値が変わらないためである。
これで中央値はある要素になることが確定したので、
中央値を全探索対象とする。

A[i]を中央値としたとき、残る変数はkである。
kは奇数であるとわかっているので、k=2s+1としておこう。
すると、残りの選択肢は、A[i]未満の数をs個、A[i]より大きい数をs個選択できる。
これで最適な選択はなんだろうか。
A[i]未満の数-A[i]は必ず負になるが、これは最小化したい。よって、A[i]未満の数は大きい方からs個取ればいい。
A[i]より大きい数-A[i]は必ず正になるが、これは最大化したい。よって、A[i]より大きい数は大きい方からs個取ればいい。

sを変数とすると、
(A[i]未満の数の大きい方からs個の総和) + (A[i]より大きい数の大きい方からs個の総和) + A[i] - A[i] (2s + 1)
より、
(A[i]未満の数の大きい方からs個の総和) + (A[i]より大きい数の大きい方からs個の総和) + - A[i] 2s
となる。
これに立ち向かうが、解説では、差分を取ると単調減少することが紹介されている。
なるほどという感じである。差分が単調減少するということは上に凸になるので、自分は三分探索した。

考察時にはA[i]の値が全て異なるっぽく考えてるが、実際には同じ値のものもある。
これを解消するには、A[i]をソートしておき、A[i]<A[j]と考えていたところを、i<jであればA[i]<A[j]と解釈すれば
上手く扱うことができる。これは競プロにおいて、一般的なテクである。
///////////////////////// writeup2 end */
