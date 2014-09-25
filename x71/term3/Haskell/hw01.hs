-- Eugene Auduchinok, 2014


-- Helper functions
counter f k x = counter' x
  where counter' i | i < 1 = 0
        counter' i = (if (f x i) then (k i) else 0) + counter' (i - 1)

counter' = counter (\ a b -> mod a b == 0)

gcd' a b | a == b = a
gcd' a b | a > b  = gcd (a - b) b
gcd' a b          = gcd b a


-- 1.1
isPrime x = divisorsCount x == 2


-- 1.2
areCoprime a b = gcd' a b == 1


-- 1.3
lcm' a b =  quot (abs (a * b)) (gcd' a b)


-- 1.4
divisorsCount = counter' (\ _ -> 1)


-- 1.5
divisorsSum = counter' id


-- 1.6
euler = counter areCoprime (\ _ -> 1)