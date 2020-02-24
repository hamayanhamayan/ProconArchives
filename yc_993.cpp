//https://yukicoder.me/problems/no/993
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
void _main() {
	cin >> S;
	int n = S.length();
	rep(i, 0, n - 1) if (S[i] == 'a' && S[i + 1] == 'o') {
		S[i] = 'k';
		S[i + 1] = 'i';
	}
	cout << S << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
パターンマッチングをして文字列を書き換える。
文字列長は短く、書き換え後に再書き換えの恐れがあるリスクもないので、
先頭からaoを探してkiに変えていこう。
///////////////////////// writeup2 end */
