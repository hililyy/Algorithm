func solution(_ n:Int) -> Int {
    var arr: [Int] = []
    
    arr.append(0)
    arr.append(1)
    
    for i in 2...n + 2 {
        arr.append((arr[i - 1] + arr[i - 2]) % 1234567)
    }
    return arr[n]
}