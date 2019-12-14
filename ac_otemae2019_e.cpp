//https://atcoder.jp/contests/otemae2019/tasks/otemae2019_e
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













int N, Q; ll D[501010], T[501010], L[501010], R[501010];
int ans[501010];
//---------------------------------------------------------------------------------------------------
int get(ll top, ll L, ll R, vector<ll> &ds) {
	// T - R≦D[i]≦T - L

	int lft = lower_bound(all(ds), top - R) - ds.begin();
	int rht = upper_bound(all(ds), top - L) - ds.begin();

	int res = rht - lft;
	if (L <= top and top <= R) res++;

	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> Q;
	rep(i, 0, N) cin >> D[i];
	rep(i, 0, Q) cin >> T[i] >> L[i] >> R[i];

	rep(i, 1, N) D[i] += D[i - 1];

	vector<int> ord;
	rep(i, 0, Q) ord.push_back(i);
	sort(all(ord), [&](int a, int b) {return T[a] < T[b]; });

	int moved = 0;
	vector<ll> ds;
	rep(_q, 0, Q) {
		int q = ord[_q];

		while (moved < N and D[moved] <= T[q]) {
			ds.push_back(D[moved]);
			moved++;
		}

		ans[q] = get(T[q], L[q], R[q], ds);
	}

	rep(q, 0, Q) printf("%d\n", ans[q]);
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
問題を整理すると、校長がまず出発して、先頭から順番に前との距離がある一定の距離になったら歩き出すような
入場でよくあるルールで動き出すことがわかる。
重要な性質として、いったん動きだすと、先頭からの距離は一定となり続け、それまではずっと動き出さないということ。
そのため、動き出すタイミングは累積和を使って校長からの距離としておくと、ちょうどそれが動き出す時間になるので
都合がいい。

そして、問題として問われている区間にあるのは動いている人だけとなる。
そのため、クエリをTでソートし、クエリを処理していくにつれて、移動している人をどんどん増やしていくようにしていく。
区間にどれだけの人が含まれるかは、校長からの距離は不変なので、それを作っていく。
その配列は単調増加になるので、二分探索することで、指定の区間にどれだけの人がいるかは取得できる。
これで解いていこう。実装が大変。

先頭がTだけ移動していて、[L,R]の範囲にある人は、
T - D[i]だけそれぞれ移動しているので、
L≦T-D[i]≦R
を満たせばいいので、
L - T≦-D[i]≦R - T
T - R≦D[i]≦T - L
を満たすD[i]の個数を調べればいい。
///////////////////////// writeup2 end */
