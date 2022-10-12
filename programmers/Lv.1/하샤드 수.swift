func solution(_ x:Int) -> Bool {
    var num = x
    var n=0
    while(num>0){
        n += num % 10
        num = num / 10
    }
    return x % n == 0
}