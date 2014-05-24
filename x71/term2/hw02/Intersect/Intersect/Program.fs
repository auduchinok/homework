// Eugene Auduchinok (c) 2014
module Intersect

// It's important to remember that Line and VerticalLine are different types here.
type Set =
    | NoPoint
    | Point of float * float
    | Line  of float * float
    | VerticalLine of float
    | LineSegment of (float * float) * (float * float)
    | Intersect of Set * Set


// заменить
let (=) (a:float) (b:float) = 
    let eps = 1.e-10
    abs (a - b) < eps

   
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
            if x1 = x2 && y1 = y2 then Point (x1, y1)
            else NoPoint
        
        // Point and vertical line.
        | Point (x0, y0), VerticalLine (x)
        | VerticalLine (x), Point (x0, y0) ->
            if x0 = x then Point (x0, y0) else NoPoint

        // Point and line.
        | Point (x, y), Line (a, b)
        | Line (a, b), Point (x, y) ->
            if a * x + b = y then Point (x, y) else NoPoint

        // Point and line segment.
        | Point (x0, y0), LineSegment ((x1, y1), (x2, y2))
        | LineSegment ((x1, y1), (x2, y2)), Point (x0, y0) ->
            if x1 = x2 then
                if x0 = x1 && y0 >= min y1 y2 && y0 <= max y1 y2
                then Point (x0, y0)
                else NoPoint
            else
                let p = (x0 - x2) / (x1 - x2)
                if (x1 - x2) * (y0 - y2) = (x0 - x2) * (y1 - y2) && abs p <= 1.0
                then Point (x0, y0)
                else NoPoint

        // Two lines.
        | Line(a1, b1) as line, Line (a2, b2) ->
            if a1 = a2 then
                if b1 = b2 then line
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
            if x1 = x2 then line else NoPoint

        // Line segment and verical line.
        | VerticalLine (x), LineSegment ((x1, y1), (x2, y2))
        | LineSegment ((x1, y1), (x2, y2)), VerticalLine (x) ->
            let segment = LineSegment ((x1, y1), (x2, y2))
            let linesIntersection = intersect (Intersect (segmentToLine segment, VerticalLine (x)))
            match linesIntersection with
            | VerticalLine (_) -> segment
            | Point (_) -> intersect (Intersect (segment, linesIntersection))
            | _ -> failwith "Wrong type."

        | LineSegment ((x1, y1), (x2, y2)), LineSegment ((x3, y3), (x4, y4)) ->
            failwith "not implemented"
            // приводим оба отрезка к прямым,
            // смотрим их пересечение, если пересечение - точка, смотрим, принадлежит
            // ли она исходным отрезкам, если - прямая, нужно как-то найти границы общей части

    | LineSegment ((x1, y1), (x2, y2)) as segment ->
        if x1 = x2 && y1 = y2 then Point (x1, y1)
        else segment

    | x -> x