//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d
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
//---------------------------------------------------------------------------------------------------
string buf = "";
void dfs(int cu) {
	if (cu == N) {
		printf("%s\n", buf.c_str());
		return;
	}

	char biggest = 'a';
	while (buf.find(biggest) != string::npos) biggest++;
	biggest--;

	for (char c = 'a'; c <= biggest + 1; c++) {
		buf.push_back(c);
		dfs(cu + 1);
		buf.pop_back();
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;

	dfs(0);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [枝刈り全探索](https://www.hamayanhamayan.com/entry/2017/12/23/155922) （ちょっと違う気もするけど、感覚は似ている）
///////////////////////// writeup2 start
問題の定義が少し複雑に感じるかもしれない。
こういうときは、つまりこういうことができればいいというのを考えるといい。
操作が複雑な問題とか、条件が多い問題とか、そういう問題でもこういう方針から入る。

今回は頑張って例を出しながら考えていくと、
先頭から文字を追加していくが「追加するのに使えるのは'a'～今まで使われた文字の次の文字」というのを満たす文字列の全列挙である。
例を出すと、最初は`a`だけOK。
2つ目は、今までaが出ているので、aから次のbまで使える。よって、`aa`と`ab`。
`aa`に追加する3つ目は、今までaが出ているので、aから次のbまで使えるので、`aaa`と`aab`。
`ab`に追加する3つ目は、今までabが出ているので、aから次のcまで使えるので、`aba`, `abb`, `abc`となる。
これを繰り返していく。

これを全部列挙すると、O(N!)通りになる。
これは1つ目は最大1択で、2つ目は最大2択で、3つ目は最大3択で、全部最大として考えるとN!通りとなるためである（実際はそれより少ない）。
10!は3*10^6くらいで、実際はそれより少ないので、まあ行けるんじゃないかなーと思える。

後は、実装であるが、先頭から順番に決めていくのでdfsを使う。
dfsを使って重複順列を全列挙したことがある人は、感覚がつかめるだろう。
そっちで感覚をつかんだほうが、こちらに導入しやすいかもしれない。

dfsでは毎回最大の文字を求めて、'a'から最大+1までを後ろに追加する操作を繰り返していく。
///////////////////////// writeup2 end */
