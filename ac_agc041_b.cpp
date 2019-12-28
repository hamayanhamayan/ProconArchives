//https://atcoder.jp/contests/agc041/tasks/agc041_b
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














int N, M, V, P, A[101010];
//---------------------------------------------------------------------------------------------------
bool check(int i) {
	int bigger = 0, less = 0;
	ll other = 0;
	rep(j, 0, N) if (j != i) {
		if (A[i] + M < A[j]) bigger++;
		else if (A[j] <= A[i]) less++;
		else other++;
	}

	if (P <= bigger) return false;
	
	ll rest = V - 1 - bigger - less;
	if (rest <= 0) return true;

	ll tot = 0;
	ll cnt = 0;
	rep(j, 0, N) if (A[i] < A[j] and A[j] <= A[i] + M) {
		tot += A[i] + M - A[j];
		
		cnt++;
		ll ok = min({ tot / M, other, rest });
		ll ng = rest - ok;
		if (bigger + ng < P and cnt + ng <= other) {
			return true;
		}
	}

	return false;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> V >> P;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N);

	int ng = -1, ok = N;
	while (ng + 1 != ok) {
		int md = (ng + ok) / 2;
		if (check(md)) ok = md;
		else ng = md;
	}

	int ans = N - ok;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
///////////////////////// writeup2 start
Aをソートしておくと、実は採用されるかどうかは単調性を持つ。
A[i]が採用されるのであれば、A[i+1]も採用されることが言える。
よって、二分探索をしよう。

check(i) := A[i]が採用される可能性があるか

とりあえず、M人はみんなA[i]に投票する。
これでA[i]+Mという基準ができる。

まず、A[i]+Mよりも大きい問題の個数がP以上であれば、A[i]がP位以内に入ることはできない。

M人はV-1問を選んでスコアを上げることになる。
だが、なるべくA[i]+M未満のスコアは上げたくない。
しかし、これよりも大きいスコアのものはどうなってもいい。
なので、A[i]+Mよりも大きい要素がbigger個ある場合は、これもスコアを上げる。
これで、M人はV-1-bigger問をあとは選ぶ。

A[i]以下の要素についても、実は選んでも問題ない。
M人全員がそれに投票してもA[i]+Mより大きくならないからである。
この個数がless個であるとすると、M人はV-1-bigger-less問をあとは選ぶことになる。
rest = V-1-bigger-lessとしておこう。

さて、これで残ったある区間[L,R)に対してM人がrest問に対して適切に投票することで、
A[i]+Mを超える要素を最小化するという問題が残る。
これはA[i]+M以下で抑える人数がok人であるとすると、小さい方から順に余裕のある分、
つまりA[i]+M-A[j]の分だけ投票を受け持っていく。
受け持った分の総和/Mをすると処理できる問題が分かり、処理できない分は後ろでA[i]+Mが超える部分が出てくる。。
担当していくときに、A[i]+Mよりも大きい問題の個数がP以上なものはだめ。
大きい問題の個数がP未満となるものがあればtrueを返す。
///////////////////////// writeup2 end */
