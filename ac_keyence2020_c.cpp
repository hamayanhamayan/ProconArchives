//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_c
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














int N, K, S;
int MA = 1000000000;
int ans[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> S;

	if (S == MA) {
		rep(i, 0, K) ans[i] = MA;
		rep(i, K, N) ans[i] = 1;
	}
	else {
		rep(i, 0, K) ans[i] = S;
		rep(i, K, N) ans[i] = MA;
	}

	rep(i, 0, N) {
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
問題にかなりの弱点がある。
0≦K≦Nの部分である。
よって、大体はSをK個並べて、残りをINFにすればいい。
INFは最大が10^9なので、これにしておく。

この場合、S=10^9の時におかしくなる。
SをK個並べて、残りは1にしておこう。
1を集めても10^9にすることはできないためである。
///////////////////////// writeup2 end */
