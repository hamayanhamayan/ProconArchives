//https://atcoder.jp/contests/kupc2019/tasks/kupc2019_b
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
	vector<int> par; // uf(x,y)->y
	UnionFind() {}
	UnionFind(int NV) { init(NV); }
	void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); }
	void reset() { rep(i, 0, par.size()) par[i] = i; }
	int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
	void operator()(int x, int y) { x = operator[](x); y = operator[](y); if (x != y) par[x] = y; }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, W, w[101], v[101];
int dp[101][10101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> W;
	rep(i, 0, N) cin >> w[i] >> v[i];

	UnionFind uf(N);
	rep(i, 0, M) {
		int a, b; cin >> a >> b; 
		a--; b--;
		uf(a, b);
	}

	vector<int> items;
	rep(i, 0, N) {
		if (uf[i] != i) {
			w[uf[i]] += w[i];
			v[uf[i]] += v[i];
		}
		else items.push_back(i);
	}

	N = items.size();
	rep(i, 0, N + 1) rep(wei, 0, W + 1) dp[i][wei] = -inf;
	dp[0][0] = 0;
	rep(i, 0, N) rep(wei, 0, W) {
		chmax(dp[i + 1][wei], dp[i][wei]);
		int wei2 = wei + w[items[i]];
		if (wei2 <= W) chmax(dp[i + 1][wei2], dp[i][wei] + v[items[i]]);
	}

	int ans = -infl;
	rep(wei2, 0, W + 1) chmax(ans, dp[N][wei2]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ナップサック問題の派生であるが、追加されてる条件について考えてみる。
aとbを一緒に入れる必要があり、bとcも一緒に入れる必要があるとき、a,b,cはすべて一緒に入れる必要がある。
このように連結関係にあれば、すべて入れる必要があり、1つの荷物とみなすことができる。
よって、連結成分をUnionFindでまとめて、1つの荷物にしてからナップサック問題を解こう。

ナップサック問題はDPで解ける。
dp[i][wei] := i番目の荷物までを使って重さweiを作る時の合計価値の最大値
///////////////////////// writeup2 end */
