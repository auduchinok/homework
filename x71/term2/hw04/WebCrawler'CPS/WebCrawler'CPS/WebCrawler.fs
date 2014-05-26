// Eugene Auduchinok (c) 2014   

module WebCrawler

open System
open WebR
open Map'CPS

let getImages (page : string) =
    let comparison = StringComparison.InvariantCultureIgnoreCase
    let rec getImages' (index : int) =
        let imageIndex = page.IndexOf("<img", index, comparison)
        match imageIndex with
        | -1 -> []
        | foundIndex ->
            let srcString = "src=\""
            let imagePathIndex = page.IndexOf(srcString , foundIndex, comparison) + srcString.Length
            let pathEndIndex = page.IndexOf("\"", imagePathIndex)
            let pathLength = pathEndIndex - imagePathIndex

            page.Substring(imagePathIndex, pathLength) :: getImages' pathEndIndex
            
    getImages' 0


let filterImages = function
    | images when List.length images < 5 -> []
    | images -> images |> Seq.distinct |> Seq.toList


let crawl sites =
    map (fun url callback -> getUrl url (getImages >> filterImages >> callback)) (printfn "%A") sites


let sites = ["http://sputnik.ru"; "https://google.com"]
let images = crawl sites

System.Console.ReadKey () |> ignore

//let rec crawl callback = function
//    | [] -> callback []
//    | head :: tail -> getUrl head (fun head' -> crawl (fun tail' -> callback ((getImages head' |> filterImages) @ tail' )) tail)