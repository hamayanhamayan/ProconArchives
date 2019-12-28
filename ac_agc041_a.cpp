//https://atcoder.jp/contests/agc041/tasks/agc041_a
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














ll N, A, B;
//---------------------------------------------------------------------------------------------------
ll solve(ll a, ll b) {
	ll d = b - a;
	if (d % 2 == 0) return d / 2;

	ll ans = infl;

	// 最左へ
	chmin(ans, a + solve(1, b - a));

	// 最右へ
	chmin(ans, N - b + 1 + solve(a + (N - b + 1), N));

	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> A >> B;
	cout << solve(A, B) << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、2人の友達は同時に動くため、互いに近づいて行っても、交わることができる場合とできない場合がある。
B-Aが偶数なら交わることができる。
このときにかかるラウンドは、(B-A)/2であり、これが答え。
B-Aが奇数のときは、片方が場所をずらす必要がある。
これは、Aが左端に移動して勝つか、Bが右端に移動して負けるかである。
すると、B-Aの偶奇が変化するので、両方試す。
自分の実装では、A,Bが端に到着したあとに互いに近づいて行くので、
端に移動させたら再帰的に自分を呼び出して偶数の計算をしている。
///////////////////////// writeup2 end */
