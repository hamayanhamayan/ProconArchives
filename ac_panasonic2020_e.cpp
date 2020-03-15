//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_e
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















vector<bool> matching(string x, string y) {
	int nx = x.size();
	int ny = y.size();

	vector<bool> res(6010, true);
	rep(st, 0, nx) {
		for (int i = 0; st + i < nx && i < ny; i++) {
			if (x[st + i] == '?') continue;
			if (y[i] == '?') continue;
			if (x[st + i] != y[i]) res[st] = false;
		}
	}

	return res;
}
//---------------------------------------------------------------------------------------------------
int solve(string A, string B, string C) {
	int na = A.size();
	int nb = B.size();
	int nc = C.size();

	auto ab = matching(A, B);
	auto bc = matching(B, C);
	auto ac = matching(A, C);

	int ans = inf;
	rep(a, 0,  na + 1) rep(b, 0, max(na, nb) + 1) if (ab[a] && bc[b] && ac[a + b]) {
		chmin(ans, max({ na, a + nb, a + b + nc }));
	}
	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	vector<string> v;
	rep(i, 0, 3) {
		string s; cin >> s;
		v.push_back(s);
	}
	sort(all(v));

	int ans = inf;
	do {
		chmin(ans, solve(v[0], v[1], v[2]));
	} while (next_permutation(all(v)));
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
どこから考えるべきかであるが、自分はDPから考え始めてしまった。
既視感のある問題だし、自然かなとも思うが、この流れは間違いなので、捨てないといけない。

重要な方針として、A,B,Cのサイズが最大2000なので、N=max(A,B,C)としておくと、O(N^2)が答えになるだろうという方針がある。
まだまだこれだけでは方針が絞り切れない。
答えの上限はA+B+Cとした文字列であることは、言える。
つまり、最適な答えは、A,B,Cがある程度重なっているものになっている。
この重なりは全探索できるのではないか？
しかも、この組み合わせはO(N^2)だ。

文字列中にA,B,Cが出てくる順番を固定する。A≦B≦Cの順番で出てくるとしよう。
雰囲気は、以下の図みたいな感じ。
```
AAA
 BBB
  CCC
```
A,B,Cの順番は6通りしかないので、全部試して答えの最小値を取ればいい。
solve(A, B, C) := ABCがこの順番で出てくるときの目的の文字列の最短値

Bの位置はAの先頭からの相対的な位置と考えれば全探索ができる。
Cの位置もBの先頭からの相対的な位置と考えれば全探索ができる。
後は、範囲であるが、Bの位置はAの先頭から[0,|A|]の範囲だけずらしたものを考えればいい。
Cの位置はBの先頭から[0,|A|+|B|]の範囲だけずらしたものを考えるといい。
（これは範囲が実質多めです）
[0,|B|]でよさそうなものだが、これにはコーナーケースが存在する。

```
xaaxbbx
aa
bb
```

これで答えとなる可能性のある文字列の構成について全列挙できるようになった。
あとは、その構成が実現可能かを判別する。
事前に以下の配列を作っておくことで、O(1)で判定ができる。
ab[a] := 文字列Bを文字列Aの先頭からaだけずらした場合、重なっている部分について?をうまく変換して同じ文字列にできるか
bc[b] := 文字列Cを文字列Bの先頭からbだけずらした場合、重なっている部分について?をうまく変換して同じ文字列にできるか
ac[a] := 文字列Cを文字列Aの先頭からaだけずらした場合、重なっている部分について?をうまく変換して同じ文字列にできるか
これらは同じアルゴリズムで構築ができる。
それぞれ、ずらす組み合わせO(N)で、判定は愚直に見ていってO(N)なので、全体O(N^2)でできる。
判定で便利に使えるように6000くらいずらしたものまで計算しておこう。
その場合、以下のような場合を全部trueとして考えることになる。

```
AAA
     BBB
```

あとは、頑張って実装する。
///////////////////////// writeup2 end */
