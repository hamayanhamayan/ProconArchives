//https://atcoder.jp/contests/kupc2019/tasks/kupc2019_g
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














int N, H, W;
//---------------------------------------------------------------------------------------------------
void solve() {
	vector<string> ans(4);

	ans[0] = "ABCA";
	ans[1] = "BCAB";
	ans[2] = "CABC";
	ans[3] = "ABCA";

	rep(y, 0, 4) {
		rep(x, 0, W - 4) {
			ans[y] += ans[y][3];
		}
	}

	rep(y, 0, 4) printf("%s\n", ans[y].c_str());
	rep(y, 0, H - 4) printf("%s\n", ans[3].c_str());
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) {
		cin >> H >> W;
		solve();
	}
}





/* ///////////////////////// writeup1 start
# ジャンル
- [構築](https://www.hamayanhamayan.com/entry/2017/08/21/102212)
///////////////////////// writeup2 start
そういう作り方の構築は初めて見たかもしれない。

最小は4×4なので、とりあえずこれから作ってみるが、もう作ってある。
だが、大体、サンプルは規則性を隠ぺいして作ってあるので、規則的を目指して自分でも構築する。

```
ABCA
BCAB
CABC
ABCA
```

ここから横に1つ伸ばす

```
ABCA?
BCAB?
CABC?
ABCA?
```

ここには横と同じものを書けばいい

```
ABCAA
BCABB
CABCC
ABCAA
```

すると各ペア2つだけ増える。
縦に1つ伸ばす。

```
ABCAA
BCABB
CABCC
ABCAA
?????
```

これも横と同じものを書けばいい。

```
ABCAA
BCABB
CABCC
ABCAA
ABCAA
```

これも各ペア2つずつ増える。
これを繰り返していくのだが、最終的には

```
ABCAAAA
BCABBBB
CABCCCC
ABCAAAA
ABCAAAA
ABCAAAA
ABCAAAA
```

こんな感じのやつを構築すれば答え。
インクリメンタルに作ってく感じは初めてかもー。
///////////////////////// writeup2 end */
