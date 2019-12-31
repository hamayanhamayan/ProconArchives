//https://atcoder.jp/contests/past201912-open/tasks/past201912_l
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, X[40], Y[40], C[40];
//---------------------------------------------------------------------------------------------------
double solve(int msk) {
	vector<int> points;
	rep(i, 0, N) points.push_back(i);
	rep(i, 0, M) if (msk & (1 << i)) points.push_back(i + N);
	int n = points.size();

	vector<pair<double, pair<int, int>>> edges;
	rep(i, 0, n) rep(j, i + 1, n) {
		int a = points[i];
		int b = points[j];
		double dx = X[a] - X[b];
		double dy = Y[a] - Y[b];
		double d = sqrt(dx * dx + dy * dy);
		if (C[a] != C[b]) d *= 10;
		edges.push_back({ d, {i, j} });
	}
	sort(all(edges));

	UnionFind uf(n);
	double ans = 0;
	fore(p, edges) {
		double cst = p.first;
		int a = p.second.first;
		int b = p.second.second;
		if (uf[a] != uf[b]) {
			uf(a, b);
			ans += cst;
		}
	}
	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> X[i] >> Y[i] >> C[i];
	rep(i, 0, M) cin >> X[i + N] >> Y[i + N] >> C[i + N];

	double ans = 1e30;
	rep(msk, 0, 1 << M) chmin(ans, solve(msk));
	printf("%.12f\n", ans);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [最小全域木](https://www.hamayanhamayan.com/entry/2018/09/17/163004)
///////////////////////// writeup2 start
条件も多くて大変そう。
似ているアルゴリズムを考えると、最小全域木であるが、0＜Mなのでどうしようかという感じ。
Mがなくなれば解けそうだが、先にMの可能性を潰すというのも難しそう。
他に使えそうな感じというと、色の種類が3種類しかない。
…
いや、これ難しくない？？？

まあ、冷静に考えると、最小全域木に帰着できるんだろうなという所は譲れない。
ここがなくなると考える道筋がなくなる。
そうすると邪魔なのが、小さな塔の扱いである。
連結する小さい塔が分かっていれば、あとは最小全域木になる。
あぁ、これだ。

ポエムはこの辺にして、以下解法。
最小全域木の求め方が分からない方は、ググって勉強してこよう。
そちらが理解できていないとこちらは分からないし、この問題は入門には向かない。
小さな塔で使うものの組み合わせを全列挙する。
これで、連結させたい頂点が全て揃うので、全ての頂点間に辺があると考えて、最小全域木を探す。
この中で最小コストのものが答え。
///////////////////////// writeup2 end */
