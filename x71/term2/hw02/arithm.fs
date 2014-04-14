type Expr =
    | Const of int
    | Var of string
    | Add of Expr * Expr
    | Sub of Expr * Expr
    | Mul of Expr * Expr
    | Div of Expr * Expr

let rec simplify expr = 
    let simplify' expr =
        match expr with
        | Const (x) -> Const (x)
        | Var (x) -> Var (x)
        | Add (Const x, Const y) -> Const (x + y)
        | Sub (Const x, Const y) -> Const (x - y)
        | Mul (Const x, Const y) -> Const (x * y)
        | Div (Const x, Const y) -> Const (x / y)
        | Add (expr', Const 0) | Add (Const 0, expr') | Sub (expr', Const 0)
        | Mul (expr', Const 1) | Mul (Const 1, expr') | Div (expr', Const 1) -> simplify expr'
        | Mul (_, Const 0) | Mul (Const 0, _) -> Const 0
        | Sub (Var v1, Var v2) ->
            if v1 = v2 then Const 0
            else expr
        | _ -> expr

    match expr with
    | Add (e1, e2) -> simplify' (Add (simplify e1, simplify e2))
    | Sub (e1, e2) -> simplify' (Sub (simplify e1, simplify e2))
    | Mul (e1, e2) -> simplify' (Mul (simplify e1, simplify e2))
    | Div (e1, e2) -> simplify' (Div (simplify e1, simplify e2))
    | _ -> expr
    

//printfn "%A" (simplify (Sub (Var "x", Const 0)))
printfn "%A" (simplify (Add (Const 3, Sub (Const 5, Const 2))))
//printfn "%A" (simplify (Mul (Var "x", Const 0)))
//printfn "%A" (simplify (Mul (Const 1, (Sub (Var "x", Var "x")))))
//printfn "%A" (simplify (Add (Var "x", Var "y")))