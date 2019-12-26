//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d
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














int N;
string S[5];
int dp[1010][5];
map<char, int> dic = {
	{'R', 0},
	{'B', 1},
	{'W', 2},
	{'#', 3}
};
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, 5) cin >> S[i];

	rep(i, 0, N + 1) rep(lst, 0, 5) dp[i][lst] = inf;
	dp[0][4] = 0;

	rep(i, 0, N) rep(lst, 0, 5) if (dp[i][lst] < inf) {
		rep(nxt, 0, 3) if (lst != nxt) {
			int cst = 0;
			rep(j, 0, 5) if (dic[S[j][i]] != nxt) cst++;
			chmin(dp[i + 1][nxt], dp[i][lst] + cst);
		}
	}

	int ans = inf;
	rep(lst, 0, 3) chmin(ans, dp[N][lst]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ここから競技プログラミングになれていないと、満点解答を狙うには難しいかもしれない。
さて、なれている諸君は動的計画法がぽっとでてくるだろう。
自分は「最小値を求める」という所から動的計画法かもと思ってちょっと考えるとそうだったパターンである。

DPは、
dp[i][lst] := i列目まで塗り替えが完了していて、最後の色がlstである組み合わせ
で作る。
dp[i][lst] -> dp[i + 1][lst]の遷移以外を行う。
最初はどの色でもいいので、R,B,W,#を0,1,2,3として、何でも良い4を初期値としておこう。
dp[0][4] = 0, dp[他][他]=∞
///////////////////////// writeup2 end */
