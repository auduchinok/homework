-- 1. Insert Tyumen into cities table
insert into cities (id, name) select max(id + 1), 'Tyumen' from cities

-- 2. Cascade client deletion
insert into clients (id, name, phone_number, address, info) values ((select max(id) + 1 from clients), 'Eugene', null, null, null)

insert into orders (id, client_id, origin_city_id, destination_city_id, weight, cost)
	values ((select max(id) + 1 from orders), (select id from clients where name = 'Eugene'), 4, 5, 49.36, 55.05)

 alter table K4_orders drop constraint FK_K4_orders_client
 alter table K4_orders add constraint FK_K4_orders_client foreign key (client_id) references K4_clients(id) on delete cascade

 alter table K4_containers drop constraint FK_K4_containers_order
 alter table K4_containers add constraint FK_K4_containers_order foreign key (order_id) references K4_orders(id) on delete cascade

 delete clients where name = 'Eugene'

-- 3. Add additional info to the first client
update clients set info = 'Meow' where id = 1

-- 4. Enlarge maximum ships load
update ships set maximum_load = maximum_load * 1.1

-- 5. Add additional info to clients used container number 031218
update clients set info = 'Used 031218'
	where id in (select client_id from orders join containers on containers.order_id = orders.id where number = 031218)
