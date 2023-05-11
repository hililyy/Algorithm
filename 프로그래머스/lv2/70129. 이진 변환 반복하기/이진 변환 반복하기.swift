import Foundation

func solution(_ s:String) -> [Int] {
    var zeroCount = 0
    var changeCount = 0
    var beforeNum = s
    
    while(true) {
        var len = beforeNum.filter{ $0 == "1" }.count
        zeroCount += beforeNum.count - len
        changeCount += 1
        beforeNum = String(len, radix: 2)
        if beforeNum == "1" { return [changeCount, zeroCount] }
    }
    return []
}