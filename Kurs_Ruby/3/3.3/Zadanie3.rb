#Zadanie 3 Lista 3 Piotr Bolek

def is_prime(n)
    for i in 2..n-1
        if n % i == 0
            return false
        end
    end
    return true
end

def rozklad(n)
    res = []
    i = 2
    count = 0 
    while (n > 1 || i == n)
        if is_prime(n)
            res.push([n, 1])
            n = 1
        end
        while n % i == 0
            count += 1
            n = n / i
        end
        if count == 0
            i += 1
        else
            res.push([i, count])
        end
        count = 0
    end
    return res
end

def suma_dzielnikow(n)
    sum = 0
    for i in 1..n - 1
        if n % i == 0
            sum += i
        end
    end
    return sum
end

def zaprzyjaznione(n)
    zaprzyjaznione = []
    size = 0
    flag = true
    for i in 1..n - 1
        for j in 1..n - 1
            if (i != j && (suma_dzielnikow(i) == j && suma_dzielnikow(j) == i))
                for k in 0..size
                    if zaprzyjaznione[k] == [i, j] || zaprzyjaznione[k] == [j, i]
                        flag = false
                    end
                end
                if flag
                    zaprzyjaznione.push([i, j])
                    size += 1
                end
            end
            flag = true
        end
    end
    return zaprzyjaznione
end

puts "Rozklad na czynniki pierwsze dla 756:"
print rozklad(756), "\n"
puts "Liczby zaprzyjaznione mniejsze od 1300:"
print zaprzyjaznione(1300)