//https://atcoder.jp/contests/past201912-open/tasks/past201912_g
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[10][10];
//---------------------------------------------------------------------------------------------------
int ans = -inf;
vector<int> grp[3];
void dfs(int cu = 0, int tot = 0) {
	if (cu == N) {
		chmax(ans, tot);
		return;
	}
	rep(g, 0, 3) {
		int d = 0;
		fore(i, grp[g]) d += A[i][cu];
		grp[g].push_back(cu);
		dfs(cu + 1, tot + d);
		grp[g].pop_back();
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) rep(j, i + 1, N) {
		cin >> A[i][j];
		A[j][i] = A[i][j];
	}

	dfs();
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
競技プログラミング的なやりかたで解決する。
3つ以下のグループに分けるので、全てのやり方を試してもO(3^N)である。
bit全探索っぽくやってもいいし、dfsでやってもいい。
dfsが楽かも。
///////////////////////// writeup2 end */
