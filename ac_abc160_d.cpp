//https://atcoder.jp/contests/abc160/tasks/abc160_d
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














int N, X, Y;
int ans[2010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> X >> Y;
	X--; Y--;

	rep(i, 0, N) rep(j, i + 1, N) {
		int k = inf;

		// not use X -> Y
		chmin(k, j - i);

		// use X -> Y
		chmin(k, abs(X - i) + abs(Y - j) + 1);

		ans[k]++;
	}

	rep(k, 1, N) cout << ans[k] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
今回の問題で最も重要なのは、制約に気が付くところにある。
Nは最大2000なので、O(N^2)が通る。
計算量は10^7くらいを上限にしてとりあえず考えるといいだろう。

さて、O(N^2)が通るということは、すべての整数の組を全列挙できるということ。
整数の組(i,j)が与えられたときの最短経路を考えてみよう。
実はあまり、移動方法がない。

1. iからjにX->Yの辺を使わず移動する
2. i -> X -> Y -> jと移動する

この時、X -> Yの移動以外は、直線状の移動となるので、x->yに移動するときの最短距離はabs(x-y)となる。
よって、1はj-iが答えとなるし、2もabs(i-X) + 1 + abs(Y - j)となる。
最短距離は1と2の小さい方となるので、全部O(1)で計算可能。
これで「ans[k] := 最短距離がkである組の個数」をインクリメントしながら集計していき、最後に答える。
///////////////////////// writeup2 end */
