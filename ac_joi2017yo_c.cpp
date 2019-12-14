//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_c
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














int H, W, D;
string B[101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> D;
	rep(y, 0, H) cin >> B[y];

	int ans = 0;

	// 右
	rep(y, 0, H) rep(x, 0, W - D + 1) {
		int cnt = 0;
		rep(xx, x, x + D) if (B[y][xx] == '.') cnt++;
		if (cnt == D) ans++;
	}

	// 下
	rep(x, 0, W) rep(y, 0, H - D + 1) {
		int cnt = 0;
		rep(yy, y, y + D) if (B[yy][x] == '.') cnt++;
		if (cnt == D) ans++;
	}

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
重複なく数えるために、かぶらないような特徴を見つけることが大切である。
今回で言えば、休憩スペースの左上端とする座標について考え、そこを全探索する。
全探索した座標から右にDマス分に機材がなければ、そこに設けることができる。
座標の全探索で既に10^4通りくらいあり、右にマスを見ていってD個分空白になっていれば、答えとしてカウントする。
同様に下に見た場合も考えて、答えについて和を取ると答え。
///////////////////////// writeup2 end */
