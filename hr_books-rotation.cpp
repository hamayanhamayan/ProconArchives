//https://www.hackerrank.com/contests/yfkpo3-2/challenges/books-rotation
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












int H, W, A[101][101];
//---------------------------------------------------------------------------------------------------
void rotate(int x) {
    int tmp = A[H - 1][x];
    rrep(y, H - 1, 1) A[y][x] = A[y - 1][x];
    A[0][x] = tmp;
}
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve(int x) {
    if (x == W) return yes;

    rep(_, 0, H) {
        rotate(x);
        bool ok = true;
        rep(y, 0, H) if (A[y][x - 1] != A[y][x]) ok = false;
        if (ok) return solve(x + 1);
    }

    return no;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> H >> W;
    rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];
    cout << solve(1) << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
B
2ڈڍsO̗ƓɂȂ悤rotate悤΂B
̎ɂčׂB

solve(x) := xڂx-1ڂƍ킹悤rotateł邩
xڂx-1ڂƍ킹悤rotatełȂAx+1ڂxڂƍ킹悤ɂł邩B
ċA֐ƂĎĂB
x=WƂȂꍇiS̗񂪍ꍇjYesԂB
rotatełȂȂNoԂB

rotateoOꍞ݂₷̂ŁA֐ĂƂB
rotate(x)xڂɑ΂rotateisj֐B
///////////////////////// writeup2 end */
