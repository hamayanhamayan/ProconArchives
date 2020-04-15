//https://yukicoder.me/problems/no/1022
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
ll mul(ll a, ll b) { if (infl / a < b) return infl; return min(infl, a * b); }
ll fastpow(ll a, ll b) {
	ll ret = 1; while (b > 0) {
		if (b & 1) ret = mul(ret, a); a = mul(a, a); b >>= 1;
	} return ret;
}
vector<int> enumdiv(int n) {
	vector<int> S;
	for (int i = 1; 1LL * i * i <= n; i++) if (n % i == 0) { S.push_back(i); if (i * i != n) S.push_back(n / i); }
	sort(S.begin(), S.end());
	return S;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














ll N;
ll cnt[40];
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return;
	}

	ll ans = 0;

	ans += N * N; // a=c=1
	ans += (N - 1) * (N - 1); // 2<=a=c, b=d

	// 2 <= a < c
	// a^p=c<=N、かつ dp≦Nである必要がある
	// 制約より、pは最大32なので、これは全探索できそう
	// dの組み合わせは簡単にわかる
	// 問題が、aの個数だが、二分探索すればいい。

	rrep(p, 32, 2) {
		ll ok = 1, ng = N;
		while (ok + 1 != ng) {
			ll md = (ok + ng) / 2;

			if (fastpow(ok, p) <= N) ok = md;
			else ng = md;
		}
		cnt[p] = ok - 1;
		int pp = p + p;
		while (pp <= 32) {
			cnt[p] -= cnt[pp];
			pp += p;
		}
	}

	ll tot = 0;
	rep(p, 2, 33) {
		ll dcom = N / p;
		ll acom = cnt[p];
		tot += acom * dcom;
	}

	ans += tot * 2;

	cout << ans << endl;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
