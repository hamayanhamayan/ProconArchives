//https://atcoder.jp/contests/otemae2019/tasks/otemae2019_f
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













int N, D;
ll M[2010][2010];
ll dp[2010][2010];
//---------------------------------------------------------------------------------------------------
ll get(int day, int moved) {
	ll tot = M[day - 1][N - 1];
	ll R = 0;
	if(0 < moved) R = M[day - 1][moved - 1];
	ll L = tot - R;

	return abs(R - L);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> D;
	rep(i, 0, D) rep(j, 0, N) cin >> M[i][j];
	rep(i, 0, D) rep(j, 1, N) M[i][j] += M[i][j - 1];

	rep(day, 0, D + 1) rep(moved, 0, N + 1) dp[day][moved] = infl;
	dp[0][0] = 0;

	rep(day, 1, D + 1) {
		ll mi = infl;
		rep(moved, 0, N + 1) {
			chmin(mi, dp[day - 1][moved]);
			chmin(dp[day][moved], mi + get(day, moved));
		}
	}

	ll ans = infl;
	rep(moved, 0, N + 1) chmin(ans, dp[D][moved]);
	cout << ans << endl;
}






/* ///////////////////////// writeup1 start
# 前提知識
- [DP更新最適化](https://www.hamayanhamayan.com/entry/2017/03/20/234711)
///////////////////////// writeup2 start
最小値を求める問題で制約も10^3くらいなので、DPかフローかという雰囲気がある。
まずはDPから考えてみる。
10^3制約でのDPはdp[10^3][10^3]が基本なので、これで考える。
dp[day][moved] := day日終わっていて、すでにmoved個コインを移動させたときの最小コスト
dp[10^3][10^3]では、遷移を工夫するしかないので、最適化する方針で考える。
まずは貰うDPで考える。

dp[day][moved]の更新を考える。
moved移動させた後のコストはmovedによって一定なので、それまでのコストの最小値が知りたくなる。
つまり、`dp[day-1][0]～dp[day-1][moved]の最小値 + moved移動させた後のコスト`が更新値になる。
前半部分はは累積和を使って高速に求めよう。
後半部分は、M[i][j] = M[i][0] + M[i][1] + ... M[i][j]のように変換させて、累積和しよう。
///////////////////////// writeup2 end */
	