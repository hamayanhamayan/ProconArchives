//https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_b
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














ll A, V, B, W, T;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> V >> B >> W >> T;
	if (A > B) A *= -1, B *= -1;
	A += V * T;
	B += W * T;

	if (B <= A) cout << "YES" << endl;
	else cout << "NO" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
シミュレーションしていけばいい。
鬼は子供に常に向かうように移動すればいいし、子供は鬼から逃げるように移動すればいい。
これはどちらも同じ方向になる。

自分は実装を簡単にするために、この移動方向を常に数直線の正の方向にしている。
鬼≦子供であれば、移動方向は正の方向であるが、鬼＞子供なら負の方向なので、
その場合は、原点で反転させることで、位置関係を変えずに移動方向を逆にしている。

あとは、鬼・子供がT秒語にどこにいるかというのを計算して、鬼が子供を追い越していれば、
時刻Tまでに捕まえられるので、それを判定する。
///////////////////////// writeup2 end */
