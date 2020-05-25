answer = 1
Modul = 1000000000 + 7

data = gets.chomp.split.map(&:to_i)
n = data[0], k = data[1]
A = gets.chomp.split.map(&:to_i)
A.sort!

leftBorder = 0
rightBorder = A.length - 1
lastElem = A[rightBorder]
lastMinus = lastElem < 0

if k % 2 == 1
  if lastElem > 0
    answer *= lastElem
    rightBorder -= 1
    k -= 1
  end
end

while k >= 1
  if k == 0
    break
  elsif k == 1
    answer *= A[rightBorder]
    rightBorder -= 1
    k -= 1
  else
    left = A[leftBorder] * A[leftBorder + 1]
    right = A[rightBorder] * A[rightBorder - 1]
    if left >= right and !lastMinus
      answer *= left
      leftBorder += 2
    elsif (left < right and lastMinus)
      answer *= left
      leftBorder += 2
    elsif left < right and !lastMinus
      answer *= right
      rightBorder -= 2
    elsif left >= right and lastMinus
      answer *= right
      rightBorder -= 2
    else
      answer *= right
      rightBorder -= 2
    end
    k -= 2
  end
  answer %= Modul
end

puts(answer)
