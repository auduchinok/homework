// Eugene Auduchinok (2014)

// 'a list -> ('a -> 'b) -> ('b list -> 'c) -> 'c
let map'cps l f k =
    let rec map' processed left =
        match left with
        | [] -> k processed
        | head :: tail -> map' (processed @ [f head]) tail
    
    map' [] l

map'cps [1;2;3] (fun x -> x + 1) (printfn "%A")


let isEven x k = k (x % 2 = 0)

// 'a list -> ('a -> ('b -> 'c) -> 'c) -> ('b list -> 'c) -> 'c
let rec map l f k =
    match l with
    | [] -> k []
    | head :: tail ->
        f head (fun head' -> map tail f (fun tail' -> k (head' :: tail')))


let list = [1..10]

list |> (fun x -> map x isEven (fun x -> printfn "%A" x))