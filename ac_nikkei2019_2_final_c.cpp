//https://atcoder.jp/contests/nikkei2019-2-final/tasks/nikkei2019_2_final_c
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
template<int VW, int VH> struct RuisekiwaNaname {
	using T = int;
	T v[VH][VW], v2[VH][VW];
	RuisekiwaNaname() { rep(y, 0, VH) rep(x, 0, VW) v[y][x] = v2[y][x] = 0; }
	void set(int x, int y, T c) { v[y][x] = v2[y][x] = c; }
	void add(int x, int y, T c) { v[y][x] += c; v2[y][x] += c; }
	void build() {
		rep(y, 1, VH) rep(x, 1, VW) v[y][x] += v[y - 1][x - 1];
		rep(y, 0, VH) rep(x, 0, VW) if (0 <= y - 1 and x + 1 < VW) v2[y][x] += v2[y - 1][x + 1];
	}
	T getToLeftTop(int x, int y, int len) {
		if (x + 1 < len) len = x + 1;
		if (y + 1 < len) len = y + 1;
		T res = v[y][x];
		if (0 <= x - len and 0 <= y - len) res -= v[y - len][x - len];
		return res;
	}
	T getToRightBottom(int x, int y, int len) {
		if (VW - x < len) len = VW - x;
		if (VH - y < len) len = VH - y;
		return getToLeftTop(x + len - 1, y + len - 1, len);
	}
};
#ifdef _MSC_VER
inline unsigned int __builtin_clz(unsigned int x) { unsigned long r; _BitScanReverse(&r, x); return 31 - r; }
#endif // _MSC_VER
template<class V> struct SparseTable { // [L,R)
	const V def = -inf;
	inline V comp(V a, V b) { return max(a,b); }

	int n; vector<V> a, b[22]; inline int __lg(int x) { return 32 - 1 - __builtin_clz(x); }
	void init(vector<V> v) {
		int nn = v.size(); n = 1; while (n < nn) n *= 2; a.resize(n);
		rep(i, 0, 22) b[i].resize(n); rep(i, 0, nn) a[i] = v[i];

		int d = 1 << __lg(n - 1), e = d << 1;
		for (int h = 0, f; (f = 1 << h) <= d; ++h) {
			for (int i = f, r = f << 1; i < e; i += r) {
				b[h][i - 1] = a[i - 1];
				for (int j = i - 2; j >= i - f; --j) b[h][j] = comp(b[h][j + 1], a[j]);
				b[h][i] = a[i];
				for (int j = i + 1; j < i + f; ++j) b[h][j] = comp(b[h][j - 1], a[j]);
			}
		}
	}

	V get(int L, int R) {
		assert(0 <= L && L <= R); if (L == R)return def; R--; if (L == R)return a[L]; int h = __lg(L ^ R);
		return comp(b[h][L], b[h][R]);
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














int H, W, K;
Ruisekiwa2D<3010, 3010> r2d;
RuisekiwaNaname<3010, 3010> rnn;
int max1[3010][3010], max2[3010][3010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> K;
	rep(y, 0, H) rep(x, 0, W) {
		r2d.add(x, y, 1);
		rnn.add(x, y, 1);
	}
	rep(k, 0, K) {
		int y, x; cin >> y >> x;
		y--; x--;
		r2d.add(x, y, -1);
		rnn.add(x, y, -1);
	}
	r2d.build();
	rnn.build();

	rep(y, 0, H) rep(x, 0, W) {
		int ok = 0, ng = H + W;
		while (ok + 1 != ng) {
			int md = (ok + ng) / 2;
			if (r2d.getToDown(x, y, md) == md and rnn.getToRightBottom(x, y, md) == md) ok = md;
			else ng = md;
		}
		max1[y][x] = ok;
	}
	rep(y, 0, H) rep(x, 0, W) {
		int ok = 0, ng = H + W;
		while (ok + 1 != ng) {
			int md = (ok + ng) / 2;
			if (r2d.getToUp(x, y, md) == md and rnn.getToLeftTop(x, y, md) == md) ok = md;
			else ng = md;
		}
		max2[y][x] = ok;
	}

	vector<vector<pair<int,int>>> order(H + W + 5);
	rep(x, 0, W) rep(y, 0, H) order[x - y + H].push_back({ x, y });
	int ans = 0;
	rep(xy, 0, H + W + 5) {
		vector<int> v(W, -inf);
		fore(p, order[xy]) v[p.first] = max2[p.second][p.first] - p.first;
		SparseTable<int> st;
		st.init(v);

		fore(p, order[xy]) {
			int ok = p.first - 1, ng = W;
			while (ok + 1 != ng) {
				int md = (ok + ng) / 2;
				if (1 - p.first <= st.get(md, W)) ok = md;
				else ng = md;
			}
			chmax(ans, ok - p.first + 1);
		}
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
各座標について、
max1[y][x] := 座標(x,y)から下と右下にマスを伸ばしたときに伸ばせる最大長
max2[y][x] := 座標(x,y)から上と左上にマスを伸ばしたときに伸ばせる最大長
これをあらかじめ求めておこう。
これは累積和と二分探索を使えばO(HWlog(H+W))でいける。

ある座標(x,y)に対して作れるNは(x-k,y-k)について
k+1≦max1[y-k][x-k]かつk+1≦max2[y][x]を満たす全てのkを求めればいい。
後半の条件を見ると、kとして使える範囲が分かる。
この段階ではまだO(HW*(H+W))くらい。

移動するのは斜めだけなので、斜めに見ていくことにしよう。
ある頂点(x,y)をNの左上とすると、サイズ0～max1[y][x]のNを作れる可能性がある。
サイズszが作れるかどうかは、sz≦max2[y+sz-1][x+sz-1]である必要がある。
これは言い換えると、0≦max2[y+sz-1][x+sz-1]-szとも言える。
x'=x+sz-1, y'=y+sz-1とすると、0≦max2[y'][x']+x-x'-1である。
これは1-x≦max2[y'][x']-x'を満たすことになる。
よって、各xについて、1-x以上であり、最も右の要素を取ってくればいい。
斜めで見ていくとだんだんxは小さくなっていくので、条件を満たす要素が多くなっていく。
なので、最も右の要素もだんだん右にずれていく。
これを利用して尺取法的に解いていこう。
スパーステーブルで区間maxを取得して、二分探索でもいい。
こっちの方が楽かも。
///////////////////////// writeup2 end */
