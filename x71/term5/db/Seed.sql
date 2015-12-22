-- Eugene Auduchinok, 2015

-- Create tables
create table K4_clients(
  id integer not null,
  name nvarchar(50) not null,
  phone_number nvarchar(15),
  address nvarchar(50),
  info nvarchar(max)
  constraint K4_clients_PK primary key (id)
);

create table K4_cities(
  id integer not null,
  name nvarchar(50)
  constraint K4_cities_PK primary key (id)
);

create table K4_orders(
  id integer not null,
  client_id integer not null,
  origin_city_id integer not null,
  destination_city_id integer not null,
  weight float not null,
  cost money not null
  constraint K4_orders_PK primary key (id)
);

create table K4_container_types(
  id integer not null,
  empty_weight float not null,
  maximum_load float not null
  constraint K4_container_types_PK primary key (id)
);

create table K4_ships(
  id integer not null,
  maximum_load float not null,
  constraint K4_ships_PK primary key (id)
);

create table K4_sailings(
  id integer not null,
  ship_id integer not null,
  origin_city_id integer not null,
  destination_city_id integer not null
  constraint K4_sailings_PK primary key (id)
);

create table K4_containers(
  id integer not null,
  container_type_id integer not null,
  order_id integer not null,
  number integer not null,
  sailing_id integer not null
  constraint K4_containers_PK primary key (id)
);

-- Create foreign keys

alter table K4_orders add constraint FK_K4_orders_client
  foreign key (client_id)
  references K4_clients(id)
;

alter table K4_orders add constraint FK_K4_orders_origin_city
  foreign key (origin_city_id)
  references K4_cities(id)
;

alter table K4_orders add constraint FK_K4_orders_destination_city
  foreign key (origin_city_id)
  references K4_cities(id)
;

alter table K4_sailings add constraint FK_K4_sailings_ship
  foreign key (ship_id)
  references K4_ships(id)
;

alter table K4_sailings add constraint FK_K4_sailings_origin_city
  foreign key (origin_city_id)
  references K4_cities(id)
;

alter table K4_sailings add constraint FK_K4_sailings_destination_city
  foreign key (destination_city_id)
  references K4_cities(id)
;

alter table K4_containers add constraint FK_K4_containers_type
  foreign key (container_type_id)
  references K4_container_types(id)
;

alter table K4_containers add constraint FK_K4_containers_order
  foreign key (order_id)
  references K4_orders(id)
;

alter table K4_containers add constraint FK_K4_containers_sailing
  foreign key (sailing_id)
  references K4_sailings(id)
;

-- Create synonyms

create synonym clients for K4_clients
create synonym cities for K4_cities
create synonym orders for K4_orders
create synonym container_types for K4_container_types
create synonym ships for K4_ships
create synonym sailings for K4_sailings
create synonym containers for K4_containers

-- Seed

insert into K4_clients(id, name, phone_number, address, info) values (1, 'Ms. Roy Huel', '104.974.3852', '3861 Monserrat Hollow Janatown', NULL)
insert into K4_clients(id, name, phone_number, address, info) values (2, 'Jonatan Rohan', '(208) 755-7888', '53105 Balistreri Squares North Maybelleborough', NULL)
insert into K4_clients(id, name, phone_number, address, info) values (3, 'Jeramie Hagenes', '713.663.8697', '221 Weissnat Forge Faheyfurt', 'Quasi ratione voluptatibus id.')
insert into K4_clients(id, name, phone_number, address, info) values (4, 'Jamir Wolf', '(982) 622-9492', '10067 Quigley Burg Port Ludie', NULL)
insert into K4_clients(id, name, phone_number, address, info) values (5, 'Dr. Vincent Ondricka', '699.737.4844', '28680 Leda Prairie East Alexside', 'Est voluptatibus ea ab qui nostrum.')
insert into K4_clients(id, name, phone_number, address, info) values (6, 'Lia Balistreri', '(150) 760-1908', '48775 Alaina Meadows Batzside', NULL)
insert into K4_clients(id, name, phone_number, address, info) values (7, 'Schuyler Schroeder', '354-355-4063', '92500 Haag Stream Heberborough', NULL)
insert into K4_clients(id, name, phone_number, address, info) values (8, 'Dylan Batz IV', '1-323-362-6846', '807 Senger Lake Schroederburgh', NULL)
insert into K4_clients(id, name, phone_number, address, info) values (9, 'Howard Mertz', '932.942.6306', '64046 Hilll Inlet Reidmouth', 'Nihil itaque in nobis perspiciatis est aut odit.')
insert into K4_clients(id, name, phone_number, address, info) values (10, 'Cristal Green', '946.501.2336', '380 Lucienne Dale Annabelleburgh', 'Temporibus voluptatem inventore exercitationem voluptas dignissimos in explicabo.')

insert into K4_cities(id, name) values (1, 'Gibsonbury')
insert into K4_cities(id, name) values (2, 'North Kaelaburgh')
insert into K4_cities(id, name) values (3, 'South Samaramouth')
insert into K4_cities(id, name) values (4, 'Winonachester')
insert into K4_cities(id, name) values (5, 'Port Janet')
insert into K4_cities(id, name) values (6, 'South Ernestine')
insert into K4_cities(id, name) values (7, 'Alview')
insert into K4_cities(id, name) values (8, 'Deondretown')
insert into K4_cities(id, name) values (9, 'Abigalefort')
insert into K4_cities(id, name) values (10, 'Saulton')

insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (1, 7, 4, 5, 49.36, 55.05)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (2, 3, 2, 3, 15.77, 15.03)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (3, 5, 10, 8, 22.83, 81.76)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (4, 2, 10, 1, 83.74, 12.96)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (5, 4, 6, 10, 65.32, 60.83)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (6, 3, 3, 7, 76.17, 82.51)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (7, 1, 6, 5, 86.42, 57.28)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (8, 8, 4, 6, 26.33, 32.66)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (9, 3, 8, 9, 59.27, 16.83)
insert into K4_orders(id, client_id, origin_city_id, destination_city_id, weight, cost) values (10, 1, 9, 7, 36.76, 66.65)

insert into K4_container_types(id, empty_weight, maximum_load) values (1, 37.54, 370)
insert into K4_container_types(id, empty_weight, maximum_load) values (2, 44.37, 440)
insert into K4_container_types(id, empty_weight, maximum_load) values (3, 55.36, 550)
insert into K4_container_types(id, empty_weight, maximum_load) values (4, 28.87, 280)
insert into K4_container_types(id, empty_weight, maximum_load) values (5, 72.54, 720)
insert into K4_container_types(id, empty_weight, maximum_load) values (6, 84.81, 840)
insert into K4_container_types(id, empty_weight, maximum_load) values (7, 32.97, 320)
insert into K4_container_types(id, empty_weight, maximum_load) values (8, 85.89, 850)
insert into K4_container_types(id, empty_weight, maximum_load) values (9, 38.71, 380)
insert into K4_container_types(id, empty_weight, maximum_load) values (10, 30.62, 300)

insert into K4_ships(id, maximum_load) values (1, 2200)
insert into K4_ships(id, maximum_load) values (2, 9300)
insert into K4_ships(id, maximum_load) values (3, 5200)
insert into K4_ships(id, maximum_load) values (4, 5300)
insert into K4_ships(id, maximum_load) values (5, 3800)
insert into K4_ships(id, maximum_load) values (6, 1000)
insert into K4_ships(id, maximum_load) values (7, 5400)
insert into K4_ships(id, maximum_load) values (8, 7900)
insert into K4_ships(id, maximum_load) values (9, 700)
insert into K4_ships(id, maximum_load) values (10, 5300)

insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (1, 10, 7, 2)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (2, 1, 10, 2)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (3, 7, 8, 6)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (4, 4, 1, 7)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (5, 10, 2, 4)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (6, 2, 10, 2)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (7, 10, 10, 7)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (8, 2, 10, 2)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (9, 5, 4, 1)
insert into K4_sailings(id, ship_id, origin_city_id, destination_city_id) values (10, 2, 6, 7)

insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (1, 7, 2, 863453, 9)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (2, 7, 6, 354347, 7)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (3, 5, 7, 238200, 4)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (4, 3, 3, 279934, 9)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (5, 5, 3, 734582, 8)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (6, 8, 9, 579752, 8)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (7, 4, 4, 813395, 8)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (8, 6, 4, 842845, 7)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (9, 4, 3, 755358, 3)
insert into K4_containers(id, container_type_id, order_id, number, sailing_id) values (10, 7, 1, 031218, 1)



--DROP TABLE K4_containers;
--DROP TABLE K4_sailings;
--DROP TABLE K4_ships;
--DROP TABLE K4_container_types;
--DROP TABLE K4_orders;
--DROP TABLE K4_cities;
--DROP TABLE K4_clients;
