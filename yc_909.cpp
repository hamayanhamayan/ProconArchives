//https://yukicoder.me/problems/no/909
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














int N, X[201010], Y[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> X[i];
	rep(i, 0, N) cin >> Y[i];

	int ans = inf;
	rep(i, 0, N) chmin(ans, X[i] + Y[i]);
	printf("%d\n", ans);

	printf("0\n");
	rep(i, 0, N) printf("%d\n", min(X[i], ans));
	printf("%d\n", ans);

}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
たぴ1から考えてみると、なるべく離したいので、たぴ0からXiの距離に置きたい。
あと、たぴN+1とも極力離したいので、Yiの距離に置きたい。
すると、Xi+Yiだけの距離ができる。
しかも、これ以上増やすと条件を満たさなくなるので、答えはXi+Yi以下になる。
すべての条件について考えると、すべてのたぴについて条件を満たす答えの中で最大のものは、Xi+Yiの最小値となる。
よって、それが答えansになる。

そこからの復元はたぴ0が座標0, たぴN+1が座標ansである。
たぴiは基本はXiの位置に置けばいいが、Xiがansを超えている場合はansに置けばいい。
///////////////////////// writeup2 end */
