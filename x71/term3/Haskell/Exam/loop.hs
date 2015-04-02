-- Exam 2014.01.22
-- Eugene Auduchinok

loop [] = []
loop xs = xs' where
	xs' = xs ++ xs'
