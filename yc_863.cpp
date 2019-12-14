//https://yukicoder.me/problems/no/863
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










int A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B;

	if (40 * A <= B and B < 40 + 40 * A) cout << 1 << endl;
	else cout << 2 << endl;
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
計算量が線形時間であれば、Nが40倍になれば、かかる時間も40倍になっているはずである。
小数点切り捨てでAミリ秒なので、実際には、A.0～A.9999であるので、40倍すると、
39.996 + 40Aくらいになるので、40A～39.996 + 40AにBが入っていれば線形ということになる。
これを判定すればいい。
///////////////////////// writeup2 end */
	