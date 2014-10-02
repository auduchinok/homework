-- Eugene Auduchinok, 2014


-- 2.1
radd (a, b) (c, d) = rnorm (a * d + c * b, b * d)


-- 2.2
rsub (a, b) (c, d) = radd (a, b) (-c, d)


-- 2.3
rmul (a, b) (c, d) = rnorm (a * c, b * d)


-- 2.4
rinv (a, b) = rnorm (b, a)


-- 2.5
rdiv (a, b) (c, d) = rmul (a, d) (b, c)


-- 2.6
rnorm (a, b) =
  (div a c, div b c) where c = gcd a b 


-- 2.7
map' f [] = []
map' f (hd:tl) = f hd : map' f tl


-- 2.8
zip' (x:xs) (y:ys) = (x, y) : zip' xs ys
zip' _ _ = []


-- 2.9
unzip' [] = ([],[])
unzip' ((hd1,hd2):tl) = (hd1:tl1,hd2:tl2) where (tl1, tl2) = unzip' tl


-- 2.10
flatten [] = []
flatten (hd:tl) = hd ++ flatten tl