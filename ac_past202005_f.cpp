//https://atcoder.jp/contests/past202005-open/tasks/past202005_f
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












int N;
string S[505];
//---------------------------------------------------------------------------------------------------
string solve() {
	string pre = "";
	rep(i, 0, N / 2) {
		set<char> s1, s2;
		rep(x, 0, N) s1.insert(S[i][x]);
		rep(x, 0, N) s2.insert(S[N - 1 - i][x]);

		rep(_c, 0, 26) {
			char c('a' + _c);
			if (s1.count(c) && s2.count(c)) {
				pre += c;
				break;
			}
		}
	}

	if (pre.size() != N / 2) return "-1";

	string post = pre;
	reverse(all(post));

	if (N % 2 == 1) return pre + S[N / 2][0] + post;
	return pre + post;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> S[i];
	cout << solve() << endl;
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
たぶん、競技プログラミングをやってこないと回文を扱うプログラムを書いたことは無いだろうと思う。
まあそれはいいとして、回文ではabcdcbaのように鏡写しのような文字列になる。
鏡写しなので、先頭から1番目が決まれば、末尾から1番目が決まる。
2番目が決まれば、2番目が決まる。
加えて重要なのが、決まる組の間では同じである必要性があるが、決まる組と決まる組の間は独立に考えることができる。
よって、(先頭から1番目,末尾から1番目)の文字、(先頭から2番目,末尾から2番目)の文字、…を順番に確定させていこう。

先頭からi番目、末尾からi番目の文字をどうするかであるが、文字は26種類しかないので、
全ての文字について使用できるかを判定すればいい。
s1 := 先頭からi番目の文字列で使用されている文字の集合
s2 := 末尾からi番目の文字列で使用されている文字の集合
というのをあらかじめ作っておくと、ある文字が含まれるかを素早く判定できる。
含まれていれば採用する。

自分の実装では前半部分だけ答えを作って、後半部分は前半を反転させてくっつけている。

注意点として、Nが奇数の場合は真ん中の文字だけペアがないので、適当に先頭の文字列を使っている。
///////////////////////// writeup2 end */
