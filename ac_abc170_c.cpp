//https://atcoder.jp/contests/abc170/tasks/abc170_c
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














int X, N;
set<int> p;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X >> N;
	rep(i, 0, N) {
		int x; cin >> x;
		p.insert(x);
	}

	int ans = inf, diff = inf;
	rep(y, 0, 102) if (!p.count(y)) {
		int d = abs(y - X);
		if (d < diff) ans = y, diff = d;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
全探索で解く。  
答えの候補は、制約を見ると[0,101]の範囲にしかない。
よって、答えを全探索して、数列pに含まれなくて、Xに最も近いものを探していけばいい。
実装が問題になるが、数列pに含まれているかというのは、数列pをsetで持っておけば高速に判定できる。
Xに近いものを最小差分(diff)を持ちながら答えを更新していく。
yを小さい方から順に更新していくことにすれば、勝手に複数存在する場合は最小のものという条件もクリアできる。
///////////////////////// writeup2 end */
