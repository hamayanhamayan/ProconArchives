//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d
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
#define def infl
template<class V, int NV> struct SegTree { //[l,r)
	V comp(V& l, V& r) { return min(l, r); };

	vector<V> val; SegTree() { val = vector<V>(NV * 2, def); }
	V get(int x, int y, int l = 0, int r = NV, int k = 1) {
		if (r <= x || y <= l)return def; if (x <= l && r <= y)return val[k];
		auto a = get(x, y, l, (l + r) / 2, k * 2);
		auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
		return comp(a, b);
	}
	void update(int i, V v) {
		i += NV; val[i] = v;
		while (i > 1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
	}
	void add(int i, V v) { update(i, val[i + NV] + v); }
	V operator[](int x) { return get(x, x + 1); }
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











int N, M;
vector<pair<int, int>> Q[101010];
SegTree<ll, 1 << 17> st;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int l, r, c; cin >> l >> r >> c;
		Q[r].push_back({ l, c });
	}

	st.update(1, 0);
	rep(r, 1, N + 1) {
		fore(p, Q[r]) {
			int l = p.first;
			int c = p.second;
			st.update(r, min(st[r], st.get(l, r) + c));
		}
	}
	ll ans = st[N];
	if (ans == infl) ans = -1;
	cout << ans << endl;
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
本家解答はダイクストラ。
以下、セグメントツリーとDPによる解答を示す。

区間条件と最短経路といえば、Rを昇順に処理していって、DPをセグメントツリーで高速化テク。
この方針で考えていくと解けそうになってくる。
dp[i] := 頂点iに到着する為の最短経路
区間をR昇順でソートして、順番にDPを更新していく。
dp[R] = min(dp[R], min(dp[L], dp[L+1], ..., dp[R]) + C)
これで更新していけばいい。

更新先が頂点Rだけで良い理由を説明する。
区間[L1,R1]を使って移動した後に、区間[L2,R2]を使って移動するためには、
[L2,R2]の中にR1が入っているかだけを考えればいい。
よって、区間[L1,R1]を使って移動してきたという情報を頂点R1だけに伝播させれば、
直前の移動情報を正しく、かつ、まとめて保持しておくことができる。
それっぽく説明したけど、後付なので謎理論かも。

あとは、dp[N]が答え。
///////////////////////// writeup2 end */
