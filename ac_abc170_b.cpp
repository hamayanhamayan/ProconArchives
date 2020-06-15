//https://atcoder.jp/contests/abc170/tasks/abc170_b
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














int X, Y;
//---------------------------------------------------------------------------------------------------
string solve() {
	rep(tsuru, 0, 101) rep(kame, 0, 101) {
		if (tsuru + kame == X && 2 * tsuru + 4 * kame == Y) {
			return "Yes";
		}
	}
	return "No";
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X >> Y;
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
鶴亀算が与えられて、答えが存在するか判定する問題。
真面目に鶴亀算を解いてもいいのだが、計算機に頼るとしよう。
つまりは全探索するということだが、庭の動物の総数は最大100までしか与えられないので、
鶴も亀も0匹～100匹の間で全探索すればよいことになる。
どちらの場合も全探索すると、全部で10^4通りを試すことになるが、計算量的には問題ない。
全探索して、条件を満たすものがあればYesで返す。
見つからないならNo
///////////////////////// writeup2 end */
