import Foundation

func solution(_ s: String) -> String {
    var index: Int = 0
    var arr: [String] = []
    for char in s {
        let str = String(char)
        if str == " " {
            arr.append(" ")
            index = 0
            continue
        }
        if index % 2 == 0 {
            arr.append(str.uppercased())
        } else {
            arr.append(str.lowercased())
        }
        index += 1
    }
    return arr.joined(separator:"")
}