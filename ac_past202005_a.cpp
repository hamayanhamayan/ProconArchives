//https://atcoder.jp/contests/past202005-open/tasks/past202005_a
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















string s, t;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> s >> t;

	if (s == t) {
		cout << "same" << endl;
		return;
	}

	transform(all(s), s.begin(), [](char c) {return tolower(c); });
	transform(all(t), t.begin(), [](char c) {return tolower(c); });

	if (s == t) cout << "case-insensitive" << endl;
	else cout << "different" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
PASTではややおなじみである気がするが、ABCのA問題級が最初に来ることはあまりない。
ちょっとばかりのややこしさがある問題が出てくる。

FizzBuzz問題のように判定順番が重要になる。
まず最初に完全一致するかを判定しよう。
他を先に判定しまうと誤判定する恐れがある。

完全一致しない場合は、大小を無視した一致か不一致なので、文字列の大小を考えない状態にしたい。
これは各言語でどうやるかは分かれる所。
pythonなら一瞬だったと思うが、C++の場合はtransformを使うのがオススメ。
`transform(all(s), s.begin(), [](char c) {return tolower(c); });`
のように書くのだが、このように書くと、各文字に対してtolower関数を適用してくれるので、
文字列をすべて小文字に標準化することができる。
この状態でsとtを比較して同じなら、大小を無視した一致となる。

そうでもないなら、不一致。
///////////////////////// writeup2 end */
