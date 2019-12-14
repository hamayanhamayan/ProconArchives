//https://yukicoder.me/problems/no/561
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














int N, D, C[101][2];
ll dp[101][2];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> D;
	rep(i, 0, N) rep(place, 0, 2) cin >> C[i][place];
	
	rep(i, 0, N + 1) rep(place, 0, 2) dp[i][place] = -infl;
	dp[0][0] = 0;
	rep(i, 0, N) rep(place, 0, 2) if(dp[i][place] != -infl) rep(nxt, 0, 2) {
		ll dp2 = dp[i][place] + C[i][nxt];
		if (place != nxt) dp2 -= D;
		chmax(dp[i + 1][nxt], dp2);
	}
	ll ans = -infl;
	rep(place, 0, 2) chmax(ans, dp[N][place]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
