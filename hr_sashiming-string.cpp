//https://www.hackerrank.com/contests/75th/challenges/sashiming-string
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












string S;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> S;
    int N = S.length();

    ll ans = 0;
    int s = 0;
    rep(i, 0, N - 2) {
        if (S[i] == 'S') s++;
        else if (S.substr(i, 3) == "ing") ans += s;
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、何かしらの全探索対象を探す。
特徴的なのは、Sとingの位置なので、この2つの場所を全探索する。
2つを全探索すると10^10通りとなり、これは間に合わない。

これを工夫するが、何となく区間の列挙に全探索方法が似ている。
区間全探索の有名テクは「片方の歌詞を全探索して、もう片方を効率よく数える」というテクである。
今回は右端であるingを固定したときに有効なSの個数を数えよう。
ingを固定すると、有効なSはそれより前にあるSの個数なので、先頭から順番にingを確認しながら、
Sの個数を足し合わせていくと、ingを処理するときにそれまでのSの個数が数えられている。
それを足し合わせていくと答え。
///////////////////////// writeup2 end */
//　