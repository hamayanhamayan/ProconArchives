//https://www.hackerrank.com/contests/oyamac/challenges/uniform-linear-sushi
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

    int ans = 0;
    int cur = 0;
    fore(p, ST) {
        int L = p.second;
        int R = p.first;

        if (cur <= L) {
            cur = R;
            ans++;
        }
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- 区間スケジューリング問題
///////////////////////// writeup2 start
ある寿司を食べている時間は、[S, S+T]の区間の時間となる。
このように区間として考えると、今回の問題は区間スケジューリング問題と全く同じになる。
よって、終了時間が早い寿司から順に取っていく貪欲法で解こう。

これは`vector<pair<int,int>>`に{S+T,S}を入れてソートすればいい。
vector,pairのソートは最初の要素の昇順、同じなら、次の要素の昇順でやってくれるので、
これで区間の右端が小さい順から取得できる。
あとは、現在時刻を持ちながら貪欲に選択していけばいい。
///////////////////////// writeup2 end */
//　