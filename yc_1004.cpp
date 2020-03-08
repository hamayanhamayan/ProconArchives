//https://yukicoder.me/problems/no/1004
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














int a, b, x0, N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> a >> b >> x0 >> N;

	a %= 2;
	b %= 2;
	x0 %= 2;

	int x1 = (a * x0 + b) % 2;

	if (a == 0 && b == 1) {
		int taka = N / 2;
		int aoki = N / 2;
		if (2 <= N && x0 == 0) taka++;
		if (2 <= N && x1 == 0) aoki++;
		printf("%d %d\n", taka, aoki);
	} else if (a == 0 && b == 0) {
		int taka = 0;
		int aoki = 0;
		if (2 <= N && x0 == 1) taka++;
		if (2 <= N && x1 == 1) aoki++;
		printf("%d %d\n", taka, aoki);
	} else printf("0 0\n"); // (1, 1), (0, 0)
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
a(ax+b)+b=ax+ab+b
///////////////////////// writeup2 end */
