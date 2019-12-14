//https://atcoder.jp/contests/abc138/tasks/abc138_f
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














ll L, R;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> L >> R;

	ll ans = 0;
	rep(x, L, R + 1) rep(y, x, R + 1) {
		int a = 0; int xx = x; while (0 < xx) xx /= 2, a++;
		int b = 0; int yy = y; while (0 < yy) yy /= 2, b++;
		if ((y & x) == x and a == b) ans++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
剰余に対してビットで何か使えそうな性質が思いつかないので、なんらかの性質がないと解くのは難しい。
なので、実験しよう。
実験してみると、x & y == xであることが言えそう。
これでとりあえずサンプル2をやってみると、ちょっと数えすぎている。
大き目のケースで眺めてみると、最大ビットの部分が重要そう。
「xとyとで1になっている最大ビット位置が等しい」であることも必要そう。
これでサンプル2がとりあえず合う。
なので、大丈夫そう。

あとは、「x & y == x」「xとyとで1になっている最大ビット位置が等しい」を満たすx,yの組み合わせを求める。
これもこれで大変そうだ。
ビット系の数え上げは桁DPっぽいことをよくする。
dp[idx][isTop][L<=x][y<=R][x<=y]
これでできそう。
各ビットで(x,y)=(0,0),(0,1),(1,1)と割り当てていけばいい。
これをやるとx<=yは自ずと満たせるので、
dp[idx][isTop][L<=x][y<=R]
で計算を進めていく。
ここまではスムーズにいくかもしれないが、遷移は一筋縄ではいかないだろう。
///////////////////////// writeup2 end */