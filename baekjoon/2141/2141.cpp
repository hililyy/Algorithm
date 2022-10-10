#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

pair<ll,ll> xa[100001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >>n;
    
    ll sum =0;
    ll search =0;
    
    for(int i=0;i<n;i++) {
        int x, y;
        cin>>x>>y;
        xa[i].first = x;
        xa[i].second = y;
        sum += xa[i].second;
    }
    
    sort(xa, xa+n);
    
    for(int i=0; i < n; i++){
        search += xa[i].second;
        if(search >= ((sum+1)/2)) {
            cout<<xa[i].first;
            break;
        }
    }
}
