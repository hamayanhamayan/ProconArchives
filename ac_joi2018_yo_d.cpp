//https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_d
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












int N, L[55];
//---------------------------------------------------------------------------------------------------
int LL[55];
int getsm(int a, int b) { // L[a] + L[a + 1] + ... + L[b]
	int sm = LL[b];
	if (a) sm -= LL[a - 1];
	return sm;
}
//---------------------------------------------------------------------------------------------------
int memo[55];
int f(int idx, int mi, int ma) {
	if (0 <= memo[idx]) return memo[idx];
	if (idx == N) return 1;

	int lim = N;
	if (idx == 0) lim = N - 1;
	rep(i, idx, lim) {
		int sm = getsm(idx, i);
		if (mi <= sm and sm <= ma) {
			if (f(i + 1, mi, ma)) return memo[idx] = 1;
		}
	}

	return memo[idx] = 0;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> L[i];
	LL[0] = L[0];
	rep(i, 1, N) LL[i] = LL[i - 1] + L[i];

	vector<int> v;
	rep(i, 0, N) rep(j, i, N) {
		int sm = getsm(i, j);
		v.push_back(sm);
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());

	int n = v.size();
	int ans = inf;
	rep(i, 0, n) rep(j, i, n) {
		int mi = v[i];
		int ma = v[j];
		rep(k, 0, N + 1) memo[k] = -1;
		if (f(0, mi, ma)) chmin(ans, ma - mi);
	}
	cout << ans << endl;
}


/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
