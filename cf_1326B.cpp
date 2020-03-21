//https://codeforces.com/contest/1326/problem/B
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














int N; ll B[201010];
ll A[201010], X[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> B[i];

	ll ma = 0;
	X[0] = 0;
	rep(i, 0, N) {
		// A[i] - X[i] = B[i]
		A[i] = B[i] + X[i];
		chmax(ma, A[i]);
		X[i + 1] = ma;
	}

	rep(i, 0, N) {
		if(i) printf(" ");
		printf("%lld", A[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実は順番に構築していけばいい。
x[0]は0で固定。
b[i]=a[i]-x[i]なので、a[i]=b[i]+x[i]である。
なので、a[0]=b[0]+x[0]を使って、a[0]を計算可能。
a[0]があれば、x[1]が計算できる。
a[1]=b[1]+x[1]でa[i]を計算。
a[0],a[1]があれば、x[2]が計算できる。
これを繰り返せば構築可能。
///////////////////////// writeup2 end */
