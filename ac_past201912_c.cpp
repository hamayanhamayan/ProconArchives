//https://atcoder.jp/contests/past201912-open/tasks/past201912_c
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














int v[6];
//---------------------------------------------------------------------------------------------------
void _main() {
	rep(i, 0, 6) cin >> v[i];
	sort(v, v + 6, greater<int>());
	cout << v[2] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
A～Fを降順ソートして3番目を答えればよい。
ソートするために配列に入れるので、入力を受け付けるときもA,B,...とするのではなく、配列にループで入れてしまう方が良い。
それで降順ソートして3番目、つまり添字では2の数を答える。
///////////////////////// writeup2 end */
