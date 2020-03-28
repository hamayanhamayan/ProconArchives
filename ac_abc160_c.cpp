//https://atcoder.jp/contests/abc160/tasks/abc160_c
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














int K, N, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> K >> N;
	rep(i, 0, N) cin >> A[i];

	int ans = A[N - 1] - A[0];
	rep(i, 1, N) {
		int i_to_start = K - A[i];
		int start_to_i1 = A[i - 1];
		chmin(ans, i_to_start + start_to_i1);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ある家iから出発してすべての家を回る最短経路はi -> i+1 -> i+2 -> ... -> N -> 1 -> 2 -> ... -> i-1という感じになる。
つまり、1パターンしかないということ。
この場合にかかる距離は、「家iから湖のスタート(x=Kの位置)＋湖のスタート(x=0の位置)から家i-1」となる。
注意点として、家1から家Nへの最短経路は湖のスタートを通らないので最初に別途計算しておく。

実装でのchmin(a,b)はa=min(a,b)の短縮マクロとして使ってる。
///////////////////////// writeup2 end */
