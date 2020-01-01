//https://atcoder.jp/contests/abc149/tasks/abc149_b
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














ll A, B, K;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> K;

	ll eat = min(A, K);

	A -= eat;
	K -= eat;

	eat = min(B, K);

	B -= eat;
	K -= eat;

	printf("%lld %lld\n", A, B);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
高橋くんがクッキーを尽きるまで食べる。
高橋くんが食べるクッキーの量はmin(A,K)枚である。
よってこの枚数分だけ食べて、それをKからひいておこう。

次に青木くんがクッキーを尽きるまで食べる。
同様に青木くんが食べるクッキーの量はmin(B, K)枚である。
よってこの枚数分だけ食べて、それをKからひいておこう。

これで、高橋くんと青木くんの持っている枚数を答えれば答え。
10^12はintでは収まらないので、long longで変数を定義しよう。
///////////////////////// writeup2 end */
