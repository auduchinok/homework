-- 1. Add client loyalty note
create trigger client_loyality on K4_orders for insert as
	if (select count(*) from orders where client_id = (select client_id from inserted)) > 1
		update clients set info = concat(info,' (loyal!)') where id = (select client_id from inserted)

-- 2. Clients ids index
create unique index clients_ids on K4_clients (id)

-- 3. Clients names and ids index
create index clients_names on K4_clients (id, name)

-- 4. Clients uniqueness
create unique index clients_names_unique on K4_clients (name, address)