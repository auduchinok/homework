-- 1. Clients names who used containers of first five types
select distinct name client from clients
	join orders on orders.client_id = clients.id
	join containers on containers.order_id = orders.id
	join container_types types on types.id = containers.container_type_id
		where types.id in (1,2,3,4,5)

-- 2. Percentage of clients with orders having additional info
select cast(count(distinct clients.id) as float) / (select count(*) from clients) percentage
	from clients join orders on orders.client_id = clients.id where info <> ''

-- 3. People used container number 031218
select name from clients
	where 031218 in (select number from containers join orders on containers.order_id = orders.id where orders.client_id = clients.id)

-- 4. All destination cities for orders from Saulton
select name from cities
	where cities.name in
		(select destinations.name from orders
			join cities destinations on orders.destination_city_id = destinations.id
			join cities origins on orders.origin_city_id = origins.id
				where origins.name = 'Saulton')

-- 5. All cities in orders
select name cities from cities where cities.id in (select origin_city_id from orders)
union
select name from cities where cities.id in (select destination_city_id from orders)