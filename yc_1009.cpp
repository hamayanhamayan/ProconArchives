//https://yukicoder.me/problems/no/1009
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














double a, b;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> a >> b;

	double ans = 0;
	rep(i, 0, 1010101) {
		double d = (b - a) / 1010101;
		double x = a + (b - a) * i / 1010101;
		ans += abs((x - a) * (x - b)) * d;
	}
	printf("%.10f\n", ans);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ヒントとして書かれている区分求積法を実装することで答えた。
座標が微妙にずれている気もするが、誤差の範囲に収まってくれるだろう。
10^4くらいの分割でよさそうだが、念のため10^6で分割しておいた。

余談であるが、いつも10^6みたいな数を書くときに1010101のように書いている。
ピッタリよりもマージンをとっておいたほうが、配列を作ったときに更新でちょっと便利になったり、
桁が見やすいといった効果がある。
後者は、桁区切り文字を使ってもいいんだけど、なんとなく入力のしやすさからこっちを使ってる。
[C++14 数値リテラルの桁区切り文字 - Faith and Brave - C++で遊ぼう](https://faithandbrave.hateblo.jp/entry/20131007/1381128629)
///////////////////////// writeup2 end */
