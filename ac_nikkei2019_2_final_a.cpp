//https://atcoder.jp/contests/nikkei2019-2-final/tasks/nikkei2019_2_final_a
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














int N, A[5010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	ll ans = 0;
	rep(j, 0, N) {
		ll lft = 0;
		rep(i, 0, j) if (A[i] < A[j]) lft++;
		ll rht = 0;
		rep(k, j + 1, N) if (A[j] > A[k]) rht++;
		ans += lft * rht;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
3組の数え上げは、中心で全探索するパターンが多い。
多いので、それから考えてみる。
すると、あるjについて、A[i]<A[j]を満たすiの個数×A[j]>A[k]を満たすkの個数の総和を答えていけばいい。
この個数はO(N)でやっても全体で間に合うので、やる。
///////////////////////// writeup2 end */
