import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var sortD = d.sorted()
    var _budget = budget
    var count = 0
    for i in sortD {
        _budget -= i
        if _budget < 0 {
            break;
        }
        count += 1
    }
    return count
}