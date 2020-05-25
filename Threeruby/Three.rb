mod = 1000000000 + 7

input = gets.chomp.split.map(&:to_i)
N = input[0]
K = input[1]
seq = gets.chomp.split.map(&:to_i)
km = Array.new()
kp = Array.new()
havepositive = false

for i in 0...N
  a = seq.delete_at(i).to_i
  b = 0
  if a > 0
    b = 0
  else
    b = 1
  end
  seq.insert(i, [a, b])
  if seq[i][0].to_i > 0 and !havepositive
    havepositive = true
  end
end

for i in 0...N
  if seq[i][1] == 1
    seq[i][0] *= -1
  end
end

seq.sort!
t = seq.length.to_i - 1
for i in 0...K
  if (seq[t][1] == 0)
    kp.push(seq[t][0])
  else
    km.push(seq[t][0])
  end
  t -= 1
end

if (km.length.to_i % 2 == 1)
  if (kp.empty? == true)
    if (havepositive == true)
      maxp = 0
      km.pop
      while t >= 0
        if (seq[i][0] > maxp and seq[i][1] == 0)
          maxp = seq[i][0]
        end
        t -= 1
      end
      kp.push(maxp)
    else
      km.clear
      for i in 0...K
        km.push(seq[i][0])
      end
      km[0] *= -1
    end
  else
    maxp = 0
    maxm = 0
    m = 0
    pos = 0
    if kp.empty? == false
      pos = kp[kp.length.to_i - 1]
      kp.pop
    else
      pos = 0
    end

    if km.empty? == false
      m = km[km.length.to_i - 1]
      km.pop
    else
      m = 0
    end

    while t >= 0
      if seq[t][1] == 0
        if seq[t][0] > maxp
          maxp = seq[t][0]
        end
      elsif seq[t][0] > maxm
        maxm = seq[t][0]
      end
      t -= 1
    end

    if maxm * m >= maxp * pos
      km.push(m)
      km.push(maxm)
    else
      kp.push(pos)
      kp.push(maxp)
    end
  end
end

multiply = 1
for el in kp
  multiply *= el
end
for el in km
  multiply *= el
end

multiply.to_i

# if multiply > 0
#   multiply %= mod
# else
#   multiply *= -1
multiply %= mod
#   multiply *= -1
# end
print(multiply)
# print ("kp - > \n")
# for el in kp
#   print el
#   print ", "
# end
# print "\n km - > \n"

# for el in km
#   print el
#   print ", "
# end
