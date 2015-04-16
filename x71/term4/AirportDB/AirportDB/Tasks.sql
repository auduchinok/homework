-- Eugene Auduchinok, 2015

-- 1.1. Выбрать всю информацию обо всех самолетах.
select * from dbo.[Airplane];


-- 1.2. Выбрать самолеты типа Boeing.
select * from dbo.[Airplane] a where a.Type = N'Boeing';


-- 1.3. Выбрать номера самолетов, у которых число мест >=100 и упорядочить их по количеству мест.
select * from dbo.[Airplane] a where a.Seats > 100 order by a.Seats;


--1.4. Выбрать номера и экипаж всех быстрых (быстрее скорости звука) самолетов, у которых в номере встречается число 19. Список упорядочить по номеру самолета.
select * from dbo.[Airplane] a where a.Number like N'%19%';


-- 1.5. Выдать номера самолетов, фамилию заказчика и время отлета, улетевших с 11:00 до 23:00 1 июля 2014 года.
select a.Number, c.SecondName, f.DepartureTime from dbo.[Airplane] a, dbo.[Customer] c, dbo.[Flight] f where f.DepartureTime >= '2014-07-01 11:00' and f.DepartureTime <= '2014-07-01 23:00';


-- 2.1 Посчитать общую сумму оплаты по всем выполненным заказам.
select sum(o.Price) as TotalPrice from dbo.[Order] o;


-- 2.2 Получить список экипажей, отсортированный по количеству выполненных заказов.
select a.Number, o.Orders from dbo.Airplane a,
	(select a.Id, count(o.Id) as Orders from dbo.[Airplane] a, dbo.[Flight] f, dbo.[Order] o where o.FlightId = f.Id and f.AirplaneId = a.Id group by a.Id) o
		where a.Id = o.Id order by o.Orders desc;


-- 2.3 Выбрать постоянных клиентов (не менее 5 выполненных заказов).
select * from (select c.Id, count(o.Id) as Orders from dbo.[Customer] c, dbo.[Order] o where c.Id = o.CustomerId group by c.Id) c where c.Orders >= 5;


-- 3.1 Удалить клиента Попова.
delete from dbo.[Customer] where [SecondName] = N'Попов';


-- 3.2 Удалить клиента Гейтса и все его заказы.
delete from dbo.[Order] where
	[CustomerId] = (select [Id] from dbo.Customer where [SecondName] = N'Гейтс');

delete from dbo.[Customer] where [SecondName] = N'Гейтс';


-- 3.3 Заменить номер самолета ‘121212’ на ‘521212’.
update dbo.[Flight] set [Number] = N'521212' where [Number] = N'121212';