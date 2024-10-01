import Foundation

let input = readLine()!.split(separator: " ").map { Int(String($0))! }
var (n, m) = (input[0], input[1])
var dogam: [String] = []
var hash: [String: Int] = [:]

for i in 0..<n {
    let input = readLine()!
    dogam.append(input)
    hash[input] = i
}

for i in 0..<m {
    let input = readLine()!
    
    if let number = Int(input) {
        print((dogam[number - 1]))
    } else {
        print((hash[input])! + 1)
    }
}
