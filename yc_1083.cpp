//https://yukicoder.me/problems/no/1083
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














int N, K, A[20];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N, greater<int>());

	int ans = 0;
	rep(msk, 1, 1 << N) if(msk & (1 << (N - 1))) {
		int X = K;
		rep(i, 0, N) if (msk & (1 << i)) X %= A[i];
		chmax(ans, X);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
見た目に難しい問題。
Nの制約が異常に小さいので、O(N2^N)かな…といういつものやつを頭の片隅に置きつつ考える。
配列Aを固定した場合を考えてみよう。
modを取るときに、A[i]≦A[i+1]であれば、mod A[i]の結果がmod A[i + 1]で変わることはない。
なので、modを取って結果が変わる部分というのは、先頭から狭義単調減少する列だけが関係する。
「狭義単調減少する列」というのは全探索すると、2^N-1通りあるので、想定解法な道筋であるように感じる。
bit全探索を書いて、狭義単調減少列でmodを取った結果の最大を取るとサンプルが合わない。
よく考えると、狭義単調減少列だけでは不十分で、Aの中で最小の数は必ずmodが取られるので、
狭義単調減少列で、かつ、最後の要素が配列Aの中で最小のものだけで探索をすればいい。
///////////////////////// writeup2 end */
