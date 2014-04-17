let rnd = new System.Random()

type Pizza() =
    let tasty = rnd.Next(2) > 0
    member this.Tasty = tasty


[<AbstractClass>]
type Alive() = 
    let mutable dead = false
    abstract member Eat : unit -> unit
    member this.Dead = dead
    member this.Die () = dead <- true
    

type Human(name:string) = 
    inherit Alive()
    let mutable mood = 5
    member this.Name = name
    member this.Mood with get() = mood and set(m) = mood <- m
    override this.Eat () = mood <- mood + 3


type NinjaTurtle(name:string, maskColor:string) =
    inherit Human(name)
    member this.MaskColor = maskColor
   
    override this.Eat () = 
        let pizza = new Pizza()
        printfn "%s eats %s pizza." this.Name (if pizza.Tasty then "a tasty" else "an awful")
        this.Mood <- this.Mood + if pizza.Tasty then 5 else 1
        if this.Mood > 7 then printfn "His mood is good enough for him to win a battle."
        printfn ""
        

type Reporter() =
    inherit Human("April")
    member this.CaptureNews (turtle:NinjaTurtle) (badGuy:Human) =
        if turtle.Dead then
            printfn "=== SHOCKING NEWS === "
            printfn "%s's just killed %s!" badGuy.Name turtle.Name
        else
            printfn "The %s Mask has destroyed the enemy! Cool. :)" turtle.MaskColor
        

type BadGuy() =
    inherit Human("Shredder")
    member this.AttackTurtles (turtles: NinjaTurtle array) (reporter: Reporter) =
        let turtle = turtles.[rnd.Next(turtles.Length)]
        printfn "%s attacks %s." this.Name turtle.Name
        
        if turtle.Mood > this.Mood then
            this.Die ()
        else
            turtle.Die ()

        reporter.CaptureNews turtle this



let turtles = [|new NinjaTurtle("Leonardo", "blue"); new NinjaTurtle("Michelangelo", "orange"); new NinjaTurtle("Donatello", "purple"); new NinjaTurtle("Raphael", "red")|]
let badGuy = new BadGuy()
let reporter = new Reporter()

for turtle in turtles do
    turtle.Eat ()

badGuy.Eat ()

badGuy.AttackTurtles turtles reporter