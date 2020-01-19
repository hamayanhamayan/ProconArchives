//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
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
pair<int, int> robots[101010];
int dp[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) {
		int x, l;
		cin >> x >> l;
		robots[i] = { x + l, l };
	}
	sort(robots, robots + N);

	rep(i, 0, N) {
		chmax(dp[i + 1], dp[i]);
		
		int x = robots[i].first - robots[i].second;
		int l = robots[i].second;

		auto ite = lower_bound(robots, robots + N, make_pair(x - l, inf));
		int pre = ite - robots;
		chmax(dp[i + 1], dp[pre] + 1);
	}

	cout << dp[N] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/04/23/212728)
///////////////////////// writeup2 start
DPをしよう。
200点でなので想定解は貪欲なんだろうという気もするが、DPでさくっとかけるので書いてしまう。
dp[i] := i番目まで残すか確定していて、i番目のロボットを残した場合の個数最大値

どうやってこれで解くんだろうというのを説明する。
ロボットを左から残していくかを考えると、i番目のロボットを置くと、X[i]+L[i]-1までは占領してしまう。
かつ、i番目のロボットがおけるのは、最後にロボットとその手がかかる領域がX[i]-L[i]までの場合である。
これは既に置かれているロボットのX[i]+L[i]-1が関係してくる。
つまり、順番はX[i]+L[i]の昇順に置かれることになる。
よって、これでソートしておくと、順番に置くかどうかの問題となり、DPに帰着させることができる。

dp[i+1]を更新したい時に、i番目のロボットがおけるかを考えたいが、lower_boundを使って、pre番目のロボットまでおけることを調べよう。
すると、dp[i+1]はmax(dp[0], dp[1], ..., dp[pre]) + 1となるが、計算しながら、
dp[i] := i番目まで残すか確定している場合の個数最大値
を累積和っぽく求めておくと、達成できる。

追記：区間スケジューリング問題でしたね。ホントやわ。
{ X[i]+L[i], X[i]-L[i] }で配列入れて、ソートして、区間の右端が小さいものから貪欲に取って、カウントしていく。
///////////////////////// writeup2 end */
