//https://atcoder.jp/contests/past201912-open/tasks/past201912_b
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














int N, A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N - 1) {
		if (A[i] == A[i + 1]) printf("stay\n");
		else if (A[i] > A[i + 1]) printf("down %d\n", A[i] - A[i + 1]);
		else printf("up %d\n", A[i + 1] - A[i]);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
隣り合う2要素について、実装をしていく問題。
実装を頑張る問題であり、特に注意点も無いが、vectorのsizeメソッドを-1する時は注意が必要。
vectorのsizeメソッドの戻り値はunsignedであり、-1するとアンダーオーバーフローしてunsignedの最大値になるので注意。
///////////////////////// writeup2 end */
