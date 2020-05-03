//https://atcoder.jp/contests/abc166/tasks/abc166_e
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














int N, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	map<int, int> cnt;
	ll ans = 0;
	rep(i, 0, N) {
		ans += cnt[i - A[i]];
		cnt[A[i] + i]++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まずは以下の典型解法をベースに考えよう。
「数列の2要素a,b(a<b)についての数え上げは、bを全探索して条件を満たすaを高速に数え上げることで解く」

ペアを考えるときにa<bというのを使うと、「2人の持つ番号の差の絶対値」がb-aとなる。
一般に絶対値というのは扱いにくいので、大小を決定して絶対値を外す方針がよく用いられる。
満たすべき条件を式にすると、`b - a = A[a] + A[b]`となる。
変形すると、
`b - A[b] = A[a] + a`
となる。

これで条件を満たすaというのは、a<bかつb-A[b]=A[a]+aを満たすaとなる。
この時、
cnt[x] := A[a]+a=xを満たすaの個数
をbを全探索しながら更新していくことで、「bを評価するときは、cnt配列はa<bのものが作られている」状態が作れる。
これで、cnt[b-A[b]]を答えに足し合わせていくと答えが得られる。
///////////////////////// writeup2 end */
