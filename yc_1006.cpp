//https://yukicoder.me/problems/no/1006
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














int X;
int rest[2010101];
map<int, int> ep[2010101];
int d[2010101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X;
	rep(i, 1, X + 1) rest[i] = i;
	rep(i, 1, X + 1) d[i] = 1;
	rep(p, 2, X + 1) for (int x = p; x <= X; x += p) if(rest[x] % p == 0) {
		int cnt = 0;
		while (rest[x] % p == 0) rest[x] /= p, cnt++;
		d[x] *= cnt + 1;
	}

	int mi = inf;
	rep(a, 1, X) {
		int fa = a - d[a];
		int fb = X - a - d[X - a];
		chmin(mi, abs(fa - fb));
	}

	rep(a, 1, X) {
		int fa = a - d[a];
		int fb = X - a - d[X - a];
		if (mi == abs(fa - fb)) {
			printf("%d %d\n", a, X - a);
		}
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
