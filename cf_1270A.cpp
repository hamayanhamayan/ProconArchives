//https://codeforces.com/contest/1270/problem/A
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














int N, K1, K2, A[101], B[101];
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> N >> K1 >> K2;
	rep(i, 0, K1) cin >> A[i];
	rep(i, 0, K2) cin >> B[i];

	int ma1 = -1;
	rep(i, 0, K1) chmax(ma1, A[i]);
	int ma2 = -1;
	rep(i, 0, K2) chmax(ma2, B[i]);

	if (ma1 > ma2) cout << "YES" << endl;
	else cout << "NO" << endl;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
このゲームは最大のカードを持っている方が勝つ。
これは、最大のカードを持っている方が、最大のカードを出し続けることで連勝できるためである。
よって、両者持っているカードの最大値を持ってきて、大きいほうが勝ち。
///////////////////////// writeup2 end */
