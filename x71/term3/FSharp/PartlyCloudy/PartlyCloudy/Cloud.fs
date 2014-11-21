module PartlyCloudy.Core

type DaylightType = Morning | Day | Evening | Night

type CreatureType =
    | Puppy
    | Kitten
    | Hedgehog
    | Bearcub
    | Piglet
    | Bat
    | Balloon

type Creature(creatureType : CreatureType) = 
    member x.CreatureType = creatureType

type IDaylight =
    abstract member Current : DaylightType

type ILuminary =
    abstract member IsShining : bool

type IWind =
    abstract member Speed : int

let speedConstraint = 11

type ICourier =
    abstract member GiveBaby : Creature -> unit

type IMagic =
    abstract member CallStork : unit -> ICourier
    abstract member CallDaemon : unit -> ICourier

type Cloud(daylight : IDaylight, luminary : ILuminary, wind : IWind, magic : IMagic) =
    member private x.InternalCreate() =
            match daylight.Current with
            | Night ->
                match luminary.IsShining with
                | true -> Bearcub
                | _ -> match wind.Speed with
                       | 10 -> Bat
                       | _ -> Piglet
            | _ -> match luminary.IsShining with
                   | false -> Piglet
                   | _ -> match wind.Speed with
                          | x when x > 0 && x <= 3 -> Kitten
                          | x when x >= 4 && x <= 6 -> Puppy
                          | x when x >= 7 -> Hedgehog
                          | _ -> Balloon
 
    member x.Create() =
      let creature = new Creature(x.InternalCreate())
      if creature.CreatureType = Bat then
        magic.CallDaemon().GiveBaby(creature)
      else
        magic.CallStork().GiveBaby(creature)