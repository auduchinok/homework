//module Huffman

type CodeTree =
  | Fork of CodeTree * CodeTree * char list * int
  | Leaf of char * int


// code tree

let createCodeTree (chars: char list) : CodeTree = 
    failwith "Not implemented"

// decode

type Bit = int 

let decode (tree: CodeTree)  (bits: Bit list) : char list = 
    let rec decode' (node: CodeTree) (bits: Bit list) =
        match node with
        | Fork(l, r, _, _) ->
            match bits.Head with
            | 0 -> decode' l bits.Tail
            | 1 -> decode' r bits.Tail
            | _ -> failwith "Wrong symbol"
        | Leaf(c, _) ->
            if bits.IsEmpty then c :: []
            else c :: decode' tree bits
    decode' tree bits |> List.rev
// encode

let encode (tree: CodeTree)  (text: char list) : Bit list = 
  failwith "Not implemented"