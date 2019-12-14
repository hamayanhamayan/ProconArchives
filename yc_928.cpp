//https://yukicoder.me/problems/no/928
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














int P, Q, A;
int MA = 1000000;
//---------------------------------------------------------------------------------------------------
bool check(ll x) {
	ll lft = (100 + P) * x / 100;
	ll rht = (100 + Q) * x / 100 + A;
	return lft < rht;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> P >> Q >> A;

	int ans = 0;
	rep(x, 1, MA) if (check(x)) ans++;
	if (check(MA)) ans += 1000000000 - MA + 1;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
不等式にして条件を満たすラーメンを考えてみる。
floor( (1+P/100)*x ) < floor( (1+Q/100)*x ) + A
floorは切り捨ての関数である。
両辺のfloorについてなんとかするのは難しい。
中身と制約をよく見るとxは2倍にしかならない。
Aの最大値は10^4なので、xは十分に大きくなると、大小関係が一定になってくる。
なので、適当な所で探索を打ちやめて大小関係が固まってきたら、それ以降は同じであるとして良い。
///////////////////////// writeup2 end */
