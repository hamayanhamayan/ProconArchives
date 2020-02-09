//https://atcoder.jp/contests/abc154/tasks/abc154_d
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














int N, K, p[201010];
double e[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> p[i];

	rep(i, 0, N) e[i] = 1.0 * (1 + p[i]) / 2;

	double tot = 0;
	rep(i, 0, K) tot += e[i];

	double ans = tot;
	rep(i, K, N) {
		tot = tot + e[i] - e[i - K];
		chmax(ans, tot);
	}
	printf("%.10f\n", ans);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [期待値の線形性](https://www.hamayanhamayan.com/entry/2016/11/14/223727)
///////////////////////// writeup2 start
期待値の線形性というのがある。
それぞれのサイコロは独立に期待値を考えることができるので、合計の期待値は期待値の合計と等しくなる。
つまり、「隣接するK個のサイコロを選んで独立に振った時に出る目の合計の期待値」は
「隣接するK個のサイコロを選んで独立に振った時に出る目の期待値の合計」と等しい。
なので、最大化したい値の計算が区間和に帰着した。
隣接するK個のサイコロの選び方はN-K+1通りあるので、区間和が高速に求まれば、問題が解けたことになる。

これは累積和を使っても解けるが、自分の解法ではスライドしながら差分計算する方法でやっている。
ある隣接するK個の区間を計算し終わったら、その区間を右に1つ動かすことで、
先頭を引いて、追加されたサイコロ分を追加することで差分を計算する。
これで高速に区間和を求めることができ、計算しつつmaxを取ると答え。
///////////////////////// writeup2 end */
