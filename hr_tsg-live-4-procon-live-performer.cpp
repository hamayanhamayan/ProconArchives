//https://www.hackerrank.com/contests/tsg-live-4-programming-contest/challenges/tsg-live-4-procon-live-performer
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
//---------------------------------------------------------------------------------------------------
//        Welcome to My Coding Space!       @hamayanhamayan
//---------------------------------------------------------------------------------------------------












int N, M, K;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K;
	
	if (N <= M / K) cout << "Yes" << endl;
	else cout << "No" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
1つの枠でK人必要ということは、全員フル動員で出動可能な枠はM/Kとなる。
これが、N以上かどうかを判定すればいい。
///////////////////////// writeup2 end */
