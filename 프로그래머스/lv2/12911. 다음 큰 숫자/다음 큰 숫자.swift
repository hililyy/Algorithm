import Foundation

func solution(_ n:Int) -> Int {
    let num = n.nonzeroBitCount
    var count = n + 1
    
    while(true) {
        if count.nonzeroBitCount == num {
            return count
        }
        count += 1
    }
    return 0
}