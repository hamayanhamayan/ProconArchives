//https://yukicoder.me/problems/no/982
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
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int A, B;
//---------------------------------------------------------------------------------------------------
int solve() {
	if (A == 1 || B == 1) return 0;
	int g = gcd(A, B);
	if (g != 1) return -1;

	int ans = 0;
	rep(N, 1, 10101) {
		bool ng = true;
		rep(x, 0, 1010) if (0 <= (N - A * x) && (N - A * x) % B == 0) ng = false;
		if (ng) ans++;
	}
	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B;
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
A=1、または、B=1の場合は全部作れるので、0となる。
2≦gcd(A,B)の場合は、作る数は全てその倍数になるので、無限に作れない数があり、-1。

それ以外のパターンを考えるのだが、★2で制約もゆるいので、雑に扱えるんじゃないかという仮定がある。
互いに素であるため、大きい数を作る時は微妙に配合を変えることで、作れそうな感じがする。
なので、小さい数に対して作れない数がある。
よって、小さい数に対して作れるかどうかを判定してやればいい。
小さい数は10^4くらいまでの数に対して判定した。
判定方法は、xをある程度のサイズまで試して、NからAxを引いたときに余りがBで割り切れるかを見ればいい。
///////////////////////// writeup2 end */
