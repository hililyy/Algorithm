
## 코드
```
import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int
{
    var ans = 0
    var a = A.sorted()
    var b = Array(B.sorted().reversed())
    
    for num in 0..<a.count {
        ans += a[num] * b[num]
    }
    
    return ans
}
```
</br>

### 문제 포인트
1. A배열을 오름차 순으로 정렬, B배열을 내림차 순으로 정렬
2. 순서대로 곱한다.
</br></br>
### 알게된 점
1. 파라미터 배열이 let으로 주어지기 때문에 sorted()를 사용한다.
2. B.sorted().reversed()를 Array로 형변환 해주지 않으면 다른 자료형이되어 연산이 불가능하다.
3. 오름차순 => A.sorted(by:>)
   내림차순 => B.sorted(by:<)
으로 좀 더 쉽게 작성 가능하다.
4. 인덱스를 굳이 돌면서 연산하지 않고 removeFirst()를 사용해 가장 앞을 소거하는 방식으로 연산하는 방법도 있다. (시간복잡도는 O(n))
</br></br>

## 개선된 풀이
```
import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int
{
    var ans = 0
    var a = A.sorted(by:>)
    var b = Array(B.sorted(by:<))
    
    for num in 0..<a.count {
        ans += a[num] * b[num]
    }
    
    return ans
}
```


