//https://atcoder.jp/contests/past202004-open/tasks/past202004_i
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














int N, A[1 << 16];
int ans[1 << 16];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, 1 << N) cin >> A[i];

	vector<int> cur;
	rep(i, 0, 1 << N) cur.push_back(i);

	rep(round, 1, N + 1) {
		int n = cur.size();

		vector<int> nxt;
		rep(i, 0, n / 2) {
			int a = cur[i * 2];
			int b = cur[i * 2 + 1];

			if (A[a] < A[b]) {
				ans[a] = round;
				nxt.push_back(b);
			}
			else {
				ans[b] = round;
				nxt.push_back(a);
			}
		}
		swap(cur, nxt);
	}

	rep(i, 0, 1 << N) {
		if (ans[i] == 0) ans[i] = N;
		printf("%d\n", ans[i]);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
トーナメントでの戦いがあるので、これをシミュレートする問題。
先頭から2つずつ戦わせていくというのをN回繰り返していくと、シミュレートを正しく行うことができる。
勝者を残すというのは、下手に配列を使いまわすよりも、次の配列に分けて追加していくほうがやりやすい。
cur配列に現在勝ち残っているプレイヤーを入れておき、先頭から2つずつ取り出して勝者をnxt配列に入れる。
全部終わったら、cur = nxtとして、またcurに対して同様の操作を行っていけばいい。
自分はcur=nxtの代わりとしてswap(cur,nxt)を使っている。
///////////////////////// writeup2 end */
