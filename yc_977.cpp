//https://yukicoder.me/problems/no/977
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
struct BridgeSCC {
	int NV = 0, time; vector<vector<int> > E; vector<int> ord, llink, inin;
	stack<int> roots, S; vector<int> M, ART; vector<vector<int> > SC; vector<pair<int, int> > BR;
	void init(int NV) { this->NV = NV; E.clear(); E.resize(NV); }
	void add_edge(int x, int y) { assert(NV); E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur, int pre) {
		int art = 0, conn = 0, i, se = 0; ord[cur] = llink[cur] = ++time;
		S.push(cur); inin[cur] = 1; roots.push(cur); rep(i, 0, E[cur].size()) {
			int tar = E[cur][i];
			if (ord[tar] == 0) {
				conn++; dfs(tar, cur); llink[cur] = min(llink[cur], llink[tar]);
				art += (pre != -1 && ord[cur] <= llink[tar]);
				if (ord[cur] < llink[tar]) BR.push_back(make_pair(min(cur, tar), max(cur, tar)));
			}
			else if (tar != pre || se) {
				llink[cur] = min(llink[cur], ord[tar]);
				while (inin[tar] && ord[roots.top()] > ord[tar]) roots.pop();
			}
			else se++;
		}
		if (cur == roots.top()) {
			SC.push_back(vector<int>()); while (1) {
				i = S.top(); S.pop(); inin[i] = 0; SC.back().push_back(i); M[i] = SC.size() - 1;
				if (i == cur) break;
			}sort(SC.back().begin(), SC.back().end()); roots.pop();
		}
		if (art || (pre == -1 && conn > 1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(), BR.clear(), ART.clear(), M.resize(NV); ord.clear(), llink.clear(), inin.clear();
		time = 0; ord.resize(NV); llink.resize(NV); inin.resize(NV);
		for (int i = 0; i < NV; i++) if (!ord[i]) dfs(i, -1);
		sort(BR.begin(), BR.end()); sort(ART.begin(), ART.end());
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














int N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;

	UnionFind uf(N);
	BridgeSCC scc; scc.init(N);

	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		uf(a, b);
		scc.add_edge(a, b);
	}

	scc.scc();

	int cnt = 0;
	rep(i, 0, N) if (uf[i] == i) cnt++;
	if (0 < scc.BR.size()) cnt++;

	if (3 <= cnt) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [UnionFind](https://www.hamayanhamayan.com/entry/2017/10/04/101826)
- [二重辺連結成分分解](https://www.hamayanhamayan.com/entry/2016/10/18/123552)
///////////////////////// writeup2 start
Aliceは連結成分を最大1つ増やすことができるし、Bobは連結成分を最大1つ減らすことができる。
Bobが連結成分をへらすことができない条件は連結成分が1つであることだけなので、基本的にはできる。
Aliceが勝つためには、Bobの手番の時に連結成分が3つ以上ある場面を作ることが要求される。
それ以外ならBobがくっつけて勝てる。

Aliceが適切な操作を行って、連結成分を3つ以上にできるかを判定しよう。
ある辺を削除した時に、連結成分が増える辺のことを「橋」という。
よって、橋が存在するなら連結成分を+1することができるし、なければできない。
解法としては「UnionFindで連結成分の数を計算→二重辺連結成分分解を行い橋を検出」を行う。
橋の検出に二重辺連結成分分解がやりすぎかもしれないが、ライブラリ貼るだけなので採用した。
///////////////////////// writeup2 end */
