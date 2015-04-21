-- Eugene Auduchinok, 2015

delete from dbo.[Order];
delete from dbo.[Flight];
delete from dbo.[Airplane];
delete from dbo.[Pilot];
delete from dbo.[Customer];

insert into dbo.[Pilot] ([Id], [FirstName], [SecondName]) values
(1, N'Джон', N'Вачовски'),
(2, N'Тим', N'Бёртон'),
(3, N'Алекси', N'Лайхо') 

insert into dbo.[Airplane] ([Id], [Type], [PilotId], [Number], [Seats]) values
(1, N'Boeing',     1,	N'1234',   255),
(2, N'Boeing',	   2, N'121219', 300),
(3, N'NotABoeing', 3, N'СП-777', 7),
(4, N'NotABoeing', 3,	N'0555',   50)

insert into dbo.[Customer] ([Id], [FirstName], [SecondName], [PhoneNumber], [PassportNumber], [BankCardNumber]) values
(1, N'Евгений', N'Аудучинок', N'+79210000000', N'1234 123456', N'1234123412341324'),
(2, N'Владислав', N'Попов', N'88002000600', N'7890 123456', N'0101001100001111'),
(3, N'Билл', N'Гейтс', N'+7(3452)123-456', N'1234 567890', N'1234567812345678')

insert into dbo.[Flight] ([Id], [Number], [Origin], [Destination], [DepartureTime], [AirplaneId]) values
(1, N'СПБ-123', N'ТМН', N'СПБ', '2015-05-04 12:35:29', 1),
(2, N'121212', N'СПБ', N'ТМН', '2015-01-01 07:15:00', 2),
(3, N'12345', N'NYC', N'QWE', '2015-02-03 08:25:00', 3),
(4, N'June', N'SCH', N'KRM', '2014-07-01 11:15', 2)


insert into dbo.[Order] ([Id], [CustomerId], [CreatedAt], [FlightId], [Seats], [Price], [Canceled]) values
(1, 3, '2015-04-08', 1, 2, 42, 0),
(2, 1, '2015-05-07', 1, 1, 3.14, 0),
(3, 3, '2014-02-01', 3, 4, 2.71, 0),
(4, 3, '2014-03-04', 4, 2, 123, 1)