-- Exam 2014.01.22
-- Eugene Auduchinok

remove :: Eq a => [a] -> [a]
remove [] = []
remove (x:xs)
	| elem x xs = remove (filter (/= x) xs)
	| otherwise = x : (remove xs)