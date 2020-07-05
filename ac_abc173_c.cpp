//https://atcoder.jp/contests/abc173/tasks/abc173_c
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














int H, W, K;
string c[6];
string c2[6];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> K;
	rep(y, 0, H) cin >> c[y];

	int ans = 0;
	rep(mskH, 0, 1 << H) rep(mskW, 0, 1 << W) {
		rep(y, 0, H) c2[y] = c[y];
		rep(y, 0, H) if (mskH & (1 << y)) rep(x, 0, W) c2[y][x] = 'R';
		rep(x, 0, W) if (mskW & (1 << x)) rep(y, 0, H) c2[y][x] = 'R';

		int cnt = 0;
		rep(x, 0, W) rep(y, 0, H) if (c2[y][x] == '#') cnt++;
		if (cnt == K) ans++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実装問題であるが、bit全探索の書き方を知らない場合は解くのは難しいだろう。
どこかで勉強してから、この問題に戻ってくること。

この行と列の選び方は実は全探索可能である。
H=W=6の最大ケースで試しても、選び方は2^12通り。
これは4000通りくらいなので、bit全探索を使って全探索しよう。
あとは、選ばれた行と列は赤色で塗りつぶして、黒色部分をカウントしてK個なら答えをインクリメントするといい。
///////////////////////// writeup2 end */
