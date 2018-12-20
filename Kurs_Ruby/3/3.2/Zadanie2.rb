#Zadanie 2 Lista 3 Piotr Bolek

def pierwsza (n)
    tab = [2]
    size = 1;
    flag = true
    for i in 3..n-1
        for j in 0..size - 1
            if(i % tab[j] == 0)
                flag = false
            end
        end
        if(flag)
            tab.push(i)
            size += 1
        end
        flag = true
    end
    return tab
end

def doskonale (n)
    doskonale = []
    sum = 0
    size = 0
    for i in 1..n
        for j in 1..i-1
            if(i % j == 0)
                sum += j
            end
        end
        if(sum == i)
            doskonale.push(i)
        end
        sum = 0
    end
    return doskonale
end

puts "Liczby pierwsze mniejsze od 100:"
print pierwsza(100)
print "\n"
puts "Liczby doskonale mniejsze od 1000:"
print doskonale(10000)