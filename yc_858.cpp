//https://yukicoder.me/problems/no/858
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













ll A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B;

	ll integer = A / B;
	A %= B;

	printf("%lld.", integer);

	rep(i, 0, 50) {
		A *= 10;
		ll decimal = A / B;
		A %= B;
		printf("%lld", decimal);
	}

	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
A/Bをしていって商をこたえていく。
余りを10倍して小数点以下の答えを求めていく。
Bで割って、あまりを残して、10倍して…というのを繰り返す。
///////////////////////// writeup2 end */
