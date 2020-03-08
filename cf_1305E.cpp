//https://codeforces.com/contest/1305/problem/E
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














int N, M;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	
	vector<int> ans;
	rep(i, 1, N + 1) {
		int d = max(0, (i - 1) / 2);

		if(d <= M) ans.push_back(i), M -= d;
		else {
			rep(_, 0, d - M) i += 2;
			M = 0;
			ans.push_back(i);
			break;
		}
	}

	if (0 < M) {
		printf("-1\n");
		return;
	}

	int banhei = 201010, delta = 100000;
	while (ans.size() <= N) {
		ans.push_back(banhei);
		banhei += delta;
	}

	rep(i, 0, N) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
# 参考
- [構築問題](https://www.hamayanhamayan.com/entry/2017/08/21/102212)
///////////////////////// writeup2 start
構築問題に取り組む一歩として使える方針として極端な例を考えるというものがある。
今回で言うと、与えられたNに対してMを最大化するにはどのような配列を考えればいいかという感じ。
これは
```
1 2 3 4 5 ... N
```
とすることで最大化できる。
ある要素xについて、他の要素を足してその要素になれる組み合わせは、(x - 1) / 2切り捨てとなる。
これはそれ以前の要素について端から順にペアにしてくような感じ。
これをベースとして構築していくのがよさそうだ。
先頭から、1 2 3と配置していく。
組み合わせは(x - 1) / 2となるので、これがOKなら、Mを減らしながら置いていく。
(x - 1) / 2がMを超えてしまったら、調整が必要だ。
これはどうしようか。

もうすでに置いている所をいじるのはかなり面倒。今置こうとしている数をいじることで調整できないだろうか。
```
1 2 3 4 5 6 7 8 9
```
これが置かれていて、10を置くことを考える。この10を+1していきながら、組み合わせを見てみよう。

```
10 -> 4通り
11 -> 4通り
12 -> 3通り
13 -> 3通り
14 -> 2通り
15 -> 2通り
16 -> 1通り
17 -> 1通り
```

これを見てもわかるし、実験していると、あーそういうことみたいな感じにもなってくる。
+2すると、組み合わせが-1になる。
これはかなり調整しやすい。
なので、これをやる。
数式でやってもいいが、ループでやっても十分間に合う。

これをやっていき、N個おいてもMが残っていれば-1だし、N個分置けなかった場合はMを増やさないように
適当に数を置けば答え。
自分は初項201010、公差100000の等差数列を置いた。
10^9に収まるか心配なら、N=5000, M=0で確かめておくといい。
///////////////////////// writeup2 end */