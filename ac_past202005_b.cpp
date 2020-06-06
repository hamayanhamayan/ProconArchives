//https://atcoder.jp/contests/past202005-open/tasks/past202005_b
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














int N, M, Q;
bool solved[101010][51];
int solvedCount[51];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> Q;
	rep(_, 0, Q) {
		int t; cin >> t;
		if (t == 1) {
			int n; cin >> n;

			ll point = 0;
			rep(m, 1, M + 1) if (solved[n][m]) point += N - solvedCount[m];
			printf("%lld\n", point);
		}
		else {
			int n, m; cin >> n >> m;
			solvedCount[m]++;
			solved[n][m] = true;
		}
	}
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
クエリ問題。
まだ序盤なので、競プロで要求されるようなクエリ問題へのアプローチは必要なく、単なるシミュレーションで解ける。

参加者nのスコアの計算方法を見てみる。
「N-(現時点でこの問題を解いた人数)」をM問題分足し合わせたものになる。
Mの値は小さいので、毎回ループしても問題ない。
問題は、(現時点でこの問題を解いた人数)をいかに早く計算するかである。
これを事前計算という形でどこかに保持しておこう。
solvedCount[m] := 問題mが何人に解かれているか
これをクエリ2が来た段階で、適切にインクリメントしていく。

あとは、足し合わせる問題は、参加者nが解いている問題に限るので、解いたかどうかの情報もどこかに置いておく必要がある。
solved[n][m] := 参加者nが問題mを解いたか

クエリ1では、solved配列を見ながら、解いた問題に対して、N-solvedCount[n][m]を足し合わせればいい。
クエリ2では、解いた人と問題に対して、solved配列とsolvedCount配列を更新する。
///////////////////////// writeup2 end */
