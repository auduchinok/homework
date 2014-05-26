// Eugene Auduchinok (c) 2014

module Map'CPS

// 'a list -> ('a -> 'b) -> ('b list -> 'c) -> 'c
let map'cps l f k =
    let rec map' processed left =
        match left with
        | [] -> k processed
        | head :: tail -> map' (processed @ [f head]) tail
    
    map' [] l

map'cps [1;2;3] (fun x -> x + 1) (printfn "%A")


let rec map f k = function
    | [] -> k []
    | head :: tail ->
        f head (fun head' -> map f (fun tail' -> k (head' :: tail')) tail)

let list = [1..10]
let isEven x k = k (x % 2 = 0)

map isEven (printfn "%A") list