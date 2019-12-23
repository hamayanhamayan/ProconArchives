//https://atcoder.jp/contests/abc148/tasks/abc148_c
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
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














ll A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B;
	cout << lcm(A, B) << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [最小公倍数の効率的な求め方](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
今回の問題はAとBの最小公倍数が答えとなる。
ライブラリとして、最小公倍数を高速に求めるものをもっていれば、それを使うだけ。

最小公倍数を高速に求める方法を知らない方向けに少し説明をすると、
AとBの最小公倍数は、A*B/gcd(A,B)である。
gcd(A,B)はAとBの最大公約数のことである。
これには、ユークリッドの互除法という効率的な計算アルゴリズムがある。
これを使うと、O(log(A+B))くらいでGCDを求めることができる。
よって、これを持っていると答えることができる。

加えて、32bit整数ではオーバーフローする可能性があるので、注意。
C++ならlong longを使おう。
///////////////////////// writeup2 end */
