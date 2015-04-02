-- Exam 2014.01.22
-- Eugene Auduchinok

data L a = N | O (L a) a (L a) | E (L a) (L a)

instance (Show a) => Show (L a) where
	show N = "[]"
	show x = "[" ++ (init $ show' x) ++ "]" where
		show' N         = ""
		show' (E a b)   = show' a ++ show' b
		show' (O a x b) = show' a ++ show x ++ "," ++ show' b

cons :: a -> L a -> L a
cons x N         = O N x N
cons x (O a y b) = E (cons x a) (cons y b)
cons x (E a b)   = O (cons x $ initL a) (lastL a) b

lastL :: L a -> a
lastL (O N x _) = x
lastL (O _ _ b) = lastL b
lastL (E _ b)   = lastL b

initL :: L a -> L a
initL (O N _ _) = N
initL (O a x b) = E a (cons x $ initL b)
initL (E a b)   = O (initL a) (lastL a) (initL b)

fromList :: [a] -> L a
fromList = foldr cons N

len :: L a -> Integer
len N         = 0
len (E a _)   = 2 * len a
len (O a _ _) = 1 + 2 * len a

mapL :: (a -> b) -> L a -> L b
mapL f N         = N
mapL f (E a b)   = E (mapL f a) (mapL f b)
mapL f (O a x b) = O (mapL f a) (f x) (mapL f b)

foldL :: (a -> b -> b) -> L a -> b -> b
foldL f N acc         = acc
foldL f (E a b) acc   = foldL f b $ foldL f a acc
foldL f (O a x b) acc = foldL f b $ f x $ foldL f a acc

revert :: L a -> L a
revert N         = N
revert (O a x b) = O (revert b) x (revert a)
revert (E a b)   = E (revert b) (revert a)
