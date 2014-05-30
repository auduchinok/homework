// Eugene Auduchinok (c) 2014

namespace MyCollections

open System.Collections
open System.Collections.Generic

module Tree =

    type TreeNode<'Key, 'Value> = 
        | Empty
        | Node of 'Key * 'Value * left : TreeNode<'Key, 'Value> * right : TreeNode<'Key, 'Value> * height : int
        // I use k, v, l, r, h as short names for Node fields in this module.

    let isEmtpy = function
        | Empty -> true
        | _ -> false

    let height = function
        | Empty -> 0
        | Node (_, _, _, _, h) -> h

    let Key = function
        | Empty -> failwith "Empty"
        | Node (k, _, _, _, _) -> k

    let Value = function
        | Empty -> failwith "Empty"
        | Node (_, v, _, _, _) -> v

    let rec toList = function
        | Empty -> []
        | Node (_, _, l, r, _) as node -> toList l @ [node] @ toList r

    let rec count = function
        | Empty -> 0
        | Node (_, _, l, r, _) ->
            count l + count r + 1

    let rec tryFind key = function
        | Empty -> None
        | Node (k, v, l, r, _) ->
            if key = k then Some v
            else tryFind key (if key < k then l else r)

    let contains key tree =
        match tryFind key tree with
        | None -> false
        | _ -> true
    
    let item key tree =
        match tryFind key tree with
        | None -> failwith "No such element"
        | Some v -> v
        
    let createNode key value left right =
        let h = 1 + max (height left) (height right)
        Node (key, value, left, right, h)

    // In rotation functions I use lx, lv, rx, rv, etc as left and right children's fields respectively.
    let rotateRight = function
        | Node (k, v, Node (lk, lv, ll, lr, _), r, _) ->
            let r' = createNode k v lr r
            createNode lk lv lr r'
        | node -> node

    let rotateLeft = function
        | Node (k, v, l, Node (rk, rv, rl, rr, _), _) ->
            let l' = createNode k v l rl
            createNode rk rv l' rr
        | node -> node
             
    let doubleRotateLeft = function
        | Node (k, v, l, r, _) ->
            let r' = rotateRight r
            let node' = createNode k v l r'
            rotateLeft node'
        | node -> node

    let doubleRotateRight = function
        | Node (k, v, l, r, _) ->
            let l' = rotateLeft l
            let node' = createNode k v l' r
            rotateRight node'
        | node -> node

    let nodeBalance = function
        | Empty -> 0
        | Node (_, _, l, r, _) -> (height l) - (height r)

    let balance = function
        | Node (_, _, l, _, _) as node when nodeBalance node >= 2 ->
            if nodeBalance l >= 1 then rotateRight node
            else doubleRotateRight node
        | Node (_, _, _, r, _) as node when nodeBalance node <= -2 ->
            if nodeBalance r <= -1 then rotateLeft node
            else doubleRotateLeft node
        | node -> node

    let rec add key value = function
        | Empty -> createNode key value Empty Empty
        | Node(k, v, l, r, _) as node ->
        if key = k then createNode key value l r
        else
            let l', r' = if key < k then add key value l, r else l, add key value r
            createNode k v l' r' |> balance

    let rec mostLeft = function
        | Node (_, _, l, _, _) as node ->
            if isEmtpy l then node else mostLeft l
        | Empty -> failwith ""

    let rec mostRight =  function
        | Node (_, _, _, r, _) as node ->
            if isEmtpy r then node else mostRight r
        | Empty -> failwith ""

    let rec remove key = function
            | Empty -> Empty
            | Node (k, v, l, r, _) -> 
                if key = k then
                    if isEmtpy l && isEmtpy r then Empty
                    else
                        if height l > height r then
                            let v' = mostRight l
                            let k' = Key v'
                            createNode k' (Value v') (remove k' l) r
                        else
                            let v' = mostLeft r
                            let k' = Key v'
                            createNode k' (Value v') l (remove k' r
                else
                    if key < k
                    then createNode k v (remove key l) r
                    else createNode k v l (remove key r)
                |> balance


module Map =
    open Tree

    type Map<'Key, 'Value when 'Key : comparison and 'Value : equality> = 
        val private tree : TreeNode<'Key, 'Value>
        private new (tree') = { tree = tree' }
        new (init: seq<'Key * 'Value>) =
            let t = ref Tree.Empty
            let rec add = function
                | [] -> t
                | head :: tail ->
                    match head with
                    | (k, v) ->
                        t:= Tree.add k v (!t)
                        add tail
            Map<_, _>(!(add (Seq.toList init)))

        member this.IsEmpty = Tree.isEmtpy this.tree
        member this.Count = Tree.count this.tree
        member this.ContainsKey key = Tree.contains key this.tree
        member this.TryFind key = Tree.tryFind key this.tree
        member this.Item key = Tree.item key this.tree
        member this.Add (key, value) = new Map<_, _> (Tree.add key value this.tree)
        member this.Remove key = new Map<_, _> (Tree.remove key this.tree)
        
        member this.ToString () =
            let rec toString = function
                | Empty -> "Empty"
                | Node (k, v, l, r, _) -> "Node(" + k.ToString() + " " + v.ToString() + toString l + toString r + ")"
            toString this.tree

        member private this.getEnumerator () =
            let list = List.tail (Tree.toList this.tree)
            let remains = ref list

            let current () =
                match List.head !remains with
                | Node (k, v, _, _, _) -> (k, v)
                | _ -> failwith "Empty"

            {new IEnumerator<'Key * 'Value> with
                member this.Current = current ()
            
            interface IEnumerator with
                member this.Current = current :> obj
                member this.MoveNext () = 
                    remains := (!remains).Tail
                    not (List.isEmpty !remains)
                member this.Reset () = remains := list
            interface System.IDisposable with
                member this.Dispose () = ()
            }

        interface IEnumerable<'Key * 'Value> with
            member this.GetEnumerator () = this.getEnumerator ()
                
        interface IEnumerable with
            member this.GetEnumerator () = this.getEnumerator () :> IEnumerator