//https://yukicoder.me/problems/no/920
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














int X, Y, Z;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X >> Y >> Z;
	int ans = -1;
	rep(dr, 0, Z + 1) {
		int red = X + dr;
		int blue = Y + (Z - dr);
		chmax(ans, min(red, blue));
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
XYZの制約が小さいので、個数で全探索できそう。
白色のボールが何個赤色になるかを全探索しよう。
赤にならない白ボールは青にすればいい。
あとは、紫色のボールはmin(赤ボール, 青ボール)だけ作れるので、
それの最大値が答え。
///////////////////////// writeup2 end */
