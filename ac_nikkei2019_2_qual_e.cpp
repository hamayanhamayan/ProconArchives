//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_e
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














int N, K;
//---------------------------------------------------------------------------------------------------
vector<vector<int>> solve() {
	if (K > (N + 1) / 2) return {};

	int a = K;
	int b = K + 2 * N - 1;
	int c = b + K;

	set<int> sa, sb, sc;
	vector<vector<int>> ans;
	while (K + N <= b and K + 2 * N <= c) {
		sa.insert(a);
		sb.insert(b);
		sc.insert(c);
		ans.push_back({ a, b, c });
		a++;
		b -= 2;
		c--;
	}

	b = K + 2 * N - 1;
	c = K + 3 * N - 1;
	while (sb.count(b)) b--;
	while (sc.count(c)) c--;
	while (a < K + N and K + N <= b and K + 2 * N <= c) {
		sa.insert(a);
		sb.insert(b);
		sc.insert(c);
		ans.push_back({ a, b, c });
		a++; b--; c--;
		while (sb.count(b)) b--;
		while (sa.count(c)) c--;
	}
	
	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	auto ans = solve();
	if (ans.size() == 0) {
		cout << -1 << endl;
		return;
	}
	fore(v, ans) printf("%d %d %d\n", v[0], v[1], v[2]);
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
yes/no判定だけでなく、構築結果も出せという問題なので、
単純なルールで構築が出せるのだろうとまずは仮定をする。
で、限界条件を頑張ってルール化すると、それっぽい構築法が出てくる。
その、それっぽい構築法を説明する。

a<b<cと仮定する。
加えて、小さい順からN個ずつ数を区切ったときにaが最初のグループ、
bが中のグループ、cが最後のグループに属すことになる。
これは実験により導いたが、正直これくらいの前提が無いと厳しいからなぁ・・・みたいな気持ちもある。

a[i]+b[i]≦c[i]であるが、この仮定により、総和を取ると嬉しい式が出てくる。
(NK + N(N-1)/2) + (NK + N(2N-1+N)/2) ≦ (NK + N(3N-1+2N)/2)
NK + (N^2-N+3N^2-N) / 2 ≦ (5N^2-N) / 2
2NK + 4N^2 - 2N ≦ 5N^2 - N
2K + 4N - 2 ≦ 5N - 1
2K ≦ N + 1
K≦ (N + 1) / 2
ということで、この条件を満たすときに構築可能である。

N=4とかN=5とかでこの上限条件でのうまい構築ルールを考えると、思いつく。
1. (K, K+2N-1, K+2N-1+K)とする
2. (K+1, K+2N-3, K+2N-1+K-1)とする（bを-2して、cを-1する。すると差はK+1）になる
3. 2.をできる限り続ける（全部でK回行う）
4. (K+K, K+2N-1, K+3N-1)とする
5. (K+K+1, K+2N-1, K+3N-2)とする(b,cをまだ割りあたってない最大の数として割り当てていく)
なんか分からんけど、これで通る。
///////////////////////// writeup2 end */
