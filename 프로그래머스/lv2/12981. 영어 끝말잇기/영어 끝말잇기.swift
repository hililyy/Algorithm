import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var lastChar: String = ""
    var beforeWords: [String] = []
    
    for (i, word) in words.enumerated() {
        if lastChar != word.prefix(1) && lastChar != "" {
            return makeResult(i, n)
        } else {
            if beforeWords.contains(word) {
                return makeResult(i, n)
            } else {
                beforeWords.append(word)
                lastChar = String(word.suffix(1))
            }
        }
    }
    return [0, 0]
}

func makeResult(_ index: Int, _ n: Int) -> [Int] {
    var result = [((index) % n) + 1, ((index) / n) + 1]
    return result
}