//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_d
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














int M, R;
int keys[4][3] = {
	{7, 8, 9}, 
	{4, 5, 6},
	{1, 2, 3},
	{0, -1, -1}
};
int dist[4][3][101010];
bool vis[4][3][101010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> M >> R;

	rep(y, 0, 4) rep(x, 0, 3) rep(mo, 0, M) dist[y][x][mo] = inf;

	queue<vector<int>> que;
	que.push({3, 0, 0});
	dist[3][0][0] = 0;

	while (!que.empty()) {
		auto v = que.front(); que.pop();

		int y = v[0];
		int x = v[1];
		int mo = v[2];

		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx and xx < 3 and 0 <= yy and yy < 4) {
				if (keys[yy][xx] < 0) continue;

				chmin(dist[yy][xx][mo], dist[y][x][mo] + 1);
				if (!vis[yy][xx][mo]) {
					vis[yy][xx][mo] = true;
					que.push({yy, xx, mo});
				}
			}
		}

		int mo2 = (mo * 10 + keys[y][x]) % M;
		chmin(dist[y][x][mo2], dist[y][x][mo] + 1);
		if (!vis[y][x][mo2]) {
			vis[y][x][mo2] = true;
			que.push({ y, x, mo2 });
		}
	}

	int ans = inf;
	rep(y, 0, 4) rep(x, 0, 3) chmin(ans, dist[y][x][R]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [幅優先探索](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
**30点**
mod 100000で固定されているが、例えばR=12345だった場合、
12345, 112345, 212345, 312345, ...とかが考えられる。
しかし、どの場合でも結局12345と打つ必要があるので、最短で12345、つまりRを実現するよう動けばいい。

**満点解法**
満点を取るには、網羅的に探索してやる必要がある。
すこし発想の飛躍があるので、下にヒントを書いておく。

- DPっぽい考えもできる。dp[位置][入力済みの数modM] := 最小コスト
- 更新順が問題となるが、DPで更新順が小さいものから確定させてくやつはダイクストラに方針転換する場合が多い
- 今回はコストが1なので、ダイクストラまで必要なく幅優先探索
- よって、今回の問題は適切に状態を作ると、グラフを構築して、最短距離に帰着できる

さて、まとめると、今回は、移動か入力かでコストが1かかるが、これを遷移に見立ててグラフを構築することができる。
頂点は(現在の位置, 入力済みの数をMで割った余り)で表現できる。
コストは全て1なので、幅優先探索で答えが求まる。
///////////////////////// writeup2 end */
