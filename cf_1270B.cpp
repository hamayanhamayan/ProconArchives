//https://codeforces.com/contest/1270/problem/B
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
void solve() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N - 1) {
		int a = A[i];
		int b = A[i + 1];
		if (2 <= abs(b - a)) {
			printf("YES\n%d %d\n", i + 1, i + 2);
			return;
		}
	}

	printf("NO\n");
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
条件を満たすものがあるならば、隣り合う2つで満たすものがある。
上手く説明するのが難しいが、条件が満たされるのは、123...のような連続になっていないものであり、
124みたいな感じになっている必要があるが、どんな順番であっても必ず2つ以上離れている部分が存在する。
よって、隣り合う2つで探せばいい。
差の絶対値が2以上の所があれば、それを答える。
///////////////////////// writeup2 end */
