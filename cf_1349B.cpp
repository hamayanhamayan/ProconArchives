//https://codeforces.com/contest/1349/problem/B
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














int N, K, A[101010];
//---------------------------------------------------------------------------------------------------
bool check() {
	int tot = -inf/2;
	rep(i, 0, N) {
		if (A[i] == 0) tot = 0;
		else {
			tot += A[i];
			if (0 <= tot) return true;
		}
	}
	return false;
}
void solve() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) {
		if (A[i] < K) A[i] = -1;
		else if (A[i] == K) A[i] = 0;
		else A[i] = 1;
	}

	bool ok = false;
	rep(i, 0, N) if (A[i] == 0) ok = true;
	if (!ok) {
		printf("no\n");
		return;
	}

	bool ans = false;
	if (N == 1 && A[0] == 0) ans = true;
	rep(i, 0, N - 1) if (A[i] == 0 && A[i + 1] == 0) ans = true;

	ans |= check();
	reverse(A, A + N);
	ans |= check();

	rep(i, 0, N - 1) if (A[i] == 1 && A[i + 1] == 1) ans = true;
	rep(i, 0, N - 2) if (A[i] == 1 && A[i + 1] == -1 && A[i + 2] == 1) ans = true;
	rep(i, 0, N - 2) if (A[i] == 0 && A[i + 1] == -1 && A[i + 2] == 0) ans = true;

	if (ans) printf("yes\n");
	else printf("no\n");
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
