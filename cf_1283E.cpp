//https://codeforces.com/contest/1283/problem/E
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














int N, A[201010];
//---------------------------------------------------------------------------------------------------
int dp[201010];
int solve1() {
	vector<int> v;
	rep(i, 0, N) v.push_back(A[i]);
	v.erase(unique(all(v)), v.end());
	int n = v.size();

	rep(i, 0, n + 1) dp[i] = inf;
	dp[0] = 0;
	rep(i, 0, n) {
		chmin(dp[i + 1], dp[i] + 1);
		if (i + 1 < n) {
			if(v[i + 1] - v[i] <= 2) chmin(dp[i + 2], dp[i] + 1);
		}
		if (i + 2 < n) {
			if (v[i + 2] - v[i] <= 2) chmin(dp[i + 3], dp[i] + 1);
		}
	}
	return dp[n];
}
//---------------------------------------------------------------------------------------------------
int solve2() {
	map<int, int> cnt;
	rep(i, 0, N) cnt[A[i]]++;
	rep(i, 0, N) {
		int a = A[i];
		if (cnt[a - 1] == 0) {
			cnt[a - 1]++;
			cnt[a]--;
			A[i] = a - 1;
		}
	}
	rrep(i, N - 1, 0) {
		int a = A[i];
		if (cnt[a + 1] == 0) {
			cnt[a + 1]++;
			cnt[a]--;
			A[i] = a + 1;
		}
	}

	set<int> se;
	rep(i, 0, N) se.insert(A[i]);
	int ans = se.size();
	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N);

	int mi = solve1();
	int ma = solve2();

	cout << mi << " " << ma << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
最小と最大別々に考えよう。

DPでうまいことやる？
最小のときは、同じ値は特に考える必要はないので、1つにまとめておく。
これで「dp[i] := i番目までまとめたときのグループの最小値」を更新する。
AをソートしておくことでこのDPを更新できる。

貪欲にやれそう。
最大のときは、-1して悪くならない限り、-1をすればいい。
こうすると+1での最適化ができないので、+1して悪くならない限り、+1をする。
これでできているグループの個数を数えると最大。
///////////////////////// writeup2 end */
