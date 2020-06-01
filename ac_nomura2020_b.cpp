//https://atcoder.jp/contests/nomura2020/tasks/nomura2020_b
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














string T;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> T;
	fore(c, T) if (c == '?') c = 'D';
	cout << T << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
?にPを入れるかDを入れるかをDPで最適解を求めて、復元して答えを求める…
というのも1つの手ではあるが、200点問題としては厳しいだろう。

最適方針が存在する。
?には常にDを入れるのが最適になる。
Dを入れる時とPを入れる時をそれぞれ考えてみる。
Dを入れると必ず1pt入る。
Pを入れると、次がDの時に限り1pt入る。
Pを入れることで後々2pt入ることもないので、常にDを入れておけばいい。

?をDに変換して答える。
///////////////////////// writeup2 end */
