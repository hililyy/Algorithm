import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64 {
    var totalMoney = 0
    
    for i in 1...count {
        totalMoney += i * price
    }
    return totalMoney - money > 0 ? Int64(totalMoney - money) : 0
}