//https://atcoder.jp/contests/past202004-open/tasks/past202004_h
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














int H, W; string A[50];
const int MA = 50 * 50 * 15;
int mi[50][50][15];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
int enc(int x, int y, int state) {
	return state * H * W + y * W + x;
}
// {x, y, state}
tuple<int, int, int> dec(int id) {
	return make_tuple(id % W, (id % (H * W)) / W, id / (H * W));
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> A[y];

	queue<int> que;
	rep(y, 0, H) rep(x, 0, W) rep(state, 0, 10) mi[y][x][state] = -1;
	rep(y, 0, H) rep(x, 0, W) if (A[y][x] == 'S') {
		que.push(enc(x, y, 0));
		mi[y][x][0] = 0;
	}

	while (!que.empty()) {
		int q = que.front(); que.pop();
		int x, y, state;
		tie(x, y, state) = dec(q);

		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx && xx < W && 0 <= yy && yy < H) {
				if (mi[yy][xx][state] < 0) {
					mi[yy][xx][state] = mi[y][x][state] + 1;
					que.push(enc(xx, yy, state));
				}

				if (A[yy][xx] == char('1' + state)) {
					if (mi[yy][xx][state + 1] < 0) {
						mi[yy][xx][state + 1] = mi[y][x][state] + 1;
						que.push(enc(xx, yy, state + 1));
					}
				}
			}
		}
	}

	rep(y, 0, H) rep(x, 0, W) if (A[y][x] == 'G') {
		cout << mi[y][x][9] << endl;
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
この問題は類題を解いていないといきなり解くのは難しいだろう。
SからGへの最短距離なので、盤面上の最短距離の典型手法であるBFSを使う解法で考えてみる。
考えてみると、適用可能であることに気づくので解ける。

盤面上の最短距離では、「mi[y][x] := (x,y)へ到達するための最短距離」をqueueを使って求めていけばいい。
だが、今回はS->1->2->...->9->Gという決まった経路を通る必要がある。
これをどうやって表現しようか。
マス目を歩いている人の『状態』を考えてみると、もう1までは通ったとか、もう8までは通ったとか、
どこまでは通ったかを考えながら移動を進めていくだろう。
なので、どの数まで通ったかというのも状態に含める。
mi[y][x][state] := (x,y)にいて、最後にstateの数まで通っている状態の最短距離
これをbfsを使って最短経路を求めていけばGのマスが(gx, gy)なら、dp[gy][gx][9]が答え。
///////////////////////// writeup2 end */
