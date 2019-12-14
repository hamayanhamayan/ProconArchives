//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_f
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














int H, W;
string B[1010];
int dp[1010][1010][2][2][2][2];
enum { UP = 0, RIGHT, DOWN, LEFT };
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(x, 0, W + 2) B[0] += ".";
	rep(x, 0, W + 2) B[W+1] += ".";
	rep(y, 1, H + 1) {
		string s; cin >> s;
		B[y] = "." + s + ".";
	}

	rep(y, 0, H + 2) rep(x, 0, W + 2) rep(xp1ym1, 0, 2) rep(xp1y, 0, 2) rep(xm1yp1, 0, 2) rep(xyp1, 0, 2) {
		dp[y][x][xp1ym1][xp1y][xm1yp1][xyp1] = inf;
	}
	dp[1][1][0][0][0][0] = 0;

	rep(y, 1, H + 1) rep(x, 1, W + 1) rep(xp1ym1, 0, 2) rep(xp1y, 0, 2) rep(xm1yp1, 0, 2) rep(xyp1, 0, 2) {
		if (dp[y][x][xp1ym1][xp1y][xm1yp1][xyp1] == inf) continue;
		int tot = -1, cur = 0;

		// dp[y][x+1]
		tot = 0;
		cur = 0;
		if (B[y][x + 1] != '.') cur = B[y][x + 1] - '0';
		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + 1 + dy[d];

			if (d == LEFT) continue;
			if (d == UP and xp1ym1) continue;
			if (B[yy][xx] != '.') tot += B[yy][xx] - '0';
		}
		if (tot == 0) {
			chmin(dp[y][x + 1][0][0][xyp1][0], dp[y][x][xp1ym1][xp1y][xm1yp1][xyp1] + cur);
		}
		else {
			rep(d, 0, 4) {
				int xx = x + dx[d];
				int yy = y + 1 + dy[d];

				if (d == LEFT) continue;
				if (d == UP and xp1ym1) continue;
				if (B[yy][xx] != '.') {
					int tot2 = tot - (B[yy][xx] - '0');
					chmin(dp[y][x + 1][0][d == RIGHT][xyp1][0], dp[y][x][xp1ym1][xp1y][xm1yp1][xyp1] + cur);
				}
			}
		}
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
区間の制約と→か↓しか移動できないという所から、DPで解く雰囲気がすごくする。
dp[y][x] := マス(x,y)にいる時に買ったお菓子の総額の最小値
だが、これだけでは隣接する区間でお菓子を買う時に困る。
よって、それに必要な情報も入れ込んでおこう。

遷移から、必要な情報を考えてみる。
(x,y)から(x+1,y)であれば、(x+1,y-1)の情報はほしい。
(x+1,y+1)とかは、→↓の遷移だと影響を及ぼせないので、いらない。
(x,y)から(x,y+1)であれば、(x-1,y+1)の情報はほしい。
加えて、遷移後に(x+1,y-1)と(x-1,y+1)を得るには(x+1,y)と(x,y+1)が無いと作れない。
よって、(x,y)については(x+1,y-1),(x+1,y),(x-1,y+1),(x,y+1)が取ったか取ってないかフラグを作る。
dp[y][x][xp1ym1][xp1y][xm1yp1][xyp1]として、遷移させよう。
状態空間の指定だけでも大変なのに境界を考えるのはもっと大変なので、前処理として、周りに'.'を敷き詰めておこう。
これでdp[1][1][false][false][false][false]からdp[H][W]へ遷移させて、dp[H][W]の最小値が答え。
///////////////////////// writeup2 end */
