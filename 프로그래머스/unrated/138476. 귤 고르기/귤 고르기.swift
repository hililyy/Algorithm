import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var dic: [Int : Int] = [:]
    var result: Int = 0
    var _k = k
    
    for i in tangerine {
        if let num = dic[i] {
            dic[i]! += 1
        } else {
            dic[i] = 1
        }
    }
    
    let newDic = dic.sorted {
        return $0.1 > $1.1
    }
    
    for (_, value) in newDic {
        if _k != 0 {
            result += 1
            _k = _k - value
        }
        if _k <= 0 {
            break
        }
    }
    return result
}
