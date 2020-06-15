//https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_d
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












int LIM = 10;
int N, V[1 << 19], W[1 << 19], Q;
//---------------------------------------------------------------------------------------------------
vector<pair<int, int>> memo[1 << 18];
void naive(int cu, vector<int>& arr) {
	if (memo[cu].size() != 0) return;

	int n = arr.size();
	map<int, int> dp;
	rep(msk, 0, 1 << n) {
		int val = 0, wei = 0;
		rep(i, 0, n) if (msk & (1 << i)) {
			val += V[arr[i]];
			wei += W[arr[i]];
		}
		chmax(dp[wei], val);
	}

	fore(p, dp) memo[cu].push_back(p);
	int ma = -inf;
	fore(p, memo[cu]) {
		chmax(ma, p.second);
		p.second = ma;
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 1, N + 1) cin >> V[i] >> W[i];
	cin >> Q;
	rep(_, 0, Q) {
		int v, L; cin >> v >> L;
		
		int v2 = v;
		vector<int> arr;
		while (1 <= v2) {
			arr.push_back(v2);
			v2 /= 2;
		}

		int n = arr.size();
		if (n <= LIM) {
			naive(v, arr);

			int ans = 0;
			auto idx = upper_bound(all(memo[v]), make_pair(L, inf)) - memo[v].begin();
			if (0 < idx) {
				ans = memo[v][idx - 1].second;
			}
			printf("%d\n", ans);
		}
		else {
			vector<int> arr2;
			rep(i, n - LIM, n) arr2.push_back(arr[i]);
			int p = arr[n - LIM];
			naive(p, arr2);

			int m = n - LIM;
			int ans = 0;
			rep(msk, 0, 1 << m) {
				int val = 0, wei = 0;
				rep(i, 0, m) if (msk & (1 << i)) {
					val += V[arr[i]];
					wei += W[arr[i]];
				}

				auto idx = upper_bound(all(memo[p]), make_pair(L - wei, inf)) - memo[p].begin();
				if (0 < idx) chmax(ans, memo[p][idx - 1].second + val);
			}
			printf("%d\n", ans);
		}

	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [半分全列挙](https://www.hamayanhamayan.com/entry/2018/01/06/112704)
///////////////////////// writeup2 start
だいぶ難しい問題。
ナップサックを半分全列挙で解く解法があるが、それを見たことないと結構難しい。
加えて、今回は制約が厳しめなので、言語によっては通すのが難しいかもしれない。

まず、半分全列挙が分からないと難しいので、どこかで学んでこよう。
半分全列挙が分かればナップサックを半分全列挙で解く方法は、割と思いつくと思う。
品物を2グループに分けて、どっちも全列挙して、どっちかを全探索しながら、もう片方の最適を取ってくる感じ。
[D - ナップサック問題](https://atcoder.jp/contests/abc032/tasks/abc032_d)
ここに類題があるから、これの解説とかを見てもいいかもしれない。

これが分かっていれば各クエリ毎にそれをやるだけとなる。
実際これをやると、O(Q 2^(logN/2) logN)くらいになると思う。
だが、これを実際に通すのは厳しくて、定数倍高速化とか閾値を変えるとかする必要がある。

頂点vから根までの頂点が以下のようになっていたとする。
v - a - b - c - ... - 1
これで半分全列挙するとしたときに、前半と後半で2グループに分けることにする。
そして、ここからが重要であるが「後半のグループのサイズを固定しておく」
最大18個なので9個を後半のグループのサイズとして固定しておく。
すると、半分全列挙するのだが、後半部分は同じになればメモ化をすることができる。
このメモ化を行うことで、たぶん二倍くらい早くなる。

自分はこれだけでは通らなくて、半分全列挙のサイズを調整して通した。
後半のサイズを9個としていたが、通したサイズは10個としている。
前半後半のグループに分けたときに前半の方が重めだったので、後半のサイズを大きくしておいた。
前半はたぶん2^20くらいの計算量くらいで、まだ攻めれるかなくらいになる。
///////////////////////// writeup2 end */
