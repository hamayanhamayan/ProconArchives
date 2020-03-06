//https://codeforces.com/contest/1305/problem/D
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
set<int> E[1010];
bool erased[1010];
//---------------------------------------------------------------------------------------------------
int query(int u, int v) {
	printf("? %d %d\n", u + 1, v + 1);
	fflush(stdout);
	int res; cin >> res;
	return res - 1;
}
//---------------------------------------------------------------------------------------------------
void answer(int r) {
	printf("! %d\n", r + 1);
	fflush(stdout);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		E[a].insert(b);
		E[b].insert(a);
	}

	rep(_, 0, 500) {
		int a = -1, b = -1;
		rep(i, 0, N) if (!erased[i] && E[i].size() <= 1) {
			if (a < 0) a = i;
			else b = i;
		}

		if (b < 0) {
			answer(a);
			return;
		}

		int res = query(a, b);
		if(res != a && res != b) {
			fore(to, E[a]) E[to].erase(a);
			fore(to, E[b]) E[to].erase(b);
			erased[a] = erased[b] = true;
		} else {
			answer(res);
			return;
		}
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
木の葉から2つを選択して質問するという方針を繰り返す。
応答が指定した2つの頂点以外であれば、その葉が根である可能性はなくなる。
かつ、その葉を木から削除しても問題なくなる。
これは、今後その葉がLCA計算には影響しないためである。
これを繰り返していくと、1回で2つ消えるので、N/2回で答えが見つかる。
2つの頂点を選択して質問して、どちらかが応答で帰ってきたら、それが答え。
頂点が1つだけになったら、それを答える。
///////////////////////// writeup2 end */
