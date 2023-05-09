import Foundation

func solution(_ record:[String]) -> [String] {
    var msgs: [String] = []
    var idNickname: [String: String] = [:]
    
    for r in record {
        let arr = r.components(separatedBy: " ")
        
        if arr[0] == "Enter" || arr[0] == "Change" {
            idNickname[arr[1]] = arr[2]
        }
    }

    for r in record {
        let arr = r.components(separatedBy: " ")
        
        switch arr[0] {
            case "Enter":
            msgs.append("\(idNickname[arr[1]]!)님이 들어왔습니다.")
            case "Leave":
            msgs.append("\(idNickname[arr[1]]!)님이 나갔습니다.")
            default:
            break
        }
    }

    return msgs
}