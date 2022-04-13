#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int flag=0;
    int count[2] = {0};
    
    cin>>s;
    
    if(s[0]=='0') count[0]++;
    else count[1]++;
    
    for(int i=1; i<s.length(); i++){
        if(s[i-1]!=s[i]) count[int(s[i])-48]++;
    }
    
    cout<<min(count[0],count[1]);
}
