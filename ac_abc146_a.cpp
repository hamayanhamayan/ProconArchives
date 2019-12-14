//https://atcoder.jp/contests/abc146/tasks/abc146_a
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














string S;
string week[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	rep(i, 0, 7) if (week[i] == S) {
		int ans = 7 - i;
		cout << ans << endl;
		return;
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
SUN,MON,TUE,WED,THU,FRI,SATを0,1,2,3,4,5,6と変換して考えてみよう。
すると、答えは7-S'となる。
文字列だと差を出しにくいので、数値に変換して考える。
///////////////////////// writeup2 end */
