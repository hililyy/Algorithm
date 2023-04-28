import Foundation

func solution(_ left:Int, _ right:Int) -> Int {
    var sum: Int = 0
    for num in left...right {
        var count: Int = 0
        for i in 1...num {
            if num % i == 0 { count += 1 }
        }
        if count % 2 == 0 { sum += num }
        else { sum -= num }
        count = 0
    }
    return sum
}