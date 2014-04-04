// Eugene Auduchinok (c) 2014
// hw02


//filter
printfn "%A" (filter (fun x -> x > 2) [1; 7; -1; 2; 3; 4])


// fact digit sum
let factDigitSum n =
    let rec fact n =
        match n with
        | 1 -> 1I
        | _ -> (bigint n) * fact (n - 1) 

    let rec digitSum num =
        if num = 0I then 0
        else (int (num % 10I)) + digitSum (num / 10I)

    digitSum (fact n)

printfn "%A" (factDigitSum 100)
   

// fib
let evenFibSum n = 
    let rec fib n = 
        if n = 1 || n = 2 then 1
        else fib (n - 1) + fib (n - 2)
    let rec evenFibSum' k =
        if fib k > n then 0
        else if fib k % 2 = 0 then
                fib k + evenFibSum' (k + 1)
                else evenFibSum' (k + 1)
    evenFibSum' 1

printfn "%A" (evenFibSum 10)
