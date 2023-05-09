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

/*
1. 닉네임과 아이디는 순서를 알 필요 없이 따로 저장 가능
2. 딕셔너리의 키 벨류를 통해 키로 값을 한번에 변경 가능 => 굳이 contatin 여부를 체크할 필요가 없음 (Enter와 Change를 동일한 동작을 실행 가능함을 알아야했음)
3. 동작 하나를 줄이기보다 반복문을 최대한 덜 사용하는 방향으로 생각했어야했음
*/


/* ---------------기존에 작성한 코드--------------- */

func solution(_ record:[String]) -> [String] {
    var users: [UserInfo] = []
    var msgs: [String] = []
    
    for r in record {
        let arr = r.components(separatedBy: " ")
        
        switch arr[0] {
            case "Enter":
            if users.contains(where: { user in
                user.id == arr[1] && user.nickName != arr[2]
            }) {
                for i in 0..<users.count {
                    if users[i].id == arr[1] {
                        users[i].nickName = arr[2]
                    }
                }
            }
            users.append(UserInfo(type: arr[0], id: arr[1], nickName: arr[2]))
            case "Leave":
            var nickName: String = ""
            
            for i in 0..<users.count {
                if users[i].id == arr[1] {
                    nickName = users[i].nickName
                }
            }
            users.append(UserInfo(type: arr[0], id: arr[1], nickName: nickName))
            case "Change":
            for i in 0..<users.count {
                if users[i].id == arr[1] {
                    users[i].nickName = arr[2]
                }
            }
            default:
            break
        }
    }
    
    for user in users {
        switch user.type {
            case "Enter":
            msgs.append("\(user.nickName)님이 들어왔습니다.")
            case "Leave":
            msgs.append("\(user.nickName)님이 나갔습니다.")
            default:
            break
        }
    }
    
    return msgs
}

struct UserInfo {
    var type: String = ""
    var id: String = ""
    var nickName: String = ""
}
