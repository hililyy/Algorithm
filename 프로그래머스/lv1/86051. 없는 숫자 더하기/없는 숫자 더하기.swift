import Foundation

func solution(_ numbers:[Int]) -> Int {
    var total: Int = 45
    for num in numbers {
        total = total - num
    }
    return total
}