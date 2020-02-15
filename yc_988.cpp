//https://yukicoder.me/problems/no/988
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














int N, M, K; char op;
ll B[101010], A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K >> op;
	rep(i, 0, M) cin >> B[i];
	rep(i, 0, N) cin >> A[i];

	ll ans = 0;
	if (op == '+') {
		rep(i, 0, N) ans += A[i] * M;
		rep(i, 0, M) ans += B[i] * N;
	}
	else {
		ll a_sm = 0;
		rep(i, 0, N) a_sm += A[i];
		a_sm %= K;
		ll b_sm = 0;
		rep(i, 0, M) b_sm += B[i];
		b_sm %= K;
		ans = a_sm * b_sm;
	}
	cout << ans % K << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
すべての要素について計算することはできない。
場合分けをして、それぞれで効率な解き方をやろう。

opが和の場合。
主客転倒テクを使う。
すべての組み合わせを列挙するのは難しいので、すべての総和の中でA[i],B[i]が何回足されるかを考える。
A[i]が足される組み合わせはC[i][?]であるので、?の個数回足されることになる。
これは配列Bの個数であり、M個である。
よって、A[i]の分は全体でA[i]*Mである。
同様にB[i]の分は全体でB[i]*Nである。
これらの総和をとると答え。

orが積の場合。
分配法則をうまく使う。
配列Aの要素と配列Bの要素の全パターンの組み合わせの積の総和なので、
(配列Aの要素の総和)×(配列Bの要素の総和)を求めることで、答えが求まる。
///////////////////////// writeup2 end */
