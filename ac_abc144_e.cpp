//https://atcoder.jp/contests/abc144/tasks/abc144_e
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














int N; ll K;
int A[201010], F[201010];
//---------------------------------------------------------------------------------------------------
bool check(ll ma) {
	ll cnt = 0;
	rep(i, 0, N) {
		int ok = 0, ng = A[i] + 1;
		while (ok + 1 != ng) {
			int md = (ok + ng) / 2;
			if (1LL * md * F[i] <= ma) ok = md;
			else ng = md;
		}
		cnt += A[i] - ok;
	}
	return cnt <= K;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) cin >> F[i];

	sort(A, A + N);
	sort(F, F + N, greater<int>());

	ll ng = -1, ok = infl;
	while (ng + 1 != ok) {
		ll md = (ng + ok) / 2;
		if (check(md)) ok = md;
		else ng = md;
	}
	cout << ok << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
///////////////////////// writeup2 start
まず、最大値の最小化ということで二分探索かというところ。
最大値が決まっていれば、各メンバーについて何回修行が必要かわかれば良さそう。
ここで、エスパーをする必要がある。
Aを昇順ソート、Fを降順ソートして、A[i]*F[i]とマッチングさせるのが、最適。
これで割当順が決まったので、更にソートを行い、A[i]を減らしてA[i]*F[i]≦最大値となるようにする。
修行回数がK回以下なら、その最大値を達成可能なのでtrue
///////////////////////// writeup2 end */
