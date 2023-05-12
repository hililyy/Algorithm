import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var lastChar: String = ""
    var beforeWords: [String] = []
    
    for (i, word) in words.enumerated() {
        if lastChar != "" {
            guard lastChar.isEmpty || lastChar == word.prefix(1),
                  !beforeWords.contains(word) else {
                return makeResult(i, n)
            }
        }
        beforeWords.append(word)
        lastChar = String(word.suffix(1))
    }
    return [0, 0]
}

func makeResult(_ index: Int, _ n: Int) -> [Int] {
    var result = [((index) % n) + 1, ((index) / n) + 1]
    return result
}