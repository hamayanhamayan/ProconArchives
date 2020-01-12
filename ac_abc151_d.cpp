//https://atcoder.jp/contests/abc151/tasks/abc151_d
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














int H, W;
string S[20];
//---------------------------------------------------------------------------------------------------
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
vector<vector<int>> bfs(int sx, int sy) {
	queue<pair<int, int>> que;
	vector<vector<int>> res(H, vector<int>(W, inf));
	vector<vector<bool>> vis(H, vector<bool>(W, false));

	res[sy][sx] = 0;
	vis[sy][sx] = true;
	que.push({ sx, sy });

	while (!que.empty()) {
		int x, y;
		tie(x, y) = que.front();
		que.pop();

		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx and xx < W and 0 <= yy and yy < H) {
				if (S[yy][xx] != '#' and !vis[yy][xx]) {
					res[yy][xx] = res[y][x] + 1;
					vis[yy][xx] = true;
					que.push({xx, yy});
				}
			}
		}
	}

	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> S[y];

	int ans = 0;
	rep(sx, 0, W) rep(sy, 0, H) if(S[sy][sx] != '#') {
		auto res = bfs(sx, sy);
		rep(x, 0, W) rep(y, 0, H) if (S[y][x] != '#') chmax(ans, res[y][x]);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [BFSによる最短経路](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
制約を見るとかなり小さい。
なので、なるべく全探索できるものは、全探索していこう。
任意の二点間の最短距離の最大値を求めるが、任意の二点間の全探索を考えよう。
この段階で、20^4くらいの組み合わせがある。

二点間の最短距離を求めるには、BFSでO(WH)で行うことができるので、これを毎回やると、
20^6くらいが計算量となる。
これは、間に合うだろうか。
16*10^6なので、正直間に合う気もする。

が、ちょっと心配なので、もう少し工夫することを考える。
BFSによる最短距離で求めることができるのは、ある点を始点としたときの他のすべての点の最短距離である。
よって、任意の二点間を全探索するのではなく、始点のみ全探索すれば、BFSすることで全ての終点が見られる。
なので、始点だけ全探索すればいい。
これで20^4くらいに計算量が落ちるので、十分間に合う。
///////////////////////// writeup2 end */
