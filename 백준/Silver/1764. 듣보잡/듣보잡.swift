import Foundation

let input = readLine()!.split(separator: " ").map { Int(String($0))! }
var (n, m) = (input[0], input[1])
var persons: [String: Int] = [:]
var answer: [String] = []
var count: Int = 0

for person in 0..<n {
    let input = readLine()!
    persons[input] = 1
}

for person in 0..<m {
    let input = readLine()!
    if persons[input] != nil {
        count += 1
        answer.append(input)
    }
}

answer.sort()

print(count)
for person in answer {
    print(person)
    
}
