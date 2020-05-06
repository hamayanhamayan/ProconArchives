//https://atcoder.jp/contests/past202004-open/tasks/past202004_g
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














int Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> Q;

	deque<pair<char, int>> deq;

	rep(_, 0, Q) {
		int t; cin >> t;
		if (t == 1) {
			char c; int x; cin >> c >> x;
			deq.push_back({ c, x });
		}
		else {
			int d; cin >> d;

			map<char, int> del;
			while (0 < d) {
				if (deq.size() == 0) break;

				auto p = deq.front(); deq.pop_front();

				int de = min(d, p.second);
				del[p.first] += de;
				p.second -= de;
				d -= de;

				if (0 < p.second) deq.push_front(p);
			}

			ll ans = 0;
			fore(p, del) ans += 1LL * p.second * p.second;
			printf("%lld\n", ans);
		}
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
この問題は実装が重い問題である。
愚直に文字列を追加する解法では、文字列の長さが10^10とかになってしまうので、TLE。
だが、方針としては間違っていない。
今回の問題は与えられた操作をデータ構造を駆使して高速にさばいていくことが要求される。

文字列の追加も削除も愚直にやると間に合わない。
これを、どのように高速化するかであるが、高速化に使えそうな性質は、同じ文字が連続するという部分である。
ランレングス表現というのを知っていれば、解法をいくらか思いつきやすいかもしれない。
ランレングス表現とは、(文字,個数)の組を保持しておくことで、長い文字列を圧縮する表現方式である。
今回はこのランレングス表現を保ちながら操作を行っていくことにしよう。

問題では末尾に追加、先頭から削除と先頭も末尾も操作があるので、dequeを使おう。
dequeはqueueの操作を両端から行えるようにしたもので、先頭・末尾に対してpush,popが行える。

dequeには(文字,個数)を入れることにする。
T=1の時は、dequeの末尾に(C[i], X[i])を入れるだけでいい。

T=2の時は、dequeの先頭から(文字,個数)を取り出して処理していく。
個数がD[i]未満であれば、先頭から(文字,個数)を取り出すが、何個かは戻さないといけないので、
(文字,個数-D[i])を先頭に入れなおす。
個数がD[i]以上であれば、先頭は全部使うので、取り出して、「D[i] -= 個数」をしておく。
これらの操作をやりながら、「del[i] := 文字iが何個削除されたか」も数えながらやる。
あとは、del[i]の二乗の総和を取って答える。

実装がちょっと大変。
///////////////////////// writeup2 end */
