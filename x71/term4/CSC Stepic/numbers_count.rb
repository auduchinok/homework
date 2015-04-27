# Eugene Auduchinok, 2015
# Solution for some Stepic task

def count_numbers
  numbers = (0..99999).map{ |x| (x + 100000).to_s.split("").drop(1) }
  numbers.select{ |num| has_no_repeats? num }.count
end

def has_no_repeats?(num)
  (0...5).each do |index|
    return false if num[index] == num[index + 1]
  end

  return true
end