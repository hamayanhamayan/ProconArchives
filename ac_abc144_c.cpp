//https://atcoder.jp/contests/abc144/tasks/abc144_c
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














ll N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	ll ans = infl;
	rep(i, 1, 1010101) if (N % i == 0) chmin(ans, i + N / i - 2);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、制約を見ると、掛け算表を作るのは現実的ではない。
Nが書かれているマスはどんなマスだろうと考えたときに、i*j=Nを満たすマスであることがわかる。
ここに移動するのにかかる移動回数は(i-1)+(j-1)である。
よって、i*j=Nを満たすi,jが列挙できれば、その中での移動回数の最小値を答えればいい。

10^12という特殊制約は、O(sqrt(N))で解いてほしいというメッセージが込められている。
i,jはNの約数であるため、約数列挙を思いつくほうが早いかもしれない。
i≦jという風に制約を追加すると、iの上限はsqrt(N)になる。
よって、iを1～10^6くらい前探索して、j=N/iとして整数であれば、条件を満たす。
これでi,jが高速に全探索できるので、あとは移動回数の最小値を求める。
///////////////////////// writeup2 end */
