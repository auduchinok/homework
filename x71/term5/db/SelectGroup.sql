-- 1. Count orders for each origin city
select name city, count(*) count 
	from orders join cities on orders.origin_city_id = cities.id
	group by name order by count desc

-- 2. Average client order weight
select name, avg(weight) count from orders
	join clients on orders.client_id = clients.id
	group by name order by count desc

-- 3. Maximum ship load for ships having more than 1 sailing
select ship_id "ship id", max(maximum_load) "max load" from sailings join ships on sailings.ship_id = ships.id
	group by ship_id having count(*) > 1

-- 4. Uppercase clients names
select upper(name) from clients

-- 5. Convert containers numbers to strings
select str(number) from containers