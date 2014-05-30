module Intersect.Tests

open NUnit.Framework
open FsUnit

[<Test>]
let ``Segment to line`` () =
    Intersect.segmentToLine (LineSegment((2.0, 1.0), (1.0, 3.0)))
    |> should (equalWithin 0.5) (Line(-2.0, 5.0))

[<Test>]
let ``Equal points`` () = 
    intersect (Intersect (Point (1.0, 2.0), Point(1.0, 2.0)))
    |> should equal (Point (1.0, 2.0))

[<Test>]
let ``Equal lines`` () =
    intersect (Intersect (Line(1.0, 0.0), Line(1.0, 0.0)))
    |> should equal (Line(1.0, 0.0))

[<Test>]
let ``Point and line`` () =
    intersect (Intersect (Line(1.0, 0.0), Point(2.0, 2.0)))
    |> should equal (Point(2.0, 2.0))

[<Test>]
let ``Line and vertical Line`` () =
    intersect (Intersect (Line (1.0, 2.0), VerticalLine (4.0)))
    |> should equal (Point(4.0, 6.0))

[<Test>]
let ``Point and line segment`` () =
    intersect (Intersect (LineSegment ((1.0, 1.0), (3.0, 2.0)), Point (2.0, 1.5)))
    |> should equal (Point (2.0, 1.5))

[<Test>]
let ``Line and line segment`` () =
        intersect (Intersect (Line (2.0, -1.0), LineSegment ((1.0, 3.0), (2.0, 1.0))))
        |> should equal (Point (1.5, 2.0))

[<Test>]
let ``Vertical lines`` () =
    intersect (Intersect (VerticalLine (1.0), VerticalLine (1.0)))
    |> should equal (VerticalLine (1.0))
    
[<Test>]
let ``Two lines and point`` () =
    intersect (Intersect (Intersect (Line (1.0, 1.0), Line (-1.0, 5.0)), Point (2.0, 3.0)))
    |> should equal (Point (2.0, 3.0))

[<Test>]
let ``Line segment and vertical line`` () =
    intersect (Intersect (LineSegment ((1.0, 2.0), (1.0, 5.0)), VerticalLine (1.0)))
    |> should equal (LineSegment ((1.0, 2.0), (1.0, 5.0)))



[<Test>]
let ``Two points`` () =
    intersect (Intersect (Point (1.0, 2.0), Point (1.1, 2.2)))
    |> should equal (NoPoint)
    
[<Test>]
let ``No point and line`` () =
    intersect (Intersect (NoPoint, Line(1.0, 2.0)))
    |> should equal (NoPoint)

[<Test>]
let ``Parallel lines`` () =
    intersect (Intersect (Line(1.0, 0.0), Line(1.0, 1.0)))
    |> should equal (NoPoint)

[<Test>]
let ``Non-intersecting line segment and verical line`` () =
    intersect (Intersect (VerticalLine (-1.0), LineSegment ((-3.0, 1.0), (-2.0, 3.0))))
    |> should equal (NoPoint)

[<Test>]
let ``(non-intersecting) Point and line segment`` () = 
    intersect (Intersect (LineSegment ((-3.0, 1.0), (-2.0, 3.0)), Point (-1.0, 5.0)))
    |> should equal (NoPoint)
    
[<Test>]
let ``(non-intersecting) Vertical lines`` () =
    intersect (Intersect (VerticalLine (1.0), VerticalLine (2.0)))
    |> should equal (NoPoint)

[<Test>]
let ``Intersecting segments `` () =
    intersect (Intersect (LineSegment ((1.0, 1.0), (3.0, 3.0)), LineSegment ((2.0, 2.0), (5.0, 5.0))))
    |> should equal (LineSegment ((3.0, 3.0), (2.0, 2.0)))