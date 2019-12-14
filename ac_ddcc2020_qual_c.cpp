//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c
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














int H, W, K;
string S[303];
int cnt[303];
//---------------------------------------------------------------------------------------------------
int ans[303][303];
int idx = 1;
void go(int sx, int tx) {
	vector<int> vy;
	rep(y, 0, H) {
		int sm = 0;
		rep(x, sx, tx + 1) if (S[y][x] == '#') sm++;
		if (0 < sm) vy.push_back(y);
	}
	int pre = 0;
	int ny = vy.size();
	rep(i, 0, ny - 1) {
		rep(y, pre, vy[i] + 1) rep(x, sx, tx + 1) ans[y][x] = idx;
		idx++;
		pre = vy[i] + 1;
	}
	rep(y, pre, H) rep(x, sx, tx + 1) ans[y][x] = idx;
	idx++;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> K;
	rep(y, 0, H) cin >> S[y];

	rep(y, 0, H) rep(x, 0, W) if (S[y][x] == '#') cnt[x]++;
	vector<int> vx;
	rep(x, 0, W) if (0 < cnt[x]) vx.push_back(x);

	int nx = vx.size();
	int pre = 0;
	rep(i, 0, nx - 1) {
		go(pre, vx[i]);
		pre = vx[i] + 1;
	}
	go(pre, W);

	rep(y, 0, H) {
		rep(x, 0, W) {
			if (x) printf(" ");
			printf("%d", ans[y][x]);
		}
		printf("\n");
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実装方針としては、まずは縦にスライスして、横にスライスする。

cnt[x] := x座標がxであるいちごの個数
これを数えておく。
基本は1列ごとにスライスしていくのだが、cnt[x]=0である列は、どこかに含めないと
いちごが入ってない長方形ができてしまう。
なので、いちごが無い列はいちごがある列にくっつける。
このように縦にスライスしていくと、1つ1つのグループは横にスライスすることで
ちょうど1個のいちごを含むようにできる。

go(sx, tx) := [sx,tx]列のケーキを横に切る
横に切る場合も縦に切る場合と同じく、いちごが無い行をいちごがある行にくっつけるようにして
分割していけばいい。
あとは、適当に順番をつけると答え。
///////////////////////// writeup2 end */
