# Eugene Auduchinok, 2015
# Solution for some Stepic task

require 'prime'

def count_primes
  count = 0

  (0...(2 ** 16)).each do |index|
    bits = to_bits index
    nums = map_to_task_nums bits
    count += 1 if rows_and_cols(nums).all?{ |x| Prime.prime?(x) }
  end

  count
end

def to_bits(number)
  (number + (2 ** 16)).to_s(2).split("").drop(1).map(&:to_i)
end

def map_to_task_nums(bits)
  nums = bits.map do |bit|
    case bit
    when 0
      1
    when 1
      2
    end
  end
end

def rows_and_cols(nums)
  result = []
  (0..3).each do |index|
    result << (nums[index]     + nums[index + 4]       + nums[index + 8] + nums[index+12])
    result << (nums[index * 4] + nums[(index * 4) + 1] + nums[(index * 4) + 2] + nums[(index * 4) + 3])
  end

  result
end