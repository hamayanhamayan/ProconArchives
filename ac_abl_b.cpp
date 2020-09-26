//https://atcoder.jp/contests/abl/tasks/abl_b
#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; using namespace atcoder;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
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














ll A, B, C, D;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> C >> D;

	ll L = max(A, C);
	ll R = min(B, D);

	if (L <= R) cout << "Yes" << endl;
	else cout << "No" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
[A,B]と[C,D]の区間のANDを取ったときに、残る区間があるかという問題。
区間のANDを取りたい場面は結構あって、以下の手法が役に立つ。

[A,B]と[C,D]の区間のAND -> [max(A,C),min(B,D)]

ANDを取ったときに区間が残らない場合は、[4,2]みたいな変な感じになるので、ANDを取った[L,R]に対して、
L≦Rであるかを確認すれば区間が残るかが分かる。
///////////////////////// writeup2 end */
