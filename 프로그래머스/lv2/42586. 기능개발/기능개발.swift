import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var answer: [Int] = []
    var count: Int = 0
    var max: Int = 0
    
    for (i, (a, b)) in zip(progresses, speeds).enumerated() {
        var newElement = Int(ceil(Double((100 - a)) / Double(b)))
        if i == 0 {
            count += 1
            max = newElement
            continue
        }
        if max < newElement {
            max = newElement
            answer.append(count)
            count = 1
        } else {
            count += 1
        }
        
        if i == progresses.count - 1 {
            answer.append(count)
        }
    }
    return answer
}