-- 1. Clients with additional info
select name, info from clients
	where info <> '' order by name

-- 2. Orders with weight below 50.0
select id, weight from orders
	where weight between 0 and 50 order by weight desc

-- 3. Distinct origin city ids
select distinct origin_city_id cities from orders

-- 4. Count distinct origin cities
select count(distinct origin_city_id) "distinct cities" from orders

-- 5. Average order cost
select avg(cost) "average cost" from orders