let map'cps l f k =
    let rec map' processed left =
        match left with
        | [] -> k processed
        | head :: tail -> map' (processed @ [f head]) tail
    
    map' [] l

map'cps [1;2;3] (fun x -> x + 1) (printfn "%A")