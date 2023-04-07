func solution(_ num:Int) -> Int {
    var result = num
    var count = 0
    while(result != 1) {
        if result % 2 == 0 {
            result = result / 2
            count += 1
        } else {
            result = result * 3 + 1
            count += 1
        }
        if result < 0 || count >= 500 {
            return -1
        }
    }
    return count
}


/* 
좀 지저분하게 짰다고 생각했는데 다른사람들의 풀이를 보니 더 간소화된 방식은 없는 것 같다.
변수를 많이 사용하는걸 안좋아하는데 500이라는 수는 maxCount라고 따로 빼주는게 더 직관적인것 같아 더 좋은방법이라는 생각이 든다.
*/
