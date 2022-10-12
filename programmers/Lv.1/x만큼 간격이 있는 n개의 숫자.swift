func solution(_ x:Int, _ n:Int) -> [Int] {
    var arr: [Int] = []
    var count: Int = 1
    for i in 1...n {
        arr.append(x*count)
        count = count + 1
    }
    return arr
}