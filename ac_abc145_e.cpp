//https://atcoder.jp/contests/abc145/tasks/abc145_e
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














int N, T;
int A[3010], B[3010];
pair<ll, int> dp[3010][3010];
//---------------------------------------------------------------------------------------------------
pair<ll, int> max(pair<ll, int> a, pair<ll, int> b) {
	if (a.first + a.second == b.first + b.second) {
		if (a.first > b.first) return a;
		return b;
	}

	if (a.first + a.second > b.first + b.second) return a;
	return b;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> T;
	rep(i, 0, N) cin >> A[i] >> B[i];

	rep(i, 0, N + 1) rep(t, 0, T + 1) dp[i][t] = { -infl, 0 };
	dp[0][0] = { 0, 0 };

	rep(i, 0, N) rep(t, 0, T + 1) if(0 <= dp[i][t].first) {
		dp[i + 1][t] = max(dp[i + 1][t], { dp[i][t].first, max(dp[i][t].second, B[i]) });
		if (t + A[i] <= T) {
			dp[i + 1][t + A[i]] = max(dp[i + 1][t + A[i]], {
				dp[i][t].first + B[i],
				dp[i][t].second
				});
		}
	}

	ll ans = 0;
	rep(t, 0, T) chmax(ans, dp[N][t].first + dp[N][t].second);
	chmax(ans, dp[N][T].first);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
よくあるDPを考えると、
DP[i][t] := i番目までを注文して今までt分経過しているときの満足度の最大値
っぽいが、最後に時間を超えて食べられるというのが難しい。
DP[i][t] := (i番目までを注文して今までt分経過しているときの満足度の最大値, 食べなかった料理の最大値)
これでできそうか？
大小の比較は、pairとしての比較ではなく、合計で比較すればよさそう。
今までに見たことがない形。
祈って出すと通る。
///////////////////////// writeup2 end */
