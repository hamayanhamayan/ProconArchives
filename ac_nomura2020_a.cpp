//https://atcoder.jp/contests/nomura2020/tasks/nomura2020_a
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














int H1, M1, H2, M2, K;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H1 >> M1 >> H2 >> M2 >> K;

	int st = H1 * 60 + M1;
	int gl = H2 * 60 + M2;

	int len = gl - st;
	int ans = len - K;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず起きている時間を計算しよう。
時間の単位が色々あるので、全部分に直してやるのが簡単。
H1時M1分を分に直すと、60*H1+M1分となる。
H2時M2分を分に直すと、60*H2+M2分となる。
この差分が起きている時間なので、60*H2+M2 - 60*H1+M1となる。

勉強を開始するためには、勉強できる時間帯の末尾からK分で始めるとオーバーしてしまうので、それ以外の部分で始める必要がある。
よって、開始できる時間の長さは60*H2+M2 - 60*H1+M1 - Kであり、これが答え。
///////////////////////// writeup2 end */
