data = gets.chomp.split.map(&:to_i)
n = data[0], k = data[1]
Arr = gets.chomp.split.map(&:to_i)
Arr.sort!

leftBorder = 0
rightBorder = Arr.length - 1
lastElem = Arr[rightBorder]
lastMinus = lastElem < 0
multiplication = 1

if k % 2 == 1
  if lastElem > 0
    multiplication *= lastElem
    rightBorder -= 1
    k -= 1
  end
end

mod = 1000000000 + 7
while k >= 1
  if k == 0
    break
  else
    if k == 1
      multiplication *= Arr[rightBorder]
      rightBorder -= 1
      k -= 1
    else
      left = Arr[leftBorder] * Arr[leftBorder + 1]
      right = Arr[rightBorder] * Arr[rightBorder - 1]
      if left >= right and !lastMinus
        multiplication *= left
        leftBorder += 2
      else
        if (left < right and lastMinus)
          multiplication *= left
          leftBorder += 2
        else
          if left < right and !lastMinus
            multiplication *= right
            rightBorder -= 2
          else
            if left >= right and lastMinus
              multiplication *= right
              rightBorder -= 2
            else
              multiplication *= right
              rightBorder -= 2
            end
          end
        end
      end
      k -= 2
    end
  end
  multiplication %= mod
end
puts(multiplication)
