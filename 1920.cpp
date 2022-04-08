#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n,m;
    int a[100001]={0};
    int b;
    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin>> n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    
    cin>>m;
    
    for(int i=0;i<m;i++){
        cin>>b;
        if(upper_bound(a,a+n,b)-lower_bound(a,a+n,b)) cout<<'1'<<'\n';
        else cout<<'0'<<'\n';

    }
}