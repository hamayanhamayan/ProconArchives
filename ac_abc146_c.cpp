//https://atcoder.jp/contests/abc146/tasks/abc146_c
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














ll A, B, X;
//---------------------------------------------------------------------------------------------------
ll check(ll x) {
	ll dx = to_string(x).length();
	return A * x + B * dx;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> X;
	ll ok = 0, ng = 1000000001;
	while (ok + 1 != ng) {
		ll md = (ok + ng) / 2;
		if (check(md) <= X) ok = md;
		else ng = md;
	}
	cout << ok << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
///////////////////////// writeup2 start
x<yを満たすならばxの値段<yの値段を必ず満たす。
よって、所持金Xの境界線がどこにあるかを割り出せばいい。
これは二分探索を使おう。
check(x) := xを買うときの値段
これがX以下ならok, Xより大きいならngとして境界を詰めていく。
///////////////////////// writeup2 end */
