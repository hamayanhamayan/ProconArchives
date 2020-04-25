//https://yukicoder.me/problems/no/1034
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














int N, I, J;
//---------------------------------------------------------------------------------------------------
ll solve() {
	cin >> N >> I >> J;
	
	int mi = min({ I, J, N - 1 - I, N - 1 - J });

	ll ans = 1LL * (N - 1 + N - 1 - (mi - 1) * 2) * mi / 2 * 4;
	I -= mi;
	J -= mi;
	N -= mi * 2;

	if (N == 1) return ans;
	else if (N == 2) {
		if (I == 0 && J == 0) return ans;
		else if (I == 0 && J == 1) return ans + 1;
		else if (I == 1 && J == 1) return ans + 2;
		return ans + 3;
	}
	else {
		if (I == 0) return ans + J;
		ans += N - 1;

		if (J == N - 1) return ans + I;
		ans += N - 1;

		if (I == N - 1) return ans + N - 1 - J;
		ans += N - 1;

		return ans + N - 1 - I;
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int Q; cin >> Q;
	rep(q, 0, Q) printf("%lld\n", solve());
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
