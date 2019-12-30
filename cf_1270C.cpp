//https://codeforces.com/contest/1270/problem/C
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














int N, A[101010];
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	ll sm = 0;
	rep(i, 0, N) sm += A[i];

	ll xorsm = 0;
	rep(i, 0, N) xorsm ^= A[i];

	ll ans1 = xorsm;
	ll ans2 = xorsm + sm;

	printf("2\n%lld %lld\n", ans1, ans2);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難しい問題に見える。
和は別に大丈夫だが、xor和を2倍するという操作はいかにもヤバそうに見える。
加えて問題の方にも操作は最小化する必要は無いよと書いてあるし、順位表を見ても爆速でみんな通しているので、
なにか特別な解き方があって、それを全部に適用できる感じだろうなぁと漠然と考える。

総和と2×XOR和
を同じにしたい。
XOR和がとても面倒で、扱いにくい。
なので、XOR和を足すことで、消そう。

総和 + XOR和と2×0
を同じにしたい。
いい感じになってきた。
1つ数を足すと右辺では2倍されるので、2倍されて等しくなるためには、総和 + XOR和を足せばいい。
総和 + XOR和 + 総和 + XOR和と2×(総和 + XOR和)
これは等しい。

よって、2つの数で必ず等式を作ることができ、
「XOR和」と「総和 + XOR和」を答えればいい。
///////////////////////// writeup2 end */
