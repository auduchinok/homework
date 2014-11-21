module PartlyCloudy.Tests

open NUnit.Framework
open FsCheck
open NSubstitute
open PartlyCloudy.Core

let test (dayLightArg : DaylightType, isShiningArg : bool, speedArg : int) (creatureType : CreatureType) =
    let daylight = Substitute.For<IDaylight>()
    let luminary = Substitute.For<ILuminary>()
    let wind = Substitute.For<IWind>()

    let magic = Substitute.For<IMagic>()
    let courier = Substitute.For<ICourier>()

    luminary.IsShining.Returns(isShiningArg) |> ignore
    wind.Speed.Returns(speedArg)             |> ignore
    daylight.Current.Returns(dayLightArg)    |> ignore
    magic.CallDaemon().Returns(courier)      |> ignore
    magic.CallStork().Returns(courier)       |> ignore

    let cloud = new Cloud(daylight, luminary, wind, magic)
    cloud.Create()

    courier.Received().GiveBaby(Arg.Is<Creature> (fun (x : Creature) -> x.CreatureType = creatureType))



[<Test>]
let ``Balloon`` () = test (Morning, true, 0) Balloon 



type KittenGen =
    static member DaylightType() = Arb.fromGen <| Gen.elements [Morning; Day; Evening]
    static member bool() = Arb.fromGen <| Gen.constant true
    static member int() = Arb.fromGen <| Gen.choose (1,3)

[<Test>]
let ``Kitten`` () = 
    Arb.register<KittenGen>() |> ignore
    FsCheck.Check.QuickThrowOnFailure (fun x -> test x Kitten )



type PuppyGen = 
    static member DaylightType() = Arb.fromGen <| Gen.elements [Morning; Day; Evening]
    static member bool() = Arb.fromGen <| Gen.constant true
    static member int() = Arb.fromGen <| Gen.choose (4,6)

[<Test>]
let ``Puppy`` () =
    Arb.register<PuppyGen>() |> ignore
    FsCheck.Check.QuickThrowOnFailure (fun x -> test x Puppy )



type HedgehogGen =
    static member DaylightType() = Arb.fromGen <| Gen.elements [Morning; Day; Evening]
    static member bool() = Arb.fromGen <| Gen.constant true
    static member int() = Arb.fromGen <| Gen.choose (7, 10)

[<Test>]
let ``Hedgehog`` () =
    Arb.register<HedgehogGen>() |> ignore
    FsCheck.Check.QuickThrowOnFailure (fun x -> test x Hedgehog)



type BearcubGen = 
    static member DaylightType() = Arb.fromGen <| Gen.constant Night
    static member bool() = Arb.fromGen <| Gen.constant true
    static member int() = Arb.fromGen <| Gen.choose(0, 10)

[<Test>]
let ``Bearcub`` () = 
    Arb.register<BearcubGen>() |> ignore
    FsCheck.Check.QuickThrowOnFailure (fun x -> test x Bearcub)



type PigletGen1 = 
    static member DaylightType() = Arb.fromGen <| Gen.elements [Morning; Day; Evening]
    static member bool() = Arb.fromGen <| Gen.constant false
    static member int() = Arb.fromGen <| Gen.choose (0, 10)

type PigletGen2 =
    static member DaylightType() = Arb.fromGen <| Gen.constant Night
    static member bool() = Arb.fromGen <| Gen.constant false
    static member int() = Arb.fromGen <| Gen.choose (0, 9)

[<Test>]
let ``Piglet`` () =
    Arb.register<PigletGen1>() |> ignore
    Arb.register<PigletGen2>() |> ignore
    FsCheck.Check.QuickThrowOnFailure (fun x -> test x Piglet)



type BatGen = 
    static member DaylightType() = Arb.fromGen <| Gen.constant Night
    static member bool() = Arb.fromGen <| Gen.constant false
    static member int() = Arb.fromGen <| Gen.constant 10

[<Test>]
let ``Bat`` () =
    Arb.register<BatGen>() |> ignore
    FsCheck.Check.QuickThrowOnFailure (fun x -> test x Bat)