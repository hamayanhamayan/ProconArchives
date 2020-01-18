//https://yukicoder.me/problems/no/970
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














int N, Y[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> Y[i];

	rep(i, 0, N) Y[i] *= N - 1;

	ll tot = 0;
	rep(i, 0, N) tot += Y[i];
	tot /= N - 1;

	rep(i, 0, N) {
		if(i) printf(" ");
		int x = tot - Y[i];
		printf("%d", x);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
平均は分数の形になっていて少し扱いにくいので、b[i]をN-1倍して考える。
すると、b[i]はa[i]以外の総和になるので、この時点で全部の総和が分かれば答えられそうだなと分かる。
総和を求めたいが、ここでブレイクスルーが必要となる。
b[i]の総和を求めると、a[i]の総和のN-1倍が得られる。
これはb[i]はa[i]以外の和を求めているので、全て足すとa[i]がN-1回足されることになり、
全部に対してそれが言えることから分かる。
なので、b[i]の総和÷(N-1)をすると、a[i]の総和が得られるので、総和とb[i]よりa[i]を求めることができる。
///////////////////////// writeup2 end */
