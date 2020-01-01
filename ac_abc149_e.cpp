//https://atcoder.jp/contests/abc149/tasks/abc149_e
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














int N; ll M; int A[101010];
//---------------------------------------------------------------------------------------------------
ll getCount(int tot) {
	ll res = 0;
	rep(i, 0, N) {
		int Ay = tot - A[i];
		int idx = lower_bound(A, A + N, Ay) - A;
		res += N - idx;
	}
	return res;
}
//---------------------------------------------------------------------------------------------------
ll As[101010];
ll getSum(int tot) {
	rep(i, 0, N) As[i] = A[i];
	rrep(i, N - 2, 0) As[i] += As[i + 1];

	ll res = 0;
	rep(i, 0, N) {
		int Ay = tot - A[i];
		int idx = lower_bound(A, A + N, Ay) - A;
		int cnt = N - idx;
		res += 1LL * A[i] * cnt;
		res += As[idx];
	}
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N);

	int ok = 0, ng = inf;
	while (ok + 1 != ng) {
		int md = (ok + ng) / 2;
		if (M <= getCount(md)) ok = md;
		else ng = md;
	}

	ll ans = (M - getCount(ok + 1)) * ok + getSum(ok + 1);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
直感的には最大のものからペアで使っていくのが良い。
Ax+Ayを列挙すると10^10通りあるので、列挙するのは現実的ではない。
ここから発想の飛躍がある。
Ax+Ayを列挙して降順ソートしたときのM番目の値が気になる。
この値が分かれば、それ以上となるAx+Ayの値の総和を取るのは、累積和を使えばそんなに難しくない。

M番目の値を得たい。といえば二分探索である。
Ax+Ayの値を二分探索して、M番目の値を特定していこう。
tot≦Ax+Ayである組み合わせがM通り以上という条件を使えば、totについて二分探索できる。

getCount(tot) := tot≦Ax+Ayとなる組み合わせ数
とりあえず、これを求めよう。
Aを昇順ソートしておき、Axを全探索する。
tot-Ax≦Ayとなる個数を数えればいいので、昇順ソートしておけば、O(logN)でその個数は割り出せる。
これの総和を返せば良い。

これを使えばM - getCount(tot-1)個はtotとなる。
あとはtotより大きい数の総和であるが、count関数と同様の感じで求めることができる。
getSum(tot) := tot≦Ax+AyとなるAx+Ayの総和。
Aを昇順ソートしておき、Axを全探索する。
tot-Ax≦Ayとなる個数を数えればいいので、昇順ソートしておけば、O(logN)でその個数は割り出せる。
Axはその個数分足しておき、AyはAで累積和を用意しておけば、区間和で総和が得られる。
これの総和を返せば良い。

実装が大変になるので、関数毎に着実に作って行こう。
///////////////////////// writeup2 end */
