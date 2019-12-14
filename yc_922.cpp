//https://yukicoder.me/problems/no/922
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














int N, M, Q;
vector<int> E[101010];
//---------------------------------------------------------------------------------------------------
vector<pair<int, int>> plan;
ll solve1() {
	
}
//---------------------------------------------------------------------------------------------------
int cnt[101010];
ll solve2() {

}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> Q;
	UnionFind uf(N);
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
		uf(a, b);
	}

	rep(q, 0, Q) {
		int a, b; cin >> a >> b;
		a--; b--;
		if (uf[a] == uf[b]) plan.push_back({ a,b });
		else cnt[a]++, cnt[b]++;
	}

	ll ans = solve1() + solve2();
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
移動予定の中で同じ連結成分にあるものは最短距離を加えておく。
違う連結成分にあるものについてのみ、以降は考える。

連結成分Aに属す頂点aから連結成分Bに属す頂点bへ移動することを考える。
このときの距離は、(頂点a→成分Aの空港)+(成分Bの空港→頂点b)となる。
距離は逆にしても変わらないので、(頂点a→成分Aの空港)+(頂点b→成分Bの空港)である。
これを全ての移動予定について考えると、全ての移動予定を達成するために移動する距離の総和と
全ての成分について(成分Aに属しているuiかvi→成分Aの空港の距離の総和)の総和をとったものが等しくなる。
よって、全ての成分について、そこに属すuiかviからの距離の総和が最小となる頂点を探す問題に帰着する。

これは、全方位木DPで達成できる。
///////////////////////// writeup2 end */
