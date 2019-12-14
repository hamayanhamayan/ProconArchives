//https://atcoder.jp/contests/abc142/tasks/abc142_c
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

int N, A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    vector<pair<int,int>> v;
    rep(i, 0, N) v.push_back({A[i], i + 1});
    sort(all(v));

    rep(i, 0, N) {
        if (i) printf(" ");
        printf("%d", v[i].second);
    }
    printf("\n");
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
最初に来た生徒では1人の記録があるはず。
二番目に来た生徒では2人の記録があるはず。
という感じで、記録された人数と来た順番は一致する。
よって、記録人数でソートして、その順番で生徒の番号を答えればいい。
///////////////////////// writeup2 end */
