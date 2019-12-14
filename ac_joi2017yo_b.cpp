//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_b
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














int N, M, A[1010], B[1010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, M) cin >> A[i] >> B[i];
	int ans = 0;
	sort(A, A + M, greater<int>());
	rep(i, 0, M - 1) ans += max(0, N - A[i]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
N≦A[i]であれば、当たりとなり、当たりとなるようにM-1個選んでいく。
どれを当たりカードとすべきか考えたときになるべく、A[i]が大きいカードのほうが書き換える回数が少なくて済む。
よって、カードを考えるときにA[i]が大きいものから順に考えていくのが、最適であることがわかる。

A[i]を降順ソートしよう。
先頭からM-1個に対して、書き換える必要があれば書き換えて当たりカードにしていく。
必要な回数はN-A[i]であるが、もうすでに当たりの場合は負の数になる。
負の数の場合は0にしたいので、max(0, N - A[i])の総和を求めると答え。
///////////////////////// writeup2 end */
