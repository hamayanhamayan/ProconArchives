//https://www.hackerrank.com/contests/oyamac/challenges/uniform-linear-sushi-2
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












int N;
vector<pair<int, int>> ST;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) {
        int s, t; cin >> s >> t;
        int L = s, R = s + t;
        ST.push_back({ R, L });
    }
    sort(all(ST));

    int cu1 = 0, cu2 = 0, ans = 0;
    fore(p, ST) {
        int L = p.second;
        int R = p.first;

        if (cu1 > cu2) swap(cu1, cu2);
        if (cu2 <= L) {
            cu2 = R;
            ans++;
        }
        else if (cu1 <= L) {
            cu1 = R;
            ans++;
        }
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
前の問題同様に貪欲法で解ける。
2人の空き時間をcu1, cu2としておく（cu1≦cu2）。
次に選択しようとしている寿司が区間[L,R]の時間を使うとする。
この時、cu2≦Lであれば、cu2に寿司を食べてもらう方がいい。
(cu1, R)と(R, cu2)では前者の方がいい状態であることが分かるだろう。
そうでなくて、cu1≦Lであればcu1が寿司を食べる。
これを区間の右端が小さい方から、貪欲にやっていくとAC。
///////////////////////// writeup2 end */
//　