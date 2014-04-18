type CodeTree = 
  | Fork of left: CodeTree * right: CodeTree * chars: char list * weight: int
  | Leaf of char: char * weight: int


let weight (t: CodeTree) =
    match t with
    | Fork(_, _, _, x) -> x
    | Leaf(_, x) -> x


let chars (t: CodeTree) =
    match t with
    | Fork(_, _, x, _) -> x
    | Leaf(x, _) -> [x]


let stringToChars (str: string) =
    Seq.toList str


let rec times (chars: char list) =
    let rec addChar (toAdd: char) (list: (char * int) list) =
        match list with
        | [] -> (toAdd, 1) :: []
        | head :: tail -> 
            let ch, times = head
            if toAdd = ch then
                (toAdd, times + 1) :: tail
            else
                head :: addChar toAdd tail

    match chars with
    | [] -> []
    | head :: tail -> addChar head (times tail)


let rec addToSortedList (t: CodeTree) (list: (CodeTree list)) =
    match list with
    | [] -> [t]
    | head :: tail ->
        match t, head with
        | Leaf(_, tWeight), Leaf(_, hdWeight) | Leaf(_, tWeight), Fork(_, _, _, hdWeight)
        | Fork(_, _, _, tWeight), Leaf(_, hdWeight) | Fork(_, _, _, tWeight), Fork(_, _, _, hdWeight) ->
            if tWeight < hdWeight then
                t :: list
            else
                head :: addToSortedList t tail


let rec orderedLeafList (list: (char * int) list) =
    match list with
    | [] -> []
    | head :: tail ->
        let ch, weight = head
        addToSortedList (Leaf(ch, weight)) (orderedLeafList tail)


let combine (left: CodeTree) (right: CodeTree) =
    Fork(left, right, chars left @ chars right, weight left + weight right)


let createCodeTree (chars: char list) = 
    let rec createFromLeafList (list: CodeTree list) =
        match list with
        | [] -> None
        | hd :: [] -> Some hd
        | first :: second :: tail ->
            createFromLeafList (addToSortedList (combine first second) tail)
        
    let singletonList = (chars |> times  |>  orderedLeafList |> createFromLeafList)

    match singletonList with
    | None -> failwith "Shouldn't be empty."
    | Some el -> el

printfn "%A" ("aaabbcd" |> stringToChars |> createCodeTree)