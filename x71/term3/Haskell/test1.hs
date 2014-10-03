-- Eugene Auduchinok 2014

-- Task 1
sprod (x:xs) (y:ys) = x*y + sprod xs ys
sprod _ _ = 0


-- Task 2
normalize [] = []
normalize (x:xs) = x : (normalize $ filter (/= x) xs)


-- Task 3
sort [] = []
sort (x:xs) = sort lt ++ [x] ++ sort gt
  where lt = filter (<= x) xs
        gt = filter (> x) xs


-- Task 4
isProgression (x1:r@(x2:x3:xs))
  | x2 - x1 /= x3 - x2 = False
  | otherwise          = isProgression r
isProgression _ = True


-- Task 5
isFunction [] = True
isFunction ((x,_):xs)
  | length [ z | (z,_) <- xs, z == x] /= 0 = False
  | otherwise = isFunction xs


-- Task 6
isSymmetric r =
  foldl (&&) True (map (\(x,y) -> (y,x) `elem` r) r)


-- Task 7
isReflexive r =
  foldl (&&) True (map (\(x,_) -> (x,x) `elem` r) r)


-- Task 8
closure r =
  if length r == length c then r else closure c
  where c = normalize [ (x1,y2) | (x1,y1) <- r, (x2,y2) <- r, y1 == x2 || (x1 == x2 && y1 == y2) ]

-- Task 9
isTransitive r = length r == (length $ closure r)