module EmailVerifier.Tests.Verifier

open EmailVerifier.Core.Verifier
open NUnit.Framework
open FsUnit


// Valid emails

[<Test>]
let ``Uppercase`` () = IsValid "ME@EXAMPLE.COM" |> should equal true

[<Test>]
let ``Single letter localpart & subdomain`` () = IsValid "a@b.cc" |> should equal true

[<Test>]
let ``Full name with a dot`` () = IsValid "victor.polozov@mail.ru" |> should equal true

[<Test>]
let ``'info' tld`` () = IsValid "my@domain.info" |> should equal true

[<Test>]
let ``Begins with underscore`` () = IsValid "_.1@mail.com" |> should equal true

[<Test>]
let ``Long tld`` () = IsValid "paints_department@hermitage.museum" |> should equal true


// Invalid emails

[<Test>]
let ``Without at-symbol`` () = IsValid "Me.Com" |> should equal false

[<Test>]
let ``Single letter tld`` () = IsValid "a@b.c" |> should equal false

[<Test>]
let ``Two dotes in a row`` () = IsValid "a..b@mail.ru" |> should equal false

[<Test>]
let ``A dot in the beginning`` () = IsValid ".a@mail.ru" |> should equal false

[<Test>]
let ``A strange tld`` () = IsValid "yo@domain.somedomain" |> should equal false

[<Test>]
let ``Begins with a number`` () = IsValid "1@mail.ru" |> should equal false





