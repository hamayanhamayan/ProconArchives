//https://codeforces.com/contest/1286/problem/A
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














int N, P[101];
int dp[105][105][2];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> P[i];

	int odd = 0, even = 0;
	rep(i, 0, N) if(0 < P[i]) {
		if (P[i] % 2 == 0) even++;
		else odd++;
	}

	int resteven = N / 2 - even;
	
	rep(i, 0, N + 1) rep(usedeven, 0, resteven + 1) rep(parity, 0, 2) dp[i][usedeven][parity] = inf;
	dp[0][0][0] = dp[0][0][1] = 0;

	int zeros = 0;
	rep(i, 0, N) {
		rep(usedeven, 0, resteven + 1) rep(parity, 0, 2) {
			if (0 < P[i]) {
				chmin(dp[i + 1][usedeven][P[i] % 2], dp[i][usedeven][parity] + (parity != P[i] % 2));
			}
			else {
				chmin(dp[i + 1][usedeven][1], dp[i][usedeven][parity] + (parity == 0));
				chmin(dp[i + 1][usedeven + 1][0], dp[i][usedeven][parity] + (parity == 1));
			}
		}
	}

	int ans = min(dp[N][resteven][0], dp[N][resteven][1]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
0に数を入れていくが、2で割った余りだけが関係あるので、0に入れるべき数で
偶数の個数をresteven, 奇数の個数をrestoddとして数えておこう。
あとは、これを適切に入れていく方針で考える。
これで状態をだいぶ抽象化して考えることができるようになる。
貪欲で行けそうな雰囲気もあるが、DPしよう。
dp[i][usedeven][parity] := i番目まで確定していて、restevenのうち、
usedeven個使っていて最後の数を2で割った余りがparityであるときのコスト最小値。
///////////////////////// writeup2 end */
