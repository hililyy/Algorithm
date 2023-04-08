import Foundation

func solution(_ s:String) -> Bool
{
    var count: Int = 0
    var arr = Array(s)
    for str in arr {
        count = str == "(" ? count + 1 : count - 1
        if count < 0 {
            return false
        }
    }
    
    if count == 0 {
        return true
    } else {
        return false
    }
}
