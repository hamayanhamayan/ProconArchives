//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_e
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
struct UnionFind {
	using T = int;
	const T def = 0;
	T f(T a, T b) { return a + b; }
	//==========================================
    vector<int> par; 
	vector<T> value;
    UnionFind() {}
    UnionFind(int NV) { init(NV); }
	void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); value.resize(NV, 1); }
    void reset() { rep(i, 0, par.size()) par[i] = i; }
	int operator[](int x) {
		if (par[x] == x) return x;
		else {
			int res = operator[](par[x]);
			if (res != par[x]) {
				value[res] = f(value[res], value[par[x]]);
				value[par[x]] = def;
			}
			return par[x] = res;
		}
	}
	// uf(x,y)->y
    void operator()(int x, int y) {
		x = operator[](x); y = operator[](y); 
		if (x != y) {
			value[y] += value[par[x]];
			value[par[x]] = def;
			par[x] = y;
		}
	}
	T getValues(int x) { return value[operator[](x)]; };
};
struct UnionFind2D {
	using T = int;
	int H, W;
	UnionFind uf;
	UnionFind2D() {}
	UnionFind2D(int NH, int NW) { init(NH, NW); }
	void init(int NH, int NW) { H = NH, W = NW, uf.init(H * W); }
	// {x, y}
	pair<int, int> get(int x, int y) { return { uf[y * W + x] % W, uf[y * W + x] / W }; }
	void marge(int x1, int y1, int x2, int y2) {
		uf(x1 + y1 * W, x2 + y2 * W);
	}
	T getValue(int x, int y) { 
		return uf.getValues(x + y * W);
	}
};
template<int VW, int VH> struct Ruisekiwa2D {
	using T = int;
	T v[VH][VW];
	Ruisekiwa2D() { rep(y, 0, VH) rep(x, 0, VW) v[y][x] = 0; }
	void set(int x, int y, T c) { v[y][x] = c; }
	void add(int x, int y, T c) { v[y][x] += c; }
	void build() {
		rep(y, 0, VH) rep(x, 0, VW) {
			if (0 < y) v[y][x] += v[y - 1][x];
			if (0 < x) v[y][x] += v[y][x - 1];
			if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
		}
	}
	T get(int sx, int tx, int sy, int ty) { // [sx,sy]～[tx,ty]
		if (tx < sx or ty < sy) return 0;
		T rs = v[ty][tx];
		if (0 < sx) rs -= v[ty][sx - 1];
		if (0 < sy) rs -= v[sy - 1][tx];
		if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
		return rs;
	}
	T getToDown(int x, int y, int len) {
		if (VH - y < len) len = VH - y;
		return get(x, x, y, y + len - 1);
	}
	T getToUp(int x, int y, int len) {
		if (y + 1 < len) len = y + 1;
		return get(x, x, y - len + 1, y);
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, W;
string S[1510];
Ruisekiwa2D<1510, 1510> r2d;
int Q;
int X[151010], Y[151010], L[151010];
vector<int> queries[1510];
vector<pair<int, int>> que[1510];
int ma[1510][1510];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int ans[151010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> S[y];
	cin >> Q;
	rep(i, 0, Q) cin >> Y[i] >> X[i] >> L[i];

	rep(y, 0, H) rep(x, 0, W) if (S[y][x] == '#') r2d.set(x, y, 1);
	r2d.build();

	rep(i, 0, Q) queries[L[i]].push_back(i);
	rep(y, 0, H) rep(x, 0, W) {
		int len = min(H - y, W - x);
		int ok = 0, ng = len + 1;
		while (ok + 1 != ng) {
			int md = (ok + ng) / 2;
			if (r2d.get(x, x + md - 1, y, y + md - 1) == 0) ok = md;
			else ng = md;
		}
		ma[y][x] = ok;
		que[ma[y][x]].push_back({ x, y });
	}

	UnionFind2D uf(H, W);

	rrep(l, 1500, 1) {
		fore(p, que[l]) {
			int x = p.first;
			int y = p.second;
			rep(d, 0, 4) {
				int xx = x + dx[d];
				int yy = y + dy[d];
				if (0 <= xx and xx < W and 0 <= yy and yy < H) {
					if (l <= ma[yy][xx]) uf.marge(x, y, xx, yy);
				}
			}
		}
		fore(i, queries[l]) {
			ans[i] = uf.getValue(X[i] - 1, Y[i] - 1);
		}
	}

	rep(i, 0, Q) printf("%d\n", ans[i]);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二次元累積和](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
- [BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
クエリ問題では、まず1クエリだとどう解くかを考えるのが定石。
操作の建物と重ならないようにちょうど1メートル動かす操作をする。
これは、プレゼントの左上のマスが今いるマスと考えると、横に1マス移動していることになる。
すると、今回の答えは周りに1マス移動するときに到達可能な頂点の個数となる。
これらの情報からBFSで解けるのではと考える。
制約もそれっぽい。
だが、マスによっては建物とかぶってしまって移動できない。
これを判定するには二次元累積和を使えばO(1)で使えるマスかが判定できる。
これでBFSをすれば、O(HW)では解けそうだ。

これでは満点は狙えない。
Lが変わる問題にどう立ち向かおうか。
さて、ここからブレイクスルーをする必要がある。
UnionFindを使おう。
到達可能な頂点の個数は、隣り合う使える頂点を連結した連結成分に含まれる頂点数と等しくなる。
この考察に至るまで大変だと思う。
あと、ここから更に必要なのが、Lを大きい方から見て、オフライン計算をしていく必要がある。
クエリを事前に読み込んでおき、分類しておこう。
queries[l] := L[i]=lであるクエリのiの集合

次に以下を前計算しておく。
ma[y][x] := 各頂点で置ける最大のプレゼントの大きさ
これは二次元累積和と二分探索をすればO(HWlog(H+W))でできる。
これで「que[l] := ma[y][x]がlである座標の集合」を作っておく。

あとは、Lを大きい方から順番に見ていって、que[l]にある頂点とその周りの頂点が連結できれば連結する。
連結後に、queries[l]に含まれる頂点の連結成分の個数を答える。
///////////////////////// writeup2 end */
