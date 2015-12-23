create procedure delete_heavy_orders @weight integer as
	declare @id integer
	declare orders_cursor cursor for
		select id from orders where weight >= @weight
	open orders_cursor
	while @@fetch_status = 0
	begin 
		fetch orders_cursor into @id
		delete orders where id = @id
	end
	close orders_cursor

select count(*) from orders
execute delete_heavy_orders @weight = 50