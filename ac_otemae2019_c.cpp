//https://atcoder.jp/contests/otemae2019/tasks/otemae2019_c
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













int N, A[101010], B[101010];
int cntA[101010], cntB[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) cin >> B[i];

	rep(i, 0, N) cntB[B[i]]++;

	int ans = inf;
	rep(i, 0, N) {
		int a = A[i];
		cntA[a]++;
		chmin(ans, cntB[a] / cntA[a]);
		printf("%d\n", ans);
	}
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
カード列Bを使って、Ciを何個作れるかという問題であるが、カード列Bは毎回並び替えるので、特に順番は関係ない。
関係あるのは、とあるカードが何枚あるかである。
これを元に考えると、各iでの答えは、すべての数について、ある数が(Bで登場する回数)/(C[i]で登場する回数)の最小値が答えになる。
ここまでくれば、解法自体は簡単。
Bで登場する回数は変わらず、iが増えるごとにC[i]で登場する回数の追加になる数の個数が増えるだけなので、
これを計算して、個数の最小値を更新すると答えになる。
///////////////////////// writeup2 end */
