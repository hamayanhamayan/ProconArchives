//https://yukicoder.me/problems/no/968
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




















int A[3], C[3];
ll del[3];
int rev[3];
//---------------------------------------------------------------------------------------------------
void solve() {
	rep(i, 0, 3) cin >> A[i];
	rep(i, 0, 3) cin >> C[i];

	rev[0] = 1;
	rev[1] = 2;
	rev[2] = 0;

	ll ans = infl;

	vector<int> ord;
	rep(i, 0, 3) ord.push_back(i);
	do {
		if (ord[1] == 1) continue;

		rep(i, 0, 3) del[i] = 0;

		int pre = A[ord[0]];
		ll tot = 0;
		rep(i, 1, 3) {
			int nxt = max(A[ord[i]], pre + 1);
			int d = nxt - A[ord[i]];
			tot += 1LL * d * C[rev[ord[i]]];
			pre = nxt;

			if (rev[ord[i]] == 0) {
				del[0] += d;
				del[1] += d;
			}
			else if (rev[ord[i]] == 1) {
				del[1] += d;
				del[2] += d;
			}
			else {
				del[0] += d;
				del[2] += d;
			}
		}
		if (del[0] < A[0] and del[1] < A[1] and del[2] < A[2]) chmin(ans, tot);
	} while (next_permutation(all(ord)));

	if (ans == infl) ans = -1;
	printf("%lld\n", ans);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}







/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
この問題は、前の問題の下位互換ではない。
難易度が上がっている。

どこから考察を始めようかという感じであるが、何か使えそうな性質を探そう。
3種類の操作を1回ずつ行うと、全部-2されるので、大小関係が変化しない。
よって、2種類の操作だけを行うのが最適であると言える。

・・・
んー、いや、こっから、わからん。
どう考えても、だめじゃない？
でも、この問題は★★★であるし、解けるんだろう。
あーわかった。これ発想問題や。
なんもわからん？何を思いつけばいいんや？

（解説を見る）

あーーーーーーーーーーーーっ！！！！！
なるほどすぎる。
ABそれぞれ-1するというのは、大小関係だけを考えると、Cを+1することと考えられる。
あとは、前の問題であるようにmin,mid,maxを全探索して、最適な操作回数を考えていけばいい。
実際には+1しているのではないので、操作回数を覚えておき、全ての数が自然数になっているかを
確認する必要がある。
///////////////////////// writeup2 end */
