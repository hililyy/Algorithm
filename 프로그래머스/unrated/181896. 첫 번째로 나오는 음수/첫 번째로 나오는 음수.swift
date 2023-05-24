import Foundation

func solution(_ num_list:[Int]) -> Int {
    for (i, v) in num_list.enumerated() {
        if v < 0 {
            return i
        } 
    }
    return -1
}