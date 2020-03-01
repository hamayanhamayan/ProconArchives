//https://www.hackerrank.com/contests/yfkpo3-1/challenges/new-comers
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












int A, B, C;
string S[50101], T[50101], U[50101];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B >> C;
    rep(i, 0, A) cin >> S[i];
    rep(i, 0, B) cin >> T[i];
    rep(i, 0, C) cin >> U[i];

    set<string> users;
    rep(i, 0, A) users.insert(S[i]);
    rep(i, 0, B) users.insert(T[i]);

    int ans = C;
    rep(i, 0, C) if (users.count(U[i])) ans--;
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
O̎Q҂ꂼɂāAߋ1xĂȂl𐔂B
1xĂȂƂ𔻒肷͖̂ʓ|AɗƂ̂l𔻒肷͕̂@B
c++ł΁AsetgΊȒPɎ\B
1A2̎Q҂̖OׂsetɓB
3ŊɎQĂ邩ǂ́AsetŌ΂킩邽߁AŜĂƁA
߂ėlANew Comer̐𐔂邱ƂłB
///////////////////////// writeup2 end */
