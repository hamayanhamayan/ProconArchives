//https://yukicoder.me/problems/no/908
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














string S;
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
	int n = S.length();
	rep(i, 0, n) {
		if (i % 2 == 0 and S[i] == ' ') return no;
		if (i % 2 == 1 and S[i] != ' ') return no;
	}
	return yes;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	getline(cin, S);
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
うしたぷにきあくん文字列である条件を確認すればいい。
1列取得したいときはgetline関数を使うといい。
ダメなパターンをチェックする。
「奇数番目で空白があるとき」「偶数番目で空白じゃないとき」
これをチェックして当てはまればNo
そうでないなら、Yes
///////////////////////// writeup2 end */
