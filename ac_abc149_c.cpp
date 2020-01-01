//https://atcoder.jp/contests/abc149/tasks/abc149_c
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
vector<int> makePrimes(int n) { // [2,n]
    vector<int> res, pr(n + 1, 1);
    pr[0] = pr[1] = 0;
    rep(p, 2, sqrt(n) + 2) if (pr[p]) for (int x = p * 2; x <= n; x += p) pr[x] = 0;
    rep(p, 2, n + 1) if (pr[p]) res.push_back(p);
    return res;
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














int X;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X;

	auto vp = makePrimes(1000000);
	int ans = *lower_bound(all(vp), X);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [エラトステネスの篩](https://www.hamayanhamayan.com/entry/2016/10/21/112009)
///////////////////////// writeup2 start
素数判定をするが、雑な解き方をすると、10^6までの素数を全列挙して、X以上の最小の素数を答えればいい。
1～10^6の素数を得るためには、エラトステネスの篩を使えばいい。
1つ1つ素数であるかを判定するのは大変だが、区間なら効率的に判定できることが知られている。
自分はライブラリ化してあるので、それを貼って10^6までの素数を求めて、lower_boundでX以上の最小値を持ってきて答える。
///////////////////////// writeup2 end */
