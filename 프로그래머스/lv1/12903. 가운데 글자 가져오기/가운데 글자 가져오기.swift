func solution(_ s:String) -> String {
    var arr = Array(s)
    var str: String = ""
    if arr.count % 2 == 0 {
        str = "\(arr[arr.count/2-1])\(arr[arr.count/2])"
    } else {
        str = "\(arr[arr.count/2])"
    }
    return str
}