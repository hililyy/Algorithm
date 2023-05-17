import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var arr:[Int] = []
    for num in numbers {
        arr.append(num * 2)
    } 
    return arr
}