//https://atcoder.jp/contests/abc156/tasks/abc156_f
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














int K, Q, D[5010];
int DD[5010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> K >> Q;
	rep(i, 0, K) cin >> D[i];
	rep(_, 0, Q) {
		int N, X, M; cin >> N >> X >> M;

		rep(k, 0, K) {
			DD[k] = D[k] % M;
			if (DD[k] == 0) DD[k] = M;
		}
		X %= M;

		ll tot = 0;
		rep(k, 0, K) tot += DD[k];
		
		ll start = X;
		ll end = X;

		N--;
		end += 1LL * (N / K) * tot;
		rep(i, 0, (N%K)) end += DD[i];

		ll ng = end / M - start / M;
		ll ans = N - ng;
		printf("%lld\n", ans);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
[(104) AtCoder Beginner Contest 156 - YouTube](https://www.youtube.com/watch?v=lzAMKPMLdtU&feature=youtu.be)
解説AC。
これを思いつくのは厳しい。かなり賢い考え方。
けれど、見たことのあるテクはいくつかある。

- 与えられた条件の逆なら数えやすい
- 与えられた要素をすべてmod Mにとりあえずする
- 【NEW!】d<Mであるとき、a+d>b+d (mod M)となるのは、(a+d)/Mの商<(b+d)/Mの商のとき

数列の末項の計算の仕方を紹介しておく。
数列がN項であるということは、末項は数列dをN-1回足したものであるため、Nは-1しておこう。
d全体の総和をtotとしておく。
N/Kの商を考えると、これがd全体を足す回数となる。
よって、これを先に足す。`end += 1LL * (N / K) * tot;`
すると、残りの回数はN%K回となるので、それだけ愚直に足す。
`rep(i, 0, (N%K)) end += DD[i];`
これでO(K)で用意できるので間に合う。
///////////////////////// writeup2 end */
