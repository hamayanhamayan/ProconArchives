//https://atcoder.jp/contests/otemae2019/tasks/otemae2019_g
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













int N, M, P, Q, R, S, T[1010], A[1010], B[1010], C[1010], D[1010];
//---------------------------------------------------------------------------------------------------
vector<int> dicx, dicy;
int W, H;
void compress() {
	dicx.push_back(P); dicy.push_back(Q);
	dicx.push_back(R); dicy.push_back(S);
	rep(i, 0, M) {
		dicx.push_back(A[i]); dicx.push_back(B[i]);
		dicy.push_back(C[i]); dicy.push_back(D[i]);
	}
	sort(all(dicx)); dicx.erase(unique(all(dicx)), dicx.end());
	sort(all(dicy)); dicy.erase(unique(all(dicy)), dicy.end());

	W = dicx.size();
	H = dicy.size();
}
//---------------------------------------------------------------------------------------------------
int warp_migi[2010][2010];
int warp_shita[2010][2010];
void makeEdges() {
	rep(i, 0, M) {
		int a = lower_bound(all(dicx), A[i]) - dicx.begin();
		int b = lower_bound(all(dicx), B[i]) - dicx.begin();
		int c = lower_bound(all(dicy), C[i]) - dicy.begin();
		int d = lower_bound(all(dicy), D[i]) - dicy.begin();

		if (T[i] == 1) {
			// tate warp
			warp_shita[a][c]++;
			warp_shita[b + 1][c]--;
			warp_shita[a][d]--;
			warp_shita[b + 1][d]++;
		}
		else {
			// yoko warp
			warp_migi[a][c]++;
			warp_migi[b][c]--;
			warp_migi[a][d + 1]--;
			warp_migi[b][d + 1]++;
		}
	}

	rep(x, 0, W) rep(y, 1, H) warp_migi[x][y] += warp_migi[x][y - 1];
	rep(y, 0, H) rep(x, 1, W) warp_migi[x][y] += warp_migi[x - 1][y];

	rep(x, 0, W) rep(y, 1, H) warp_shita[x][y] += warp_shita[x][y - 1];
	rep(y, 0, H) rep(x, 1, W) warp_shita[x][y] += warp_shita[x - 1][y];
}
//---------------------------------------------------------------------------------------------------
bool vis[2010][2010]; ll dist[2010][2010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
ll dijk() {
	rep(y, 0, H) rep(x, 0, W) dist[x][y] = infl;
	rep(y, 0, H) rep(x, 0, W) vis[x][y] = false;

	min_priority_queue<pair<ll, pair<int,int>>> que;

	int sx = lower_bound(all(dicx), P) - dicx.begin();
	int sy = lower_bound(all(dicy), Q) - dicy.begin();
	int tx = lower_bound(all(dicx), R) - dicx.begin();
	int ty = lower_bound(all(dicy), S) - dicy.begin();
	
	dist[sx][sy] = 0;
	que.push({ 0, {sx, sy} });

	while (!que.empty()) {
		auto q = que.top(); que.pop();

		ll cst = q.first;
		int x = q.second.first;
		int y = q.second.second;

		if (vis[x][y]) continue;
		vis[x][y] = true;

		if (x == tx and y == ty) return dist[x][y];

		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx and xx < W and 0 <= yy and yy < H) {
				ll cst = 0;

				if (d % 2 == 0) {
					// tate
					if (warp_shita[x][min(y, yy)] == 0) cst = dicy[max(y, yy)] - dicy[min(y, yy)];
				}
				else {
					// yoko
					if (warp_migi[min(x, xx)][y] == 0) cst = dicx[max(x, xx)] - dicx[min(x, xx)];
				}

				if (chmin(dist[xx][yy], dist[x][y] + cst)) {
					que.push({ dist[xx][yy], {xx, yy} });
				}
			}
		}
	}

	return -1;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> P >> Q >> R >> S;
	rep(i, 0, M) cin >> T[i] >> A[i] >> B[i] >> C[i] >> D[i];

	compress();
	makeEdges();
	cout << dijk() << endl;
}






/* ///////////////////////// writeup1 start
# 前提知識
- 座標圧縮
- [imos](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
- [ダイクストラ](https://www.hamayanhamayan.com/entry/2017/05/14/134606)
///////////////////////// writeup2 start
ベースはBFSな感じがする。
だが、BFSにしては盤面が広い。
そこで座標圧縮してダイクストラするという流れがある。
座標移動系で重要な座標は限られて、座標圧縮するとダイクストラできるという問題を見たことがある。
今回もそれベースで考えてみる。

よくよく見ると、ワープ可能範囲が矩形であるが、おそらく重要なのは、4隅だけであろう。
なので、始点終点と矩形の4隅で使われているx座標, y座標で座圧しよう。
これで各頂点について4辺ができて、コストもわかる。
あとは、場所によってコストが0になっているので、そこを判定すればいい。
これは、ある矩形について、コストが0になる部分も矩形の形になる。
矩形の部分すべてに+1するよう2Dimosを使えば、コストが0である部分を前計算できる。
これで頂点と辺が整ったので、あとはダイクストラする。
O(M^2logM)で心配だが、よくよくみると実行時間も長めなので、気を付けて実装すれば通る。
///////////////////////// writeup2 end */
	