//https://atcoder.jp/contests/past202004-open/tasks/past202004_k
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













int N; string S; int C[3010], D[3010];
ll dp[3010][3010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;
	rep(i, 0, N) cin >> C[i];
	rep(i, 0, N) cin >> D[i];

	rep(i, 0, N + 1) rep(diff, 0, N + 1) dp[i][diff] = infl;
	dp[0][0] = 0;

	rep(i, 0, N) rep(diff, 0, N) {
		int d = 0;
		if (S[i] == '(') d = 1;
		else d = -1;

		// stay
		if (0 <= diff + d) chmin(dp[i + 1][diff + d], dp[i][diff]);

		// flip
		if (0 <= diff - d) chmin(dp[i + 1][diff - d], dp[i][diff] + C[i]);

		// erase
		chmin(dp[i + 1][diff], dp[i][diff] + D[i]);
	}

	cout << dp[N][0] << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
どことなく問題が編集距離のDPに似ている。
類題を解いたことがあるので、以下のDPが思いつくが、0から思いつくのは厳しい所があるかもしれない。
それかかっこは「diff=`(の個数`-`)の個数`」で考えるのが、典型方針であるので、そこから思いついてもいいかもしれない。
dp[i][diff] := i文字目まで見終わっていて、これまでのかっこ列についてdiff=`(の個数`-`)の個数`である最小コスト
行える操作としては、そのままにしておくか（stay）、反転させるか(flip)、削除するか（erase）の3択なので、
計算自体はO(N^2)で間に合う。
///////////////////////// writeup2 end */
