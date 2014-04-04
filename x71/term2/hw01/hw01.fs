// Eugene Auduchinok (c) 2014
// HW 171-2.01

// List elements sum
let rec listSum l = 
    match l with
    | [] -> 0
    | hd :: tl -> hd + listSum tl

printfn "%A" (listSum [1; 2; 3])


// List concatenation
let rec listCat l1 l2 =
    match l1 with
    | [] -> l2
    | hd :: tl -> hd :: listCat tl l2

printfn "%A" (listCat [1; 2; 3] [4; 5])


// List concatenation #2
printfn "%A" ([1; 2; 3] @ [4; 5])


// List.Push_back :)
let rec pushBack l n =
    match l with
    | [] -> n :: []
    | hd :: tl -> hd :: pushBack tl n

printfn "%A" (pushBack [1; 2; 3] 4)


// factorial
let rec fact n = 
    match n with
    | 1 -> 1
    | x -> x * fact (n - 1)

printfn "%A" (fact 5)    


// List generator
let genListSqr n =
    let rec genList' k =
        if k * k > n then
            []
        else
            k * k :: genList' (k + 1)

    genList' 1

printfn "%A" (genListSqr 42)