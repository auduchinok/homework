-- Eugene Auduchinok 2014

-- The 'nub' implementation.
import Data.List


-- Task 1
fromFun :: (Integer -> Integer) -> [Integer] -> [(Integer, Integer)]
fromFun f xs = [(x,y) | x <- xs, let y = f x]


-- Taks 2
dom :: [(Integer, Integer)] -> [Integer]
dom f = [x | (x,y) <- f]


-- Task 3
eval :: [(Integer, Integer)] -> Integer -> Integer
eval f x = head [y | (x',y) <- f, x' == x]


-- Task 4
invert :: [(Integer, Integer)] -> [(Integer,Integer)]
invert = map $ \(x,y) -> (y,x)


-- Task 5
(.*.) :: [(Integer,Integer)] ->[(Integer, Integer)] -> [(Integer,Integer)]
(.*.) f g = [ (x, y') | (x',y') <- f, (x,y) <- g, x' == y]


-- Task 6
image :: [(Integer, Integer)] -> [Integer] -> [Integer]
image f xs = nub [ eval f x | x <- xs]


-- Task 7
preimage :: [(Integer, Integer)] -> [Integer] -> [Integer]
preimage f ys = [x | (x,y) <- f, y' <- ys, y == y']


-- Task 8
isInjective :: [(Integer, Integer)] -> Bool
isInjective f = length f == length (normalize f)
                  where normalize [] = []
                        normalize ((x,y):xs) = x : (normalize $ filter (\(_,y') -> y /= y') xs)


-- Task 9
isSurjective :: [(Integer, Integer)] -> Bool
isSurjective f = True


-- Task 10
areMutuallyInverse :: [(Integer, Integer)] -> [(Integer, Integer)] -> Bool
areMutuallyInverse f g = sort' f == sort' (invert g)
                          where sort' = sortBy (\(x,_) (y,_) -> compare x y)
