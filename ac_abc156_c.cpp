//https://atcoder.jp/contests/abc156/tasks/abc156_c
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














int N, X[101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> X[i];
	sort(X, X + N);

	int ans = inf;
	rep(P, 1, 101) {
		int tot = 0;
		rep(i, 0, N) tot += (X[i] - P) * (X[i] - P);
		chmin(ans, tot);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
集会を開く座標Pを全探索しよう。
座標Pの最小値が得られそうで、置ける部分は[1,100]になる。
これは、その範囲でのみ集会が行われるからである。
それ以外の部分に置くときは、P=1かP=100に置くことで状況を変えずに同等の状態が作れる。
///////////////////////// writeup2 end */
