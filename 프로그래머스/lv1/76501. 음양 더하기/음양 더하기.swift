import Foundation

func solution(_ absolutes:[Int], _ signs:[Bool]) -> Int {
    var sum: Int = 0
    for num in 0..<signs.count {
        if signs[num] == true {
            sum += absolutes[num]
        } else {
            sum -= absolutes[num]
        }
    }
    return sum
}