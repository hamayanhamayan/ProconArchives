//https://atcoder.jp/contests/abc150/tasks/abc150_c
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














int N, P[8], Q[8];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> P[i];
	rep(i, 0, N) cin >> Q[i];
	
	vector<int> v;
	rep(i, 0, N) v.push_back(i + 1);
	int idx = 0, a = -1, b = -1;
	do {
		bool ok = true;
		rep(i, 0, N) if (v[i] != P[i]) ok = false;
		if (ok) a = idx;

		ok = true;
		rep(i, 0, N) if (v[i] != Q[i]) ok = false;
		if (ok) b = idx;

		idx++;
	} while (next_permutation(all(v)));

	int ans = abs(a - b);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
パット見て難しい問題に見えるかもしれない。
この問題は制約から解法を考えていく問題である。

問題の解法を考えるときに、全探索できるかを考えるのは、基本である。
今回のN!通りの8!通りは4*10^4通りくらいであり、これは全探索可能。
10^5通りくらいまでは全探索でき、10^6くらいまでギリいけるときがある感じに思っているといい。

さて、あとはどうやって全探索するかであるが、
C++には順列を辞書順で小さい方から全探索する関数がある。
C++でnext_permutationを使ってやると簡単に実装できる。
///////////////////////// writeup2 end */
