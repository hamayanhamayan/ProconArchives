//https://atcoder.jp/contests/otemae2019/tasks/otemae2019_b
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













int M, N, K, X[2010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> M >> N >> K;
	rep(i, 0, N) cin >> X[i];

	int ans = 0;
	rep(m, 1, M + 1) {
		vector<int> cnt(M + 1);
		rep(i, 0, N) cnt[abs(m - X[i])]++;
		int tot = cnt[0];
		rep(k, 1, K + 1) if (cnt[k]) tot++;
		chmax(ans, tot);
	}
	cout << ans << endl;
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
変数が多く、何か手を付けていいかわからないかもしれない。
こういう時は何かを固定するのがいい。
最も効果的な決め所を探すと、どこに駒を集めるかで全探索してみよう。
これはM通りあり、操作によって、そこに移せるかどうかをO(K+N)で試せばいいので、O(MK)で間に合う。
///////////////////////// writeup2 end */
