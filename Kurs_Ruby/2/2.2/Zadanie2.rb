#zadanie 2 Lista 2 Piotr Bolek

imiona = []
numery = []
tablica_list_grup = []
c = -1

def print_menu
    puts "1 - Dodawanie osoby wraz z numerem telefonu i lista grup"
    puts "2 - Wyszukiwanie po imieniu"
    puts "3 - Znalezienie wszystkich grup"
    puts "4 - Wyszukanie wszystkich osob nalezacych do danej grupy"
    puts "0 - Zakoncz dzialanie programu"
end

def znajdz_po_imieniu(imie)
    i = 0
    while imiona[i] != nil
        if imiona[i] == imie
            print "Imie/nick: ", imiona[i], "\n"
            print "Numer telefonu: ", numery[i], "\n"
            print "Lista grup: ", tablica_list_grup[i], "\n"
            return
        end
    end
    puts "Nie ma osoby o podanym imieniu/nicku w rejestrze"
end

def dodawanie(imie, telefon, lista_grup)
    imiona.push(imie)
    numery.push(telefon)
    tablica_list_grup.push(lista_grup)
end

def znajdz_wszystkie_grupy()
    grupy = []
    for i in 0..tablica_list_grup.length
        for j in 0..tablica_list_grup[i].length
            for k in 0..grupy.length
                if tablica_list_grup[i][j] == grupy[k]
                    flag = false
                end
            end
            if flag
                grupy.push(tablica_list_grup[i][j])
            end
        end
    end
    return grupy
end

def znajdz_wszystkie_osoby_w_grupie(nazwa_grupy)
    osoby = []
    for i in 0..tablica_list_grup.length
        for j in 0..tablica_list_grup[i].length
            if tablica_list_grup[i][j] == nazwa_grupy
                osoby.push(imiona[i])
            end
        end
    end
    return osoby
end

while c != 0
    print_menu()
    
end
