//https://atcoder.jp/contests/abc159/tasks/abc159_d
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














int N, A[201010];
ll cnt[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	ll all = 0;
	rep(i, 0, N) cnt[A[i]]++;
	rep(i, 1, N + 1) all += cnt[i] * (cnt[i] - 1) / 2;

	rep(i, 0, N) {
		ll ans = all;
		ans -= cnt[A[i]] * (cnt[A[i]] - 1) / 2;
		ans += (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2;
		printf("%lld\n", ans);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
今回のようなクエリ問題に対する対処はあまりパターンがない。

- 各クエリについて高速に計算
- 全部前計算してしまう
- 差分を計算することで高速に計算

今回は3番目の方針で解いていこう。

まず、減らさず全部の数で計算する方法を考えてみる。
すると、すべての数について、C(個数,2)、つまり、個数×(個数 - 1)/2の総和を取れば答えになる。
重要なこととして、これは各数について独立に計算ができる。

これを前提として、差分のみ計算できないかを考えてみる。
計算に関係があるのは、数A[i]の組み合わせだけになる。
全部で数A[i]がcnt個あるとする。
全部で計算してある計算結果で関係する部分は、cnt×(cnt - 1)/2なので、これを引く。
そして、i番目がないと考えると、数A[i]がcnt-1個あることになるので、これを新たに足す。
(cnt-1)×(cnt-2)/2を足す。
これで全体の計算から差分だけを計算してiを除いた場合の組み合わせが得られる。
///////////////////////// writeup2 end */
