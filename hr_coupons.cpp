//https://www.hackerrank.com/contests/yfkpo3-2/challenges/coupons
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
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N, P, C[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> P;
    rep(i, 0, N) cin >> C[i];

    int ans = P;
    rep(i, 0, N) if(0 <= P - C[i]) chmin(ans, P - C[i]);
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ǂ̃N[|gSTB
N[|g̓N[|gƂɒliɂȂȂƂłB
āAɂȂȂ̂ɂČz̒li̍ŏlƂĂ΂B
ӂƂāAN[|gȂꍇ̂ŁAŏɌ̒liĒuA
ŏlōXVĂƂ낤B
́AchminƂ}NgĂij
`template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }`
///////////////////////// writeup2 end */
