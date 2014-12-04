module ShoppingTests.Tests 

open NUnit.Framework
open FsUnit
open Shop

type EmptyShop() = 
    interface IShop with
        member x.CanSell (good : Good) = false
        member x.Sell (goods:Good list) = []

type AnytimeFullShop() = 
    interface IShop with
        member x.CanSell (good : Good) = true
        member x.Sell (goods:Good list) = goods

type TestCalendar (day : System.DayOfWeek) =
    interface Customer.ICalendar  with
        member x.DayOfWeek = day

let calendar day = new TestCalendar(day) :> Customer.ICalendar
let calendarFriday = calendar System.DayOfWeek.Friday 
   
[<Test>]
let test1 () = 
    let customer = new Customer.Customer(calendarFriday)
    customer.IsDrunk |> should be False
 
[<Test>]
let test2 () = 
    let customer = new Customer.Customer(calendarFriday)
    let emptyShop = new EmptyShop()

    customer.GoShopping emptyShop
    customer.GetDrunk ()
    customer.IsDrunk |> should be False

[<Test>]
let test3 () = 
    let customer = new Customer.Customer(calendarFriday)
    let allInclusiveShop = new AnytimeFullShop()

    customer.GoShopping allInclusiveShop
    customer.GetDrunk ()
    customer.IsDrunk |> should be True

[<Test>]
let ``test not drunk on Thursday`` () = 
    let customer = new Customer.Customer(calendar System.DayOfWeek.Thursday)
    let allInclusiveShop = new AnytimeFullShop()

    customer.GoShopping allInclusiveShop
    customer.GetDrunk ()
    customer.IsDrunk |> should be False

let shouldDrunk (day : System.DayOfWeek) = 
    let customer = new Customer.Customer(calendar day)
    let allInclusiveShop = new AnytimeFullShop()

    customer.GoShopping allInclusiveShop
    customer.GetDrunk ()
    (customer.IsDrunk && day = System.DayOfWeek.Friday) || (not customer.IsDrunk && day <> System.DayOfWeek.Friday)

[<Test>]
let ``Should only get drunk on Friday`` () = 
    FsCheck.Check.QuickThrowOnFailure shouldDrunk
