//https://yukicoder.me/problems/no/994
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














int N, K;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
	}

	if (N < K) cout << -1 << endl;
	else cout << K - 1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
N頂点に最大個数コインを置くとN枚になる。
これ以上コインがあった場合は1枚ずつにすることはできない。
よって、N<Kであれば答えは-1となる。

それ以外であれば、操作を行うことで実現可能。
実際の実現方法は聞かれておらず、最短回数だけ聞かれているが、
この答えはグラフの形によらず、K-1回となる。
理想状態にするには、K頂点にコインを置けばいいことになるが、
最初は1頂点にコインがあり、1操作につきコインがある頂点を1つ増やすことができる。
何枚コインを動かすかは、その先に置く頂点の枚数分動かせばよい。
よって、K-1頂点に対して新規でコインを置くので、必要な回数はK-1回であり、
これが最小回数である。
///////////////////////// writeup2 end */
