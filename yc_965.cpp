//https://yukicoder.me/problems/no/965
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














int A, B, C;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> C;

	int ans = inf;
	chmin(ans, abs(A - B));
	chmin(ans, abs(A - C));
	chmin(ans, abs(B - C));

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
門松列は、A>B<Cであるか、A>B<Cである。
この関係を壊すには、大小関係を壊す必要がある。
例えば、A<Bという関係があったときに、この大小関係を壊すには、A=Bのように等しくなるポイントが一番近い。
よって、A=B, A=C, B=Cのどれかが、最も近い壊れる関係となる。
この3つについて差をとり、最小の物が答え。
///////////////////////// writeup2 end */
