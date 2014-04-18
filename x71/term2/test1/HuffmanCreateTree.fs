module Huffman

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
    | Leaf(x, _) -> x :: []
  
    
let makeCodeTree left right =
    Fork(left, right, chars left @ chars right, weight left + weight right)


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


let orderedLeafList (list: (char * int) list) =
    let rec orderedLeafList' (list: (char * int) list) = 
        match list with
        | [] -> []
        | head :: tail ->
            let ch, times = head
            Leaf(ch, times) :: orderedLeafList' tail

    List.sortBy(fun Leaf(ch, times) -> times) (orderedLeafList' list)


let createCodeTree (chars: char list) : CodeTree = 
    failwith "Not implemented"

// decode

type Bit = int

let decode (tree: CodeTree)  (bits: Bit list) : char list = 
  failwith "Not implemented"

// encode

let encode (tree: CodeTree)  (text: char list) : Bit list = 
  failwith "Not implemented"
