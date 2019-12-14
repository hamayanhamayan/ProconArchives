//http://codeforces.com/contest/1236/problem/E
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














int N, M;
int to_up[101010];
int to_down[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;

	if (N == 1) {
		cout << 0 << endl;
		return;
	}

	UnionFind uf_up(N);
	UnionFind uf_down(N);
	map<int, vector<int>> dic_up, dic_down;
	int offset_up = 0;
	int offset_down = 0;

	rep(i, 0, N) {
		to_up[i] = i + 1;
		dic_up[i + 1].push_back(i);
		to_down[i] = i + 1;
		dic_down[i + 1].push_back(i);
	}

	rep(_, 0, M) {
		int a; cin >> a;
		
		offset_up++;
		if (0 < dic_up[a - offset_up].size()) {
			int i = dic_up[a - offset_up][0];
			dic_up[a - offset_up].pop_back();

			if (0 < dic_up[a - offset_up - 1].size()) {
				int j = dic_up[a - offset_up - 1][0];
				dic_up[a - offset_up - 1].pop_back();

				uf_up(i, j);
			}

			dic_up[a - offset_up - 1].push_back(uf_up[i]);
			to_up[uf_up[i]] = a - offset_up - 1;
		}

		offset_down++;
		if (0 < dic_down[a + offset_down].size()) {
			int i = dic_down[a + offset_down][0];
			dic_down[a + offset_down].pop_back();

			if (0 < dic_down[a + offset_down + 1].size()) {
				int j = dic_down[a + offset_down + 1][0];
				dic_down[a + offset_down + 1].pop_back();

				uf_down(i, j);
			}

			dic_down[a + offset_down + 1].push_back(uf_down[i]);
			to_down[uf_down[i]] = a + offset_down + 1;
		}
	}

	offset_up++;
	offset_down++;

	ll ans = 0;
	rep(i, 0, N) {
		int L = max(1, to_down[uf_down[i]] - offset_down);
		int R = min(N, to_up[uf_up[i]] + offset_up);
		ans += R - L + 1;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
