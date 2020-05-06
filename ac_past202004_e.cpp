//https://atcoder.jp/contests/past202004-open/tasks/past202004_e
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














int N, A[101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i], A[i]--;

	rep(i, 0, N) {
		int x = A[i];
		int j = 1;
		while (x != i) {
			x = A[x];
			j++;
		}

		if(i) printf(" ");
		printf("%d", j);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
各整数iについて、操作をシミュレーションして、条件を満たす整数jを答える。
そのまま、配列Aを受け取ると、「A[x] := xから1回の操作を行った後の値」となっている。
0-indexedでやっている場合は、A[x]--をしておこう。
これで、シミュレーションをしていく。
条件はx != iであるなら操作を継続するようにやっていけばいい。
初期状態をx=iとしてしまうと、操作を継続できないので、最初の1手だけ最初に行う。
これで各iについて、それぞれ答えれば答え。
///////////////////////// writeup2 end */
