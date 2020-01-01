//https://atcoder.jp/contests/abc149/tasks/abc149_d
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














int N, K, R, S, P; string T;
string grp[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> R >> S >> P >> T;
	rep(i, 0, N) grp[i % K] += T[i];

	int ans = 0;
	rep(k, 0, K) {
		int r = 0, s = 0, p = 0;
		if (grp[k][0] == 'r') p = P;
		if (grp[k][0] == 's') r = R;
		if (grp[k][0] == 'p') s = S;

		int n = grp[k].size();
		rep(i, 1, n) {
			int rr = max(s, p);
			int ss = max(r, p);
			int pp = max(r, s);

			if (grp[k][i] == 'r') pp += P;
			if (grp[k][i] == 's') rr += R;
			if (grp[k][i] == 'p') ss += S;

			r = rr;
			s = ss;
			p = pp;
		}

		ans += max({ r, s, p });
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
じゃんけんは基本は独立に処理することができる。
だが、K回前のじゃんけんで出した手と同じ手を出すことはできないという制約から、
K個飛びでは制約があることが分かる。
よって、K個飛びでまとめて、それ単位を処理することにしよう。

まとめることで、1つ前と同じ手にすることはできないという制約になるため、
簡単なDPで解決することにしよう。
DP[i][lst] := i番目まで手が決まっていて最後の手がlstであるときの最大得点
あとは、これを合計すればいい。
自分の実装では、DPを用意するのが面倒だったので、変数r,s,pを用意して更新していった。
///////////////////////// writeup2 end */
