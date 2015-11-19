#!/usr/bin/env ruby
# Eugene Auduchinok, 2015
require 'Faker'

class String
  def quotify
    "'#{ self }'"
  end
end

def generate_seed(size = 10)
  tables.each do |table|
      size.times { |i| wrap_insert table[:name], table[:columns].join(', '), table[:values].call(i).map(&:to_s).join(', ') }
      puts ''
  end
end

def wrap_insert(table_name, columns, values, prefix = 'K4')
   puts "insert into #{ prefix }_#{ table_name }" +
        "(#{ columns }) values (#{ values })"
end

def tables
  Set.new [
    { name:    'clients',
      columns: ['id', 'name', 'phone_number', 'address', 'info'],
      values:  lambda { |n|
        [n + 1,
         Faker::Name.name.quotify,
         Faker::PhoneNumber.cell_phone.quotify,
         (Faker::Address.street_address + " " + Faker::Address.city).quotify,
         rand(2) == 1 ? Faker::Lorem.sentence.quotify : 'NULL'] } },

    { name:    'cities',
      columns: ['id', 'name'],
      values:  lambda { |n| [n + 1, Faker::Address.city.quotify] } },

    { name:    'orders',
      columns: ['id', 'client_id', 'origin_city_id', 'destination_city_id', 'weight', 'cost'],
      values:  lambda { |n|
        origin_id, destination_id = (1..10).to_a.shuffle.take(2)
        [n + 1,
         rand(10) + 1,
         origin_id,
         destination_id,
         Faker::Number.decimal(2),
         Faker::Number.decimal(2)] } },

    { name:    'container_types',
      columns: ['id', 'empty_weight', 'maximum_load'],
      values:  lambda { |n|
        empty = Faker::Number.decimal(2)
        [n + 1, empty, empty.to_i * 10] } },

    { name:    'ships',
      columns: ['id', 'maximum_load'],
      values:  lambda { |n| [n + 1, Faker::Number.decimal(2).to_i * 100]} },

    { name:    'sailings',
      columns: ['id', 'ship_id', 'origin_city_id', 'destination_city_id'],
      values:  lambda { |n|
        origin_id, destination_id = (1..10).to_a.shuffle.take(2)
          [n + 1,
         rand(10) + 1,
         origin_id,
         destination_id] } },

    { name:    'containers',
      columns: ['id', 'container_type_id', 'order_id', 'number', 'sailing_id'],
      values:  lambda { |n|
        [n + 1,
         rand(10) + 1,
         rand(10) + 1,
         Faker::Number.number(6),
         rand(10) + 1]} } ]
end
