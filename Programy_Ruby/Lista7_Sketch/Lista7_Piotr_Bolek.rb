def palindrome?(name)
    s = name.downcase.tr('^a-z^', '')
    ss = s.reverse
    s == ss
end

def count_words(name)
    hash = Hash.new
    hash.default = 0
    help_name = name.downcase.tr('^a-z^', ' ').split(' ')
    for e in help_name
        hash[e] = hash[e] + 1
    end
    return hash
end

def same23?(name)
    for e in nameN
        if e != "a" and e != "b" and e != "c"
            return false
        end
    end
    if name.length != 5
        return false
    end

    hash = Hash.new(0)
    for e in name
        hash[e] = hash[e] + 1
    end
    l3 = 0
    l2 = 0
    tab = []
    tab = hash.values
    for i in 0...tab.length
        if tab[i] == 3
            l3 = l3 + 1
        elsif tab[i] == 2
            l2 = l2 + 1
        end
    end
    l3 == 1 and l2 == 1
end

# Testy
p "Palindrome?"
puts palindrome?("A man, a plan, a canal -- Panama") == true
puts palindrome?("Madam, I'm Adam!") == true
puts palindrome?("Abracadabra") == false
puts palindrome?("") == true
p "count_words"
p count_words("A man, a plan, a canal -- Panama") == {'a'=>3, 'man'=>1, 'canal'=>1, 'panama'=>1, 'plan'=>1}
p count_words("Madam, I'm Adam!") == {"madam"=>1, "i"=>1, "m"=>1, "adam"=>1}
p count_words("Abracadabra") == {"abracadabra"=>1}
p count_words("") == {}
p "same23?"
p same23?(["a", "a", "a", "b", "b"]) == true
p same23?(["a", "b", "c", "b", "c"]) == false
p same23?(["a", "a", "a", "a", "a"]) == false
p same23?(["a", "b", "b", "a", "a", "d"]) == false
    
