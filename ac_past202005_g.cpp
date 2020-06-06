//https://atcoder.jp/contests/past202005-open/tasks/past202005_g
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
bool blocked[505][505];
const int MA = 500;
const int BASE = 250;
bool vis[505][505];
int mi[505][505];
int dx[6] = { 1, 0, -1, 1, -1, 0 }, dy[6] = { 1, 1, 1, 0, 0, -1 };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> X >> Y;
	X += BASE;
	Y += BASE;
	rep(i, 0, N) {
		int x, y; cin >> x >> y;
		blocked[y + BASE][x + BASE] = true;
	}

	queue<pair<int, int>> que;
	que.push({ BASE, BASE });
	vis[BASE][BASE] = true;

	while (!que.empty()) {
		int x, y;
		tie(x, y) = que.front(); que.pop();

		rep(d, 0, 6) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx && xx < MA && 0 <= yy && yy < MA) {
				if (blocked[yy][xx]) continue;
				if (vis[yy][xx]) continue;

				vis[yy][xx] = true;
				mi[yy][xx] = mi[y][x] + 1;
				que.push({ xx, yy });
			}
		}
	}

	if (vis[Y][X]) cout << mi[Y][X] << endl;
	else cout << -1 << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
さあ、この辺からギアが上がってくる感じがある。

コスト1の移動である地点からある地点への最短距離を求めると言えばBFSなので、
まずはBFSをベースに考えてみる。
考えるべき盤面の広さはどれだけだろうか。
縦も横も[-200,200]は入力があるので必要だろう。
それ以上は必要だろうか？
いや、必要ない。無駄に大回りになってしまうだけである。
本当か？
(200,200)がゴールで(199,200),(199,199),(200,199)に障害物があれば、迂回の必要があるぞ？
だが、それでも「大回り」をする必要はない。
よってちょっとした迂回分を入れた[-201,201]の広さの盤面でBFSすれば大丈夫。

正直、自分はあまりよく考えず[-250,250]くらいでやりました。
これで縦横で500×500くらいなので、これはBFSできる。
注意点としては配列に負数を入れる必要が出てくるので、BASEを使って0を250くらいにしておこう。
実装ヒントとして、遷移はゴリゴリ書くのではなく、dxdy記法を使うのがオススメ。
///////////////////////// writeup2 end */
