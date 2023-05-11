import Foundation

func solution(_ s:String) -> [Int] {
    var zeroCount = 0
    var changeCount = 0
    var beforeNum = s
    
    while(true) {
        var afterNum = beforeNum.filter{ $0 == "1" }
        zeroCount += beforeNum.count - afterNum.count
        changeCount += 1
        beforeNum = String(afterNum.count, radix: 2)
        if beforeNum == "1" { return [changeCount, zeroCount] }
    }
    return []
}