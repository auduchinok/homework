-- 1. Distinct origin cities
select distinct name from orders
	join cities on orders.origin_city_id = cities.id

-- 2. Clients and cities names where order price is greater than 50
select clients.name client, cities.name city, cost from orders
	join cities on orders.origin_city_id = cities.id
	join clients on orders.client_id = clients.id
		where cost > 50

-- 3. Origin and destination cities for each order
select origins.name origin, destinations.name destination
	from orders, cities origins, cities destinations
	where orders.origin_city_id = origins.id and orders.destination_city_id = destinations.id

-- 4. All clients and any of their order weights if exists
select name, weight from clients full join orders on clients.id = orders.client_id

-- 5. Containers used
select number "container number" from orders
	join containers on orders.id = containers.order_id