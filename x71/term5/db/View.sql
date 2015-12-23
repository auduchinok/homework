-- 1. Select loyal clients for promotion
create view loyal_clients (name, phone)
	as select name, phone_number from clients join orders on orders.client_id = clients.id
	group by client_id, name, phone_number having count(*) > 1

select * from loyal_clients

drop view loyal_clients

-- 2. Cancel heavy orders
create view heavy_orders (id, weight)
	as select id, weight from orders where weight > 75

delete from heavy_orders

-- 3. Decrease used containers types maximum load
create view used_containers (id, number)
	as select containers.id, number from containers
	join orders on containers.order_id = orders.id

update container_types set maximum_load = maximum_load - 3
	where id in (select container_type_id from containers where id in (select id from used_containers))

drop view used_containers