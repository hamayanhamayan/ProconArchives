//https://yukicoder.me/problems/no/1042
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
#define EPS 1e-7
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














int P, Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> P >> Q;
	double ok = 1, ng = 1e12;
	rep(i, 0, 1010) {
		double md = (ok + ng) / 2;

		if (md * md <= P + 1.0 * Q * md * log2(md) + EPS) ok = md;
		else ng = md;
	}
	printf("%.10f\n", ok);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
///////////////////////// writeup2 start
`N^2 <= P + QNlogN`を満たす最大のNを求めよという問題。
★の感じから二分探索すればよさそう。
普通に二分探索する。
テクニックとして小数の比較にはEPSを使うのが定石。
今回はA≦Bを判定するが、小数の場合はA≦B+EPSで比較をしよう。

自分は[1,1e9]でEPS=1e-10をするとWAになった。
うーんと思って、適当に[1,1e12],EPS=1e-7にしたら通った。
こういう適当なことをしているからレートが上がらないんだな。
///////////////////////// writeup2 end */
