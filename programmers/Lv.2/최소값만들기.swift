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
