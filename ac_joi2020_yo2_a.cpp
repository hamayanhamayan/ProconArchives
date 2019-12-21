//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_a
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
vector<string> rotateClockwise(vector<string> g) {
	int n = g.size();
	int m = g[0].size();
	vector<string> res(m, string(n, '#'));
	rep(i, 0, n) rep(j, 0, m) res[j][n - i - 1] = g[i][j];
	return res;
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














int N;
string T[500];
int costs[4] = { 0, 1, 2, 1 };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	vector<string> S(N);
	rep(y, 0, N) cin >> S[y];
	rep(y, 0, N) cin >> T[y];

	int ans = inf;
	rep(d, 0, 4) {
		int diff = 0;
		rep(y, 0, N) rep(x, 0, N) if (S[y][x] != T[y][x]) diff++;
		chmin(ans, diff + costs[d]);
		S = rotateClockwise(S);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
操作が3種類あるが、大きく塗り替えと回転である。
時計回りに回転させてから、反時計回りに回転させるという動作は無駄なので、
回転操作は「そのまま」「時計回りに1回」「時計回りに2回」「反時計回りに1回」の4通りで固定になる。
塗り替えと回転は独立した操作なので、先に回転しておき、最小の塗替えを考えればいい。
最小の塗り替えは、単に異なる部分を塗り替えればいいので、異なる個数を数えればいい。

あとは、実装であるが、回転操作は自分はライブラリ化してあるので、それを使っている。
添字の管理がちょっと大変なのだが、単純な二重ループに帰着させることができる。
時計回りと反時計回りの2つを実装するのは、大変なので、反時計回りは時計回りを3回やることにする。
///////////////////////// writeup2 end */
