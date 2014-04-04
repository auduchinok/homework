// Eugene Auduchinok (c) 2014

let gpd n = 
    let rec gpd' n d =
        if n % d = 0I then
            let n' = n / d
            if n' = 1I then d
            else gpd' n' d
        else gpd' n (d + 1I)
    gpd' n 2I


gpd 60085175143I