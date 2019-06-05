#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll  long long
#define PB push_back
#define ld long double
#define ff first
#define ss second
# define st(v) (v).begin(),(v).end()
const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,-1,1,0};
const int nmax = 50 + 5 ;
vector < int > a(nmax);
int K ;
void solve( ){
    int n ;
    cin >> n >> K ;
    for( int i = 0 ; i < n ; i++) cin >> a[i] ;
    int sum1 = 0 ;
    int ans = 0 ;
    for( int left = 0 ; left <=n ; left++){
        if(left!=0)
            sum1+=a[left-1];
        int sum2 = 0 ;
        for( int right = n ; right >= 0 ; right--){
            if(right!=n){
                sum2+=a[right];
            }
            if(left<=right){
                int remain = K - (n-right+left);
                if(remain>=0){
                    ans = max(ans,sum1+sum2);
                    int sum = sum1 + sum2 ;
                    set < int > s ;
                    for( int i = 0 ; i < left ; i++){
                        s.insert(a[i]);
                    }
                    for( int i = n-1 ; i >=right ; i--){
                        s.insert(a[i]);
                    }
                    for( int x : s){
                        if(sum-x>=sum && remain>0){
                            sum-=x;
                            ans = max(ans,sum);
                            remain--;
                        }
                        else{
                            break ;
                        }
                    }
                }
            }
        }
    }
    cout << ans ;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q=1;
    //cin >> q;
    for( int i = 0 ; i < q ; i++){
        solve();
    }
}
