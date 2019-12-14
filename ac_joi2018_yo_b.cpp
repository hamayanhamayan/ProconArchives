//https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_b
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












int N, A[105];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 1, N + 1) cin >> A[i];

	rep(d, 1, 102) {
		vector<int> vis(N + 2, 0);
		queue<int> que;
		que.push(N + 1);
		while (!que.empty()) {
			int q = que.front(); que.pop();

			if (q == 0) {
				printf("%d\n", d);
				return;
			}

			if (vis[q]) continue;
			vis[q] = 1;

			rep(i, 1, d + 1) {
				int nx = q - i;
				if (nx < 0) continue;
				if (vis[nx]) continue;
				if (A[nx]) continue;
				que.push(nx);
			}
		}
	}
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
