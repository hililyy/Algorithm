import Foundation

func solution(_ s:String) -> Int{
    var stack: [Character] = []
    
    if s.count % 2 == 1 { return 0 }
    
    for char in s {
        if let top = stack.last, top == char {
            stack.popLast()
        } else {
            stack.append(char)
        }
    }
    
    return stack.isEmpty ? 1 : 0
}