func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    var output: [Int] = []
    
    for num in arr {
        if num % divisor == 0 {
            output.append(num)
        }
    }
    let _output = output.sorted()
    if _output == [] {
        return [-1]
    } else {
        return output.sorted()
    }
}