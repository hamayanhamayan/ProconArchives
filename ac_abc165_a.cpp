//https://atcoder.jp/contests/abc165/tasks/abc165_a
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














int K, A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> K >> A >> B;

	rep(x, A, B + 1) if (x % K == 0) {
		cout << "OK" << endl;
		return;
	}
	cout << "NG" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ジャンボ高橋君の出せる飛距離のパターンは10^3通りくらいなので、全部試してKの倍数があるか探そう。
体感としては全列挙したときに10^7通り以下なら、列挙後の計算が軽ければ大丈夫。
///////////////////////// writeup2 end */
