백준 [우체국](https://www.acmicpc.net/problem/2141)(2141번)

# 고려해야할 점 🤔
1. 마을은 순서대로 입력받지 않을 수 있다.    
    -> sort를 이용해 정렬이 필요하다.  
    -> 이때 마을과 사람수는 쌍을 이루므로 pair를 이용해 묶어서 정렬해준다.
    
2.  우체국은 마을에만 설치된다.   
    -> 마을에 사람이 없다면 그곳에는 우체국을 설치할 수 없다.
    
3. 문제에도 나와있듯 각 마을까지 거리의 합이 아닌 각 사람까지의 거리의 합이다!!   

---

# 코드 🤪

```

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

```
---

# 느낀 점 😜
1. `long long`은 `using ll = long long;` 과 같이 축약해서 사용 가능하다.
2. 단순히 첫번째 마을부터 사람들을 더해가다가 마을 인원의 중간에 위치하는 점에서 우체국을 세우면 되는 어찌보면(?) 간단한 문제!!
3. (서치해서 안 내용) 마지막 if 문에서 `(sum+1)/2` 에서 `sum`에 +1을 해주어야 99퍼에서 맞았습니다!! 가 나왔는데 그 이유는... 더 고려!!🤣
