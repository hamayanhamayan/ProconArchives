//https://atcoder.jp/contests/abc146/tasks/abc146_f
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
template<class V, int NV> struct LazySegTree { // [L,R)
	vector<V> dat, lazy; LazySegTree() { dat.resize(NV * 2, def); lazy.resize(NV * 2, ldef); }
	void update(int a, int b, V v, int k, int l, int r) {
		push(k, l, r); if (r <= a || b <= l) return;
		if (a <= l && r <= b) { setLazy(k, v); push(k, l, r); }
		else {
			update(a, b, v, k * 2 + 1, l, (l + r) / 2); update(a, b, v, k * 2 + 2, (l + r) / 2, r);
			dat[k] = comp(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	V get(int a, int b, int k, int l, int r) {
		push(k, l, r); if (r <= a || b <= l) return def;
		if (a <= l && r <= b) return dat[k]; auto x = get(a, b, k * 2 + 1, l, (l + r) / 2);
		auto y = get(a, b, k * 2 + 2, (l + r) / 2, r); return comp(x, y);
	}
	void update(int a, int b, V v) { update(a, b, v, 0, 0, NV); }
	V get(int a, int b) { return get(a, b, 0, 0, NV); }
	// ---- Template ---------------------------------------------------------------------------------
	// 区間min代入,区間min
	const V def = inf, ldef = inf;
	V comp(V l, V r) { return min(l, r); }
	void setLazy(int i, V v) { lazy[i] = min(lazy[i], v); }
	void push(int k, int l, int r) {
		if (lazy[k] != ldef) {
			// modify------------------------------
			dat[k] = min(dat[k], lazy[k]);
			// ------------------------------------
			if (r - l > 1) { setLazy(k * 2 + 1, lazy[k]); setLazy(k * 2 + 2, lazy[k]); }
			lazy[k] = ldef;
		}
	}
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














int N, M; string S;
LazySegTree<int, 1 << 17> lst;
vector<int> idx[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> S;

	lst.update(N, N + 1, 0);
	rrep(i, N, 0) if(S[i] == '0') {
		int mi = lst.get(i, i + 1);
		int l = max(0, i - M);
		lst.update(l, i, mi + 1);
	}
	
	if (lst.get(0, 1) == inf) {
		cout << -1 << endl;
		return;
	}

	rep(i, 0, N + 1) if (S[i] == '0') idx[lst.get(i, i + 1)].push_back(i);

	vector<int> ans;
	int cu = 0;
	int dp = lst.get(0, 1);
	while (cu < N) {
		int nxt = *upper_bound(all(idx[dp - 1]), cu);
		ans.push_back(nxt - cu);
		cu = nxt;
		dp--;
	}

	int n = ans.size();
	rep(i, 0, n) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
DPして復元する。
後ろからまずは最短手数になるようにDPしよう。
i番目のマスが0で最短距離がdp[i]であれば、dp[i-1]～dp[i-M]がdp[i]+1で更新される。
この区間min代入は遅延評価セグメントツリーで殴れる。
これで殴っとこう。

あとは、先頭から順番に一番近いその数の所を探してくればいい。
これは数毎に添字を持っておき、upper_boundとかで取ってくればいい。
///////////////////////// writeup2 end */
