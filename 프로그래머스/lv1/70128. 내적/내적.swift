import Foundation

func solution(_ a:[Int], _ b:[Int]) -> Int {
    var sum: Int = 0
    for (i, data) in a.enumerated() {
        sum += data * b[i]
    }
    return sum
}