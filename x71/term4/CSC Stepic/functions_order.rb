# Eugene Auduchinok, 2015
# Solution for some Stepic task

f = {}
f["arcsin x"] = ->(x) { Math.asin x }
f["-1/x"]     = ->(x) { -1/x }
f["x^2"]      = ->(x) { x ** 2 }
f["2^x"]      = ->(x) { 2 ** x }
f["x^3"]      = ->(x) { x ** 3 }
f["e^x"]      = ->(x) { Math::E ** x }
f["ln x"]     = ->(x) { Math.log x }

f.map { |name, func| {name: name, result: func.call(0.9) } }
  .sort_by{ |x| x[:result] }.each{ |x| puts "#{x[:name]} #{x[:result]}" }