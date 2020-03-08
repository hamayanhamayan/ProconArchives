//https://atcoder.jp/contests/abc158/tasks/abc158_c
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














int A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B;
	rep(x, 1, 10001) {
		int a = x * 8 / 100;
		int b = x * 10 / 100;
		if (a == A && b == B) {
			cout << x << endl;
			return;
		}
	}
	cout << -1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
A,Bは100以下である。8%して100なので、税抜き価格は雑にやると100倍くらいになる。
よって、10000以下で全探索すれば答えが存在すれば見つけることができる。
税抜き価格xから消費税を計算する場合は、例えば8%であれば、x*0.08をすればいいのだが、
最終的には小数点以下は切り捨てるし、小数を介するのは、誤差とかがちょっと怖い。
なので、x*8をして、100で割ることで整数上で正確に切り捨てを計算することができる。

あとは、同じか判定して条件を満たせばxを答える。
ループ抜けたら答えがないので、-1を答える。
///////////////////////// writeup2 end */
