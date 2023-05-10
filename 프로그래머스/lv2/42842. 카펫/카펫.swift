import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    for x in 1...yellow {
        var y = yellow / x
        if yellow % x != 0 { continue }
        
        if (x * 2) + (y * 2) + 4 == brown {
            return [max(x + 2, y + 2), min(x + 2, y + 2)]
        }
    }
    return []
}