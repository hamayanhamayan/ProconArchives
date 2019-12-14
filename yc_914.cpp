//https://yukicoder.me/problems/no/914
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














int N, M, K, A[10][10];
bool dp[11][501];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K;
	rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];

	rep(i, 0, N + 1) rep(k, 0, K + 1) dp[i][k] = false;
	dp[0][K] = true;
	rep(i, 0, N) rep(k, 0, K + 1) rep(j, 0, M) {
		if(0 <= k - A[i][j]) dp[i + 1][k - A[i][j]] |= dp[i][k];
	}

	int ans = K;
	rep(k, 0, K + 1) if (dp[N][k]) chmin(ans, k);
	if (ans == K) ans = -1;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
やりすぎ感があるが、DPしよう。
dp[i][k] := 国iまでお土産を買っていて、残りの金額がkである場合があるか
///////////////////////// writeup2 end */
