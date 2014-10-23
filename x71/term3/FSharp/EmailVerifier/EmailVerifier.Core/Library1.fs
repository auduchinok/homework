namespace EmailVerifier.Core

open System.Text.RegularExpressions

module Verifier =

    let localPart = "[a-z_](\.?\w+)*"
    let subdomains = "([a-z]+\.)+"
    let topLevelDomain = "(name|info|museum|[a-z]{2,3})"

    let addressRegExp = "^" + localPart + "@" + subdomains + topLevelDomain + "$"

    let regex = new Regex(addressRegExp, RegexOptions.IgnoreCase)
    let IsValid address = regex.IsMatch(address)