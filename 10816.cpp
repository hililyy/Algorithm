#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector <int> v;
    int num;
    int n,m;
    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    
    cin>>m;
    
    for(int i=0;i<m;i++){
        cin >>num;
        cout << upper_bound(v.begin(),v.end(),num)-lower_bound(v.begin(),v.end(),num)<<' ';
    }
    
    
    
    
}