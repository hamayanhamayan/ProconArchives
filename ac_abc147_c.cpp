//https://atcoder.jp/contests/abc147/tasks/abc147_c
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
vector<int> honests[15];
vector<int> liars[15];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) {
		int A; cin >> A;
		rep(j, 0, A) {
			int x, y; cin >> x >> y;
			if (y == 0) liars[i].push_back(x - 1);
			else honests[i].push_back(x - 1);
		}
	}

	int ans = 0;
	rep(msk, 0, 1 << N) {
		bool ok = true;
		int tot = 0;
		rep(i, 0, N) if (msk & (1 << i)) {
			tot++;
			fore(honest, honests[i]) if (!(msk & (1 << honest))) ok = false;
			fore(liar, liars[i]) if (msk & (1 << liar)) ok = false;
		}
		if (ok) chmax(ans, tot);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
この問題は競技プログラミング的な考え方が必要かもしれない。
競技プログラミングでは、最速のコードを出す必要はない。
制限時間に間に合うコードを出すことを要求されている。
加えて、Nの制約がとても小さいので、N人の人について正直/不親切であるかを全探索しよう。
これは2^N通りあり、間に合う。
bit全探索で全探索をして、条件を満たす正直者の人数の最大値が答え。
///////////////////////// writeup2 end */
