//https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_c
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














int N;
vector<int> E[201010];
int ans[201010];
//---------------------------------------------------------------------------------------------------
vector<int> grp[2];
void dfs(int cu, int pa = -1, int col = 0) {
	grp[col].push_back(cu);
	fore(to, E[cu]) if (to != pa) dfs(to, cu, 1 - col);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	dfs(0);

	int A = grp[0].size();
	int B = grp[1].size();

	int one = N / 3; if (1 <= N % 3) one++;
	int two = N / 3; if (2 <= N % 3) two++;
	int thr = N / 3;

	if (A > B) {
		swap(A, B);
		swap(grp[0], grp[1]);
	} // A <= B

	if (two <= A) {
		// grp[0]を全部2にして、残りは3
		int x = 2;
		rep(i, 0, two) ans[grp[0][i]] = x, x += 3;
		x = 1;
		rep(i, 0, one) ans[grp[1][i]] = x, x += 3;
		x = 3;
		rep(i, two, A) ans[grp[0][i]] = x, x += 3;
		rep(i, one, B) ans[grp[1][i]] = x, x += 3;
	}
	else {
		// grp[0]を全部3にする
		int x = 3;
		rep(i, 0, A) ans[grp[0][i]] = x, x += 3, thr--;
		rep(i, 0, thr) ans[grp[1][i]] = x, x += 3;
		x = 1;
		rep(i, 0, one) ans[grp[1][thr + i]] = x, x += 3;
		x = 2;
		rep(i, 0, two) ans[grp[1][thr + one + i]] = x, x += 3;
	}

	rep(i, 0, N) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
条件が少し複雑なので、整理をする。
数が1,2,3,4,...とあるが、和か積が3の倍数というのは、結構満たしそうな感じがする。
3の倍数ということで、条件としては数はmod3で考えればよい。
1,2,3,1,2,3,1,2,3,...というのがあったときに和か積が3の倍数にならないのは、1と1, 2と2の組み合わせだけになる。
つまり、距離が3であって、1と1、2と2があるとだめ。
0,1,2の個数は大体N/3となる。

距離が3であってというのは、少し扱いにくい条件である。
ここで二部グラフを導入する。
木を二部グラフで分けたときに、1が2グループで分かれてしまうと、距離が3になる恐れがある。
二部グラフの性質を見れば、同じグループに入れておけば、距離が奇数にならないことは自明。
よって、1と2はそれぞれ全部同じグループに入れておくように配置できれば、それが答えになる。

二部グラフでサイズAとサイズBに分けることができたとする（A≦B）
Aが2の個数以上であれば、そこに2を全部入れて、もう片方に1を全部入れて、残りに3を入れていけばいい。
Aが2の個数未満であれば、そこに3を全部入れて、もう片方に1と2を全部入れる。
これで適切に構築が可能。
///////////////////////// writeup2 end */
