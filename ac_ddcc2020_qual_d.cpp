//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d
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














int M;
int D[201010]; ll C[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> M;
	rep(i, 0, M) cin >> D[i] >> C[i];

	int cur = 0;
	ll ans = 0;
	rep(_, 0, M) {
		int d = D[_];
		ll c = C[_];

		if (c < 30) {
			rep(i, 0, c) {
				cur += d;
				ans++;
				if (10 <= cur) {
					cur = (cur / 10) + (cur % 10);
					ans++;
				}
			}
		}
		else {
			int idx = 0;

			map<int, int> loop;
			map<int, ll> need;
			loop[cur] = 0;
			need[cur] = ans;

			cur += d;
			ans++;
			if (10 <= cur) {
				cur = (cur / 10) + (cur % 10);
				ans++;
			}
			idx++;

			while (!loop.count(cur)) {
				loop[cur] = idx;
				need[cur] = ans;

				cur += d;
				ans++;
				if (10 <= cur) {
					cur = (cur / 10) + (cur % 10);
					ans++;
				}
				idx++;
			}

			ll ansd = ans - need[cur];
			int loopp = idx - loop[cur];

			c -= idx;

			ans += c / loopp * ansd;
			c %= loopp;
			rep(i, 0, c) {
				cur += d;
				ans++;
				if (10 <= cur) {
					cur = (cur / 10) + (cur % 10);
					ans++;
				}
			}
		}
	}
	cout << ans-1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
コードがかちゃかちゃだが、方針を伝える。
以下の様な考察で解にたどり着く。

1. ぱっと見て最適な動きが思いつかない
2. 値も大きいし、最適解への方針を見つけるのは難しそう
3. 何かしら性質が無いと厳しい
4. どんな操作をやっても同じ回数になるのでは？
5. 実験するとなる
6. 先頭から順番に操作を行っていって、かかる回数を計算しよう

これで方針はだいたい立った。
あとは、操作を高速化するだけであるが、先頭から順番にやっていくと、最上位の処理済みの数は必ず1桁になる。
よって、同じ+D[i]をする回数をC[i]回やるが、鳩ノ巣定理によりループが発生する。
そのループの周期looppと1ループでかかるコストansdを元にans += C[i] / loopp * ansdとすればループ分は解消できる。
あとは、半端な分をシミュレートすればいい。
///////////////////////// writeup2 end */
