//https://yukicoder.me/problems/no/1110
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














int N, D, A[201010], sorted[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> D;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N) sorted[i] = A[i];
	sort(sorted, sorted + N);

	rep(i, 0, N) {
		int ans = upper_bound(sorted, sorted + N, A[i] - D) - sorted;
		printf("%d\n", ans);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
## 条件の言い換え
条件を少し言い換えよう。
iについて全探索して、jを数え上げるので、A[i]は固定になるので、固定じゃないjについて簡単にする。
A[i] - A[j]≧D
A[i] - D≧A[j]
とすると、求めるべきjはA[j]がA[i] - D以下であるものである。
これはどう求めるべきだろうか。

## ソート済み配列と二分探索
これはソート済み配列を別途用意していれば、高速に取得可能である。
配列Aを別の配列に移してソートしておこう。（sorted配列）
これに対して二分探索をすることで、A[i] - D以下である境界線を見つけることができる。
二分探索を自前で書いてもいいが、C++であればlower_bound, upper_boundという関数がある。
upper_boundでA[i]-Dより大きい要素の添え字をもらってくれば、それがそのまま答えになる。
///////////////////////// writeup2 end */
