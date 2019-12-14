//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_c
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














int X;
bool dp[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X;
	dp[0] = true;
	rep(x, 0, X) if(dp[x]) rep(d, 0, 6) dp[x + d + 100] = true;

	if (dp[X]) cout << "1" << endl;
	else cout << "0" << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [yes/no系動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
品物は10^6個あるので、足りなくなることはない。
DPしよう。yes/noのDPをする。
dp[x] := ちょうどx円となる買い物ができるか
遷移は6通りなので、できる。
///////////////////////// writeup2 end */
