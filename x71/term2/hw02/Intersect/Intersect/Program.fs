// Eugene Auduchinok (c) 2014
module Intersect

let (?=) (a: float) (b: float) = 
    let eps = 1.e-10
    abs (a - b) < eps

// It's important to remember that Line and VerticalLine are different types here.
[<CustomEquality; NoComparison>]
type Set =
    | NoPoint
    | Point of float * float
    | Line  of float * float
    | VerticalLine of float
    | LineSegment of (float * float) * (float * float)
    | Intersect of Set * Set
    
    override x.Equals (o: obj) =
        match o with
        | :? Set as o ->
            match x, o with
            | NoPoint, NoPoint -> true
            | Point (x1, y1), Point (x2, y2) -> x1 ?= x2 && y1 ?= y2
            | Line (a1, b1), Line (a2, b2) -> a1 ?= a2 && b1 ?= b2
            | VerticalLine (x1), VerticalLine (x2) -> x1 ?= x2
            | LineSegment ((x1, y1), (x2, y2)), LineSegment ((x3, y3), (x4, y4)) ->
                (x1 ?= x3 && y1 ?= y3 && x2 ?= x4 && y2 ?= y4) || (x1 ?= x4 && y1 ?= y4 && x2 ?= x3 && y2 ?= y3)
            | _ -> false
        | _ -> false
    override x.GetHashCode() = hash x
   
let segmentToLine = function
    | LineSegment((x1, y1), (x2, y2)) ->
        if x1 = x2 then VerticalLine (x1)
        else Line ((y1 - y2) / (x1 - x2), (y2 - y1) / (x1 - x2) * x1 + y1)
    | _ -> failwith "Wrong argument."


let rec intersect = function
    // Match intersections.
    | Intersect (a, b) ->
        match a, b with
        | Intersect (a, b), x | x, Intersect (a, b) ->
            let a' = intersect (Intersect (a, b))
            let b' = 
                match x with
                | Intersect (a, b) -> intersect (Intersect (a, b))
                | _ -> x
            intersect (Intersect (a', b'))

        // No point.
        | NoPoint, _ | _, NoPoint ->
            NoPoint

        // Two points.
        | Point (x1, y1), Point (x2, y2) ->
            if x1 ?= x2 && y1 ?= y2 then Point (x1, y1)
            else NoPoint
        
        // Point and vertical line.
        | Point (x0, y0), VerticalLine (x)
        | VerticalLine (x), Point (x0, y0) ->
            if x0 ?= x then Point (x0, y0) else NoPoint

        // Point and line.
        | Point (x, y), Line (a, b)
        | Line (a, b), Point (x, y) ->
            if a * x + b ?= y then Point (x, y) else NoPoint

        // Point and line segment.
        | Point (x0, y0), LineSegment ((x1, y1), (x2, y2))
        | LineSegment ((x1, y1), (x2, y2)), Point (x0, y0) ->
            if x1 ?= x2 then
                if x0 ?= x1 && y0 >= min y1 y2 && y0 <= max y1 y2
                then Point (x0, y0)
                else NoPoint
            else
                let p = (x0 - x2) / (x1 - x2)
                if (x1 - x2) * (y0 - y2) ?= (x0 - x2) * (y1 - y2) && p >= 0.0 && p <= 1.0
                then Point (x0, y0)
                else NoPoint

        // Two lines.
        | Line(a1, b1) as line, Line (a2, b2) ->
            if a1 ?= a2 then
                if b1 ?= b2 then line
                else NoPoint
            else
                let x = (b1 - b2) / (a2 - a1)
                let y = (a2 * b1 - a1 * b2) / (a2 - a1)
                Point (x, y)

        // Line and vertical line.
        | Line (a, b), VerticalLine (x)
        | VerticalLine (x), Line (a, b) ->
            Point (x, a * x + b)

        // Line and line segment.
        | Line (a, b), LineSegment ((x1, y1), (x2, y2))
        | LineSegment ((x1, y1), (x2, y2)), Line (a, b) ->
            let segment = LineSegment ((x1, y1), (x2, y2))
            let line = Line (a, b)
            // Convert the segment to a line, intersect lines,
            // intersect the result with the initial segment.
            let linesIntersection = intersect (Intersect (segmentToLine segment, line))
            match linesIntersection with
            | Line (_) -> segment
            | Point (_) as point -> intersect (Intersect (segment, point))
            | _ -> failwith "Wrong type."

        // Two vertical lines.
        | VerticalLine (x1) as line, VerticalLine (x2) ->
            if x1 ?= x2 then line else NoPoint

        // Line segment and verical line.
        | VerticalLine (x), LineSegment ((x1, y1), (x2, y2))
        | LineSegment ((x1, y1), (x2, y2)), VerticalLine (x) ->
            let segment = LineSegment ((x1, y1), (x2, y2))
            let linesIntersection = intersect (Intersect (segmentToLine segment, VerticalLine (x)))
            match linesIntersection with
            | VerticalLine (_) -> segment
            | Point (_) -> intersect (Intersect (segment, linesIntersection))
            | _ -> failwith "Wrong type."

        // Two Line Segments
        | LineSegment ((x1, y1), (x2, y2)), LineSegment ((x3, y3), (x4, y4)) ->
            let seg1 = a
            let seg2 = b
            let line1 = segmentToLine seg1
            let line2 = segmentToLine seg2

            match intersect (Intersect (line1, line2)) with
            | NoPoint -> NoPoint
            | Point (_) as point->
                match intersect (Intersect (Intersect (point, seg1), (Intersect (point, seg2)))) with
                | Point (_) -> point
                | _ -> NoPoint
            | Line (_) ->
                let sortedPoints = Array.sortBy fst [|(x1, y1); (x2, y2); (x3, y3); (x4, y4)|]
                LineSegment ((sortedPoints.[1], sortedPoints.[2]))

            | _ -> failwith "Wrong type"

    | LineSegment ((x1, y1), (x2, y2)) as segment ->
        if x1 ?= x2 && y1 ?= y2 then Point (x1, y1)
        else segment

    | x -> x