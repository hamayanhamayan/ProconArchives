//https://yukicoder.me/problems/no/1107
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














int A[4];
//---------------------------------------------------------------------------------------------------
void _main() {
	rep(i, 0, 4) cin >> A[i];

	bool crescendo = A[0] < A[1];
	bool decrescendo = A[2] > A[3];

	if (crescendo && decrescendo) cout << "YES" << endl;
	else cout << "NO" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
クレッシェンドとデクレッシェンドを別々に判定して、どちらもtrueであればYESを返そう。
自分の実装では、条件式の結果をbool変数に代入して、ANDを取っている。
リーダブルコードかなんだったかに、条件式をbool変数に代入することで、
条件式に名前を付けることができるテクが書いてあった。
まあ、競技プログラミングでは時間効率が悪いけど、実務的には、確かにやや分かりやすくなる。
///////////////////////// writeup2 end */
//　