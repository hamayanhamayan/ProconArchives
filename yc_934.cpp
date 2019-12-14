//https://yukicoder.me/problems/no/934
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














int N;
//---------------------------------------------------------------------------------------------------
int ask(int without) {
	int M = N - 1;
	vector<int> v;
	rep(i, 1, N + 1) if (i != without) v.push_back(i);
	printf("? %d\n", M);
	rep(i, 0, M) {
		if (i) printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");
	fflush(stdout);

	int ans; cin >> ans;
	return ans;
}
void answer(vector<int> ans) {
	int K = ans.size();
	printf("! %d\n", K);
	rep(i, 0, K) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	fflush(stdout);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	vector<int> ans;
	rep(i, 1, N + 1) {
		auto res = ask(i);
		if (res == 0) ans.push_back(i);
	}
	answer(ans);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
リアクティブ問題。
色々考えると思いつくけど、どういう道筋で思いつくんだろうね。
ある魔剤以外を混ぜたときに、
　爆発する→ある魔剤は爆発に必要ない
　爆発しない→ある魔剤は爆発に必要
これで1個ずつ見ていけばN回で全部どっちかが分かる。
///////////////////////// writeup2 end */
