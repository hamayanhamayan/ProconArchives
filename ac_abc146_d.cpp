//https://atcoder.jp/contests/abc146/tasks/abc146_d
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N;
vector<pair<int,int>> E[101010];
//---------------------------------------------------------------------------------------------------
int ans[101010];
void dfs(int cu, int pa = -1, int col = 0) {
	set<int> used;
	used.insert(col);
	int c = 1;
	fore(to, E[cu]) if (to.first != pa) {
		while (used.count(c)) c++;
		ans[to.second] = c;
		dfs(to.first, cu, c);
		c++;
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;

		E[a].push_back({ b, i });
		E[b].push_back({ a, i });
	}

	dfs(0);

	int ma = 0;
	rep(i, 0, N) chmax(ma, (int)E[i].size());
	printf("%d\n", ma);
	rep(i, 0, N - 1) printf("%d\n", ans[i]);

}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
貪欲に色を決めて塗っていけば達成できそう。
根を1つ決めて貪欲に色を塗っていく。
あとは、実装を頑張る。
各頂点で必要な色は次数と一致するので、次数が最大の所から順番に塗っていくのも手ではある。
（実装は変わらないか）
///////////////////////// writeup2 end */
