//https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_a
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
vector<int> enumdiv(int n) { 
    vector<int> S;
    for (int i = 1; 1LL*i*i <= n; i++) if (n%i == 0) { S.push_back(i); if (i*i != n) S.push_back(n / i); }
    sort(S.begin(), S.end());
    return S;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[101];
//---------------------------------------------------------------------------------------------------
bool vis[101];
int memo[101];
int f(int x) {
	if (vis[x]) return memo[x];

	vis[x] = true;

	auto ed = enumdiv(x);
	set<int> gs;
	fore(y, ed) if (y < x) {
		int g = f(y);
		gs.insert(g);
	}

	memo[x] = 0;
	while (gs.count(memo[x])) memo[x]++;
	return memo[x];
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	int g = 0;
	rep(i, 0, N) g ^= f(A[i]);
	if (g == 0) cout << "No" << endl;
	else cout << "Yes" << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [grundy数](https://www.hamayanhamayan.com/entry/2017/02/27/025050)
///////////////////////// writeup2 start
バトル問題であるが、それぞれの整数は別々に操作されるので、それぞれにgrundy数を計算して、
xor和を計算する問題であると考えて、問題に取り組むことにする。
違ったら、違ったやけど。


///////////////////////// writeup2 end */
