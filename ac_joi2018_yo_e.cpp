//https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_e
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














int H, W, A[40][40];
int dp[40][40][1010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];

	rep(y, 0, H) rep(x, 0, W) rep(d, 0, H * W) dp[x][y][d] = inf;
	dp[0][0][0] = 0;

	rep(d, 0, H * W) rep(x, 0, W) rep(y, 0, H) {
		rep(di, 0, 4) {
			int xx = x + dx[di];
			int yy = y + dy[di];
			if (0 <= xx and xx < W and 0 <= yy and yy < H) {
				int c = dp[x][y][d] + A[yy][xx] * (1 + 2 * d);
				chmin(dp[xx][yy][d + 1], c);
			}
		}
	}

	int ans = inf;
	rep(d, 0, H * W) chmin(ans, dp[W - 1][H - 1][d]);
	cout << ans << endl;
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
