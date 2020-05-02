//https://yukicoder.me/problems/no/1041
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














int N, X[101], Y[101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> X[i] >> Y[i];

	int ans = 2;
	rep(a, 0, N) rep(b, a + 1, N) {
		int dx = X[a] - X[b];
		int dy = Y[a] - Y[b];

		int cnt = 0;
		rep(i, 0, N) {
			int dx2 = X[a] - X[i];
			int dy2 = Y[a] - Y[i];

			if (dy * dx2 == dy2 * dx) cnt++;
		}
		chmax(ans, cnt);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
考えられる直線は無限にあるのだが、最大個数の点を通すであろう直線に絞って考える。
最大個数の点を通すであろう直線は少なくとも2点は通っている直線であることが言える。
なので、この直線を全探索することにしよう。
点を2つ選ぶ選んで、a,bとする。

あとは、この2点を結んだ時の直線に何個の点が乗っているかの計算であるが、傾きを使用しよう。
直線ab上に点iがあるためには、直線abと直線aiの傾きが同じであればいい。
これを頑張って計算する。
直線abの傾きをdy/dx, 直線aiの傾きをdy2/dx2とする。
差分は普通に計算するとして、`dy/dx==dy2/dx2`を判定したいが、一般に分数で比較するのは危ない。
なので、両辺に×dx×dx2をして、`dy×dx2==dy2×dx`としておいて、この等式を満たすかどうかで判定しよう。
満たすなら個数cntをインクリメントする。

それぞれの直線についてcntを求め最大値を求めると答え。
O(N^3)で間に合う。
オーダーでは10^7くらいが目安であり、今回は10^6なので、まあ大丈夫。
///////////////////////// writeup2 end */
