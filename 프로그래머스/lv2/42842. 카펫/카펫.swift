import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    for x in 1...yellow {
        var y = 0
        if yellow % x == 0 {
           y = yellow / x
        } else {
            continue
        }
        if (x * 2) + (y * 2) + 4 == brown {
            return [max(x + 2, y + 2), min(x + 2, y + 2)]
        }
    }
    return []
}