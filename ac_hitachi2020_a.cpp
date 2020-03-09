//https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_a
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














string S;
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
	int n = S.length();

	if (n % 2 == 1) return no;
	rep(i, 0, n / 2) if (S.substr(i * 2, 2) != "hi") return no;

	return yes;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、文字列長が奇数であれば、hitachi文字列にはなりえない。
偶数であれば、2つずつ文字列を区切って、hiかどうかを確かめていけばいい。
///////////////////////// writeup2 end */
