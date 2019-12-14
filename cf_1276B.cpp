//https://codeforces.com/contest/1276/problem/B
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
    vector<int> par;
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, A, B;
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> N >> M >> A >> B;
	if (A > B) swap(A, B);
	A--; B--;
	
	UnionFind uf(N);
	vector<int> va, vb;
	vector<int> flag(N);
	int FA = 0x01;
	int FB = 0x02;

	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		if (a > b) swap(a, b);

		if (a == A and b == B) continue;
		else if (a == A) va.push_back(b);
		else if (a == B) vb.push_back(b);
		else if (b == A) va.push_back(a);
		else if (b == B) vb.push_back(a);
		else uf(a, b);
	}
	
	fore(i, va) flag[uf[i]] |= FA;
	fore(i, vb) flag[uf[i]] |= FB;

	ll ta = 0, tb = 0;
	rep(i, 0, N) {
		if (flag[uf[i]] == FA) ta++;
		if (flag[uf[i]] == FB) tb++;
	}

	ll ans = ta * tb;
	printf("%lld\n", ans);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
あるx,yについて全ての経路でa,bを通るということは、
頂点a,bを抜くとxからyに到達不可能になるということ。
よって、頂点a,bを抜いた状態で考えてみよう。
頂点a,bを抜いて、unionfindで連結成分をまとめよう。
この連結成分毎に頂点aにつながっているか、bにつながっているか、どちらにもつながっているかを判定する。
求めたい経路はx→a→b→yであるため、頂点aにのみつながっている頂点数×頂点bにのみつながっている頂点数をすると答え。
///////////////////////// writeup2 end */
