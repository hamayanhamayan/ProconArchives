//https://yukicoder.me/problems/no/1037
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














int N, V, L;
ll dp[2020][2020];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> V >> L;
	rep(i, 0, N + 1) rep(rest, 0, V + 1) dp[i][rest] = infl;
	dp[0][V] = 0;

	int pos = 0;
	rep(i, 0, N) {
		int x, v, w;
		cin >> x >> v >> w;
		rep(rest, 0, V + 1) if(x - pos <= rest) {
			chmin(dp[i + 1][rest - (x - pos)], dp[i][rest]);
			chmin(dp[i + 1][min(V, rest - (x - pos) + v)], dp[i][rest] + w);
		}
		pos = x;
	}

	ll ans = infl;
	rep(rest, 0, V + 1) if (L - pos <= rest) chmin(ans, dp[N][rest]);
	if (ans == infl) ans = -1;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
