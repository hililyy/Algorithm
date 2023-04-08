// 기존풀이
func solution(_ seoul:[String]) -> String {
    var count: Int = 0
    for str in seoul {
        if str == "Kim" {
            break
        }
        count += 1
    }
    return "김서방은 \(count)에 있다"
}

// 개선풀이
func solution(_ seoul:[String]) -> String {
    return "김서방은 \(seoul.firstIndex(of:"Kim")!)에 있다"
}

/*
이 문제의 포인트는 인덱스를 이용해 일치하는 문자열을 찾을 수 있는가이다.
index()는 deprecated 되었기 때문에 firstIndex()를 이용하자.
*/
