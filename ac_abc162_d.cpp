//https://atcoder.jp/contests/abc162/tasks/abc162_d
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














int N; string S;
int R = 1, G = 2, B = 4;
int RGB = 7;
int cnt[8];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;
	fore(c, S) {
		if (c == 'R') c = R;
		else if (c == 'G') c = G;
		else c = B;
	}

	int r = 0, g = 0, b = 0;
	ll ans = 0;
	rep(j, 0, N) {
		rep(k, j + 1, N) {
			if (S[j] == S[k]) continue;

			int Si = RGB - S[j] - S[k];
			ans += cnt[Si];

			int i = j - (k - j);
			if (0 <= i) {
				int msk = S[i] | S[j] | S[k];
				if (msk == RGB) ans--;
			}
		}

		cnt[S[j]]++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
メタ戦略で考察を始める。
N≦4000なので、O(N^2)が通る。
選択肢は3つあるので、2つを全探索して、1つは最適方針かな？ということで考える。
j,kを全探索したときにiの探索を効率化して解くことを考える。

S[j] != S[k]である必要が最低ある。
すると、S[i]として必要なのは、S[j]とS[k]以外なので、文字は確定する。
これで条件を満たすiは
- S[i]がS[j],S[k]以外
- i<j
- j-i != k-j
である。
一番下が厄介で、これをどうするかが壁となる。

上2つだけを満たす組み合わせを数えたいとすると、j未満の要素に対して、RGBの個数をそれぞれ数えておけば、
その個数分組み合わせがあることになる。
なので、その総和をとれば答え。

一番下は差分を使って計算する。
上のやり方では、「j-i = k-jなんだけど、文字が異なるもの」もダブって数えてしまっている。
だが、このパターンにはまるのは1パターンだけなので、全部を計算した後に、
「j-i = k-jなんだけど、文字が異なるもの」があれば答えから-1することにする。
これも要素を見て、確認するだけなので、そんなに難しくない。

アルゴリズムは以上のような感じだが、実装に戸惑うかもしれない。
自分はビットマスクを使うことで実装した。
ゴリゴリ場合分けでも問題ないが、N≦4000だと少し計算量には気を付けた方がいい。
///////////////////////// writeup2 end */
