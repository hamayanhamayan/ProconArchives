//https://atcoder.jp/contests/abc165/tasks/abc165_c
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














int N, M, Q, a[50], b[50], c[50], d[50];
//---------------------------------------------------------------------------------------------------
int ans = 0;
int A[10];
void dfs(int cu = 0, int lst = 1) {
	if (cu == N) {
		int tot = 0;
		rep(i, 0, Q) if (A[b[i]] - A[a[i]] == c[i]) tot += d[i];
		chmax(ans, tot);
		return;
	}

	rep(nxt, lst, M + 1) {
		A[cu] = nxt;
		dfs(cu + 1, nxt);
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> Q;
	rep(i, 0, Q) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; b[i]--;
	}

	dfs();
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
メタ読みをする。
制約を見ると、数列Aの全探索ができそうな感じ。
dfsを使って数列を全探索していこう。
dfsを使った数列の全探索方法が分からない場合は、そちらを先に学ぶといいかもしれない。
[重複順列 dfs - Google 検索](https://www.google.com/search?q=%E9%87%8D%E8%A4%87%E9%A0%86%E5%88%97+dfs&oq=%E9%87%8D%E8%A4%87%E9%A0%86%E5%88%97+dfs&aqs=chrome..69i57j0l3.5671j1j1&sourceid=chrome&ie=UTF-8)
重複順列として考えると、10^10で間に合わないが、広義単調増加である制約があるので、前の要素以下を列挙しないようにすると大丈夫。
このように全探索をするが、必要ない部分についての遷移を削減することを枝刈りと良い、枝刈り全探索というテクもある。

あとは、広義単調増加である数列Aすべてに対してスコアを計算して最大値を求めると答え。
///////////////////////// writeup2 end */
