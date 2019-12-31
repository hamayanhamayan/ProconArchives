//https://atcoder.jp/contests/past201912-open/tasks/past201912_j
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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, W, A[50][50];
//---------------------------------------------------------------------------------------------------
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
vector<vector<int>> djik(int sx, int sy) {
	vector<bool> vis(H * W);
	vector<vector<int>> res(H, vector<int>(W, inf));
	min_priority_queue<pair<int, int>> que;

	res[sy][sx] = 0;
	que.push({ 0, sx + sy * W });

	while (!que.empty()) {
		auto q = que.top(); que.pop();

		int cst = q.first;
		int id = q.second;

		if (vis[id]) continue;
		vis[id] = true;

		int x = id % W;
		int y = id / W;

		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx and xx < W and 0 <= yy and yy < H) {
				if (chmin(res[yy][xx], res[y][x] + A[yy][xx])) {
					que.push({ res[yy][xx], xx + yy * W });
				}
			}
		}
	}

	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];

	auto mix = djik(0, H - 1);
	auto miy = djik(W - 1, H - 1);
	auto miz = djik(W - 1, 0);

	int ans = inf;
	rep(y, 0, H) rep(x, 0, W) chmin(ans, mix[y][x] + miy[y][x] + miz[y][x] - 2 * A[y][x]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [ダイクストラ](https://www.hamayanhamayan.com/entry/2017/06/11/124732]
///////////////////////// writeup2 start
難しい問題。
左下を点X, 右下を点Y, 右上を点Zとしておこう。
簡単にX->Yの最短距離+Y->Zの最短距離が答えになりそう。
だが、実際にはそうではない。サンプル1がそれを示している。
そうではないが、答えはこれに近くなる。

二点の最短距離だったらどう解くかを考えよう。
X -> Yの最短距離をどう求めるか。
最短経路でDP使えないといえば、ダイクストラである。
うん。それで行けそうだ。

さて、元々の問題をいかに解くかであるが、
サンプル1を眺めると、X -> YとY -> Zのパスでは、ある1点だけを共有しているように見える。
つまり、X -> P -> Yというパスと、Y -> P -> Zというパスで最短経路を構成している。
まあ、このくらいの過程が無いと、解けないような雰囲気もある。

ここで変数となっているのは点Pなので、これを全探索する。
Pから最短距離を全探索してもいいが、計算量が怪しいので、X,Y,Zからの最短距離を前計算しておくことにする。
これをそれぞれ、minx, miny, minzとしておく。
点Pを固定すると、最短距離は minx[P] + miny[P] + minz[P] - 2A[P]となる。
///////////////////////// writeup2 end */
