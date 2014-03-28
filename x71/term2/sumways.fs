module SumWays

let sumWays size =
    let rec fact n = 
        match n with
        | 1 -> 1I
        | _ -> (bigint n) * fact (n - 1)

    fact (size * 2) / (fact size) ** 2

printfn "%A" (sumWays 20)