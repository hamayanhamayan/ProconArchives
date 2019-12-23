//https://atcoder.jp/contests/abc148/tasks/abc148_d
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
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	int cu = 1;
	rep(i, 0, N) if (A[i] == cu) cu++;
	
	if (cu == 1) cout << -1 << endl;
	else cout << N - cu + 1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
400点問題にしては、なかなか難しそうな問題に見える。
何か特殊な操作をするのだろうか。
壊すレンガを最小化するのではなく、残すレンガを最大化するよう考える。
すると、1,2,3,...というのを順番になるべく長く抜き出してくる必要がある。
これは、網羅的なアルゴリズムではなく、貪欲法で解けそうだ。

具体的には、先頭から順番に近い順に1,2,3と取っていく。
なぜ、こうして取った結果が最適かであるが、
ある1を取るときに先頭に最も近い1を取る方が、それ以外を取るより後々有利になることは分かるだろう。
つまり、選択肢がいくつかあるときに、必ず有利となる選択を毎回行うと、
先頭から近い順に1,2,3,と取っていくアルゴリズムとなる。

あとは、実装を頑張るが、先頭から精査していくなかで、どこまで取ったかを記録しておけばいい。
///////////////////////// writeup2 end */
