//https://atcoder.jp/contests/agc041/tasks/agc041_e
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














int N, M, T;
int X[101010], Y[101010];
#define UP '^'
#define DOWN 'v'
//---------------------------------------------------------------------------------------------------
using BS = bitset<50101>;
BS dp[50101];
void solve1() {
	rep(i, 0, N) dp[i].set(i);

	rep(i, 0, M) dp[X[i]] = dp[Y[i]] = dp[X[i]] | dp[Y[i]];
	rep(i, 0, N) if (dp[i].count() == N) {
		int goal = i;
		UnionFind uf(N);
		string ans = "";
		rrep(j, M - 1, 0) {
			int g = uf[goal];
			int x = uf[X[j]];
			int y = uf[Y[j]];

			if (g != x and g != y) ans += UP;
			else if (g == x and g == y) ans += UP;
			else if (g == x) {
				ans += UP;
				uf(x, y);
			}
			else {
				ans += DOWN;
				uf(x, y);
			}
		}
		reverse(all(ans));
		cout << ans << endl;
		return;
	}

	cout << -1 << endl;
}
//---------------------------------------------------------------------------------------------------
int B[50101], cnt[50101];
void solve2() {
	if (N == 2) {
		cout << -1 << endl;
		return;
	}

	rep(i, 0, N) B[i] = i, cnt[i] = 1;

	string ans = "";
	rrep(i, M - 1, 0) {
		int x = X[i], y = Y[i];
		int bx = B[x], by = B[y];

		if (cnt[bx] > cnt[by]) {
			ans += DOWN;
			cnt[by]++;
			cnt[bx]--;
			B[x] = by;
		}
		else {
			ans += UP;
			cnt[bx]++;
			cnt[by]--;
			B[y] = bx;
		}
	}
	reverse(all(ans));
	cout << ans << endl;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> T;
	rep(i, 0, M) {
		cin >> X[i] >> Y[i];
		X[i]--, Y[i]--;
	}

	if (T == 1) solve1();
	else solve2();
}





/* ///////////////////////// writeup1 start
# 前提知識
- [bitset高速化](https://www.hamayanhamayan.com/entry/2017/06/07/234608)
///////////////////////// writeup2 start
2つの問題が入っているが、全く別のアプローチで解く。

T=1では、bitset高速化で解く。
dp[i][j] := 平衡器iから平衡器jへ到達可能か
これのjの部分をbitsetで持つことにする。
すると、X[i]とY[i]のケーブルによって、
dp[X[i]] = dp[Y[i]] = dp[X[i]] | dp[Y[i]]
と更新することができる。
これで、dp[i]でbitが立っている個数がNであるものがあれば、そこにコインを集めることができる。
復元パートは、逆からUnionFindを使って、集める目的地へ向かって矢印を伸ばせばいい。

T=2を考えよう。
一番難しいパターンを考えてみる。
N=2はどう抗っても無理そう。なので-1。
N=3はどうだろう。
M=100000としても解けるだろうか。
実は解ける。
M[i]に↑か↓をつけるが、矢印の先の平衡器がM[i+1]のケーブルの端点になっていない方を選ぶ。
これだけで実は達成できる。
一般化すると、途中までは適当に矢印をつけて、3つの平衡器になったら、その段階でさきのアルゴリズムを適用する。

でも、これは実装が結構大変なので、答えに書いてあるcntとBを使う解法が実装が軽くてオススメ。
なんで、それでうまくいくのかはよくわからん。
///////////////////////// writeup2 end */
