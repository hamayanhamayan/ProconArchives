//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_a
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














int A, B, C, D, E, F;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> C >> D >> E >> F;
	
	int ans = 0;
	ans += (A + B + C + D) - min({ A, B, C, D });
	ans += max(E, F);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
物理、科学、生物、地学から点数が高いものを3つ選んで総和を取るが、
これは、「(総和)-4つのmin」と実は等しい。
こっちのほうが計算しやすいので、こっちで計算しよう。
歴史と地理の大きい方はmaxを使う。
min({A,B,C,D})という書き方は、{A,B,C,D}と書くとA～Dを含む配列が作られる。
よって、min(配列)という指定になっており、これは、配列の中での最小値を取り出してくれる。
///////////////////////// writeup2 end */
