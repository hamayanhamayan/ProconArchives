//https://atcoder.jp/contests/past201912-open/tasks/past201912_m
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













int N, M, A[1010], B[1010], C[101], D[101];
//---------------------------------------------------------------------------------------------------
bool check(double strong) {
	vector<double> normal, helper;
	rep(i, 0, N) normal.push_back(B[i] - strong * A[i]);
	sort(all(normal), greater<double>());
	rep(i, 0, M) helper.push_back(D[i] - strong * C[i]);
	sort(all(helper), greater<double>());

	double sm = 0;
	rep(i, 0, 5) sm += normal[i];
	if (0 <= sm) return true;

	sm = 0;
	rep(i, 0, 4) sm += normal[i];
	sm += helper[0];
	if (0 <= sm) return true;

	return false;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i] >> B[i];
	rep(i, 0, M) cin >> C[i] >> D[i];

	double ok = 0, ng = inf;
	rep(i, 0, 200) {
		double md = (ok + ng) / 2;
		if (check(md)) ok = md;
		else ng = md;
	}
	printf("%.13f\n", ok);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
分数の形の最大化といえば、二分探索が思いつく。
とりあえず、こちらの方針で考えてみる。
強さをstrong以上にできるかというのを考える。

お助けモンスターの話があるが、難しいので、とりあえず通常モンスター5体での最大化を考える。
モンスターabcdeを選んだとすると、
(B[a]+B[b]+B[c]+B[d]+B[e])/(A[a]+A[b]+A[c]+A[d]+A[e])≧strong
を考えればいい。
これを変形すると、
(B[a]+B[b]+B[c]+B[d]+B[e])≧strong(A[a]+A[b]+A[c]+A[d]+A[e])
(B[a]+B[b]+B[c]+B[d]+B[e])-strong(A[a]+A[b]+A[c]+A[d]+A[e])≧0
(B[a]-strongA[a]) + (B[b]-strongA[b]) + (B[c]-strongA[c]) + (B[d]-strongA[d]) + (B[e]-strongA[e]) ≧ 0
これを見ると、それぞれ独立に考えることが、できそうでB[i]-strongA[i]が大きいものを貪欲に5つ持ってくれば、
総和が0以上となる確率が最大化される。
よって、これを計算してソートして、先頭5つを取ってきて、0以上であればtrueとなる。

お助けモンスターの時も同様の計算をして、通常モンスターの先頭4つと、お助けモンスターの先頭1つを足して0以上かを見ればいい。
///////////////////////// writeup2 end */
