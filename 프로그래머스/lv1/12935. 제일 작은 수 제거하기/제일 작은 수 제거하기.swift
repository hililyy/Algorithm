func solution(_ arr:[Int]) -> [Int] {
    var num = arr[0]
    if arr.count <= 1 {
        return [-1]
    } else {       
        for i in 0 ..< arr.count {
            if num > arr[i] {
                num = arr[i]
            }
        }
    }
    return arr.filter { $0 != num }
}