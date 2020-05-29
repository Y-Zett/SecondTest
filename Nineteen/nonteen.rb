n = gets.to_i
data = gets.chomp.split().map(&:to_i)

counter = 0
for i in 0..n
  for j in i..n
    if data[i].to_i > data[j].to_i
      counter += 1
      print data[i], " ", data[j], "\n"
    end
  end
end

puts counter
