def Zadanie1(a)
    if a < 0
        a = a * -1
        print "minus "
        Zadanie1(a)
        return;
    end
    a2 = a
    tablica_jednostek = 
    [
    ["zero", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć", "dziesięć",
     "jedenaście", "dwanaście", "trzynaście", "czternaście", "piętnaście", "szesnaście", "siedemnaście", "osiemnaście", "dziewiętnaście"],
    ["dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt"],
    ["sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"],
    ["tysiąc", "tysiące", "tysięcy"],
    ["milion", "miliony", "milionów"],
    ["miliard", "miliardy", "miliardów"]]
    tablica = []
    licznik = 0
    while a > 0
        tablica[licznik] = a % 10
        a = a / 10
        licznik = licznik + 1
    end
    dlugosc_liczby = tablica.size
    if dlugosc_liczby >= 1 && dlugosc_liczby <= 3
        if dlugosc_liczby == 1 && tablica[0] != 0
            print tablica_jednostek[0][tablica[0]] + " "
        elsif dlugosc_liczby == 2
            if tablica[1] == 1
                print tablica_jednostek[0][tablica[0] + (tablica[1] * 10)] + " "
            elsif tablica[0] != 0
                print tablica_jednostek[1][tablica[1] - 2] + " " + tablica_jednostek[0][tablica[0]] + " "
            else
                print tablica_jednostek[1][tablica[1] - 2] + " "
            end
        elsif dlugosc_liczby == 3
            print tablica_jednostek[2][tablica[2] - 1] + " "
            Zadanie1(a2 % 100)
        end
    elsif dlugosc_liczby >= 4 && dlugosc_liczby <= 6
        if dlugosc_liczby == 4
            if tablica[3] == 1
                print tablica_jednostek[3][0] + " "
            else
                Zadanie1(a2 / 1000)
                if tablica[3] >= 2 &&  tablica[3] <= 4
                    print tablica_jednostek[3][1] + " "
                elsif
                    print tablica_jednostek[3][2] + " "
                end
                Zadanie1(a2 % 1000);
            end
        elsif dlugosc_liczby == 5 || dlugosc_liczby == 6
            Zadanie1(a2 / 1000)
            if tablica[3] >= 2 && tablica[3] <= 4 && tablica[3] + tablica[4] * 10 >= 20
                print tablica_jednostek[3][1] + " "
            else
                print tablica_jednostek[3][2] + " "
            end
            Zadanie1(a2 % 1000)
        end
    elsif dlugosc_liczby >= 7 &&  dlugosc_liczby <= 9
        if dlugosc_liczby <= 7
            if tablica[6] == 1
                print tablica_jednostek[4][0] + " "
            else
                Zadanie1(a2 / 1000000)
                if tablica[6] >= 2 && tablica[6] <= 4
                    print tablica_jednostek[4][1] + " "
                elsif
                    print tablica_jednostek[4][2] + " "
                end
                Zadanie1(a2 % 1000000)
            end
        elsif dlugosc_liczby == 8 || dlugosc_liczby == 9
            Zadanie1(a2 / 1000000)
            if(tablica[6] >= 2 && tablica[6] <= 4 && tablica[6] + tablica[7] * 10 >= 20)
                print tablica_jednostek[4][1] + " "
            else
                print tablica_jednostek[4][2] + " "
            end
            Zadanie1(a2 % 1000000)
        end
    elsif dlugosc_liczby == 10
        if tablica[9] == 1
            print tablica_jednostek[5][0] + " "
        else
            Zadanie1(a2 / 1000000000)
            if tablica[9] >= 2 && tablica[9] <= 4
                print tablica_jednostek[5][1] + " "
            else
                print tablica_jednostek[5][2] + " "
            end
            Zadanie1(a2 % 1000000000)
        end
        Zadanie1(a % 1000000000)
    end
end

print "\nZadanie1\n"
test1 = 2000
test2 = 2222
test3 = 123123123
test4 = -13
test5 = 2123123123
puts "\nTest1: " + test1.to_s
Zadanie1(test1)
puts "\nTest2: " + test2.to_s
Zadanie1(test2)
puts "\nTest3: " + test3.to_s
Zadanie1(test3)
puts "\nTest4: " + test4.to_s
Zadanie1(test4)
puts "\nTest5: " + test5.to_s
Zadanie1(test5)

def Zadanie2(a)
    bigger_numbers = [["XXX", "  X", " XX ", "XXX", "X  ", "XXX", "XXX", "XXX", "XXX", "XXX"],
                      ["X X", " XX", "X  X", "  X", "X  ", "X  ", "X  ", "  X", "X X", "X X"],
                      ["X X", "X X", "  X ", " XX", "XXX", "XXX", "XXX", "  X", "XXX", "XXX"],
                      ["X X", "  X", " X  ", "  X", "  X", "  X", "X X", "  X", "X X", "  X"],
                      ["XXX", "  X", "XXXX", "XXX", "  X", "XXX", "XXX", "  X", "XXX", "XXX"]]
    tab = []
    licznik = 0
    if a == 0
        for i in 0..4
            print bigger_numbers[i][0] + "\n"
        end
    else
        while a > 0
            tab[licznik] = a % 10
            a = a / 10
            licznik = licznik + 1
        end
        tab = tab.reverse
        size = 0
        row = 0
        for i in 0..4
            while size != tab.size
                print bigger_numbers[i][tab[size]] + " "
                size = size + 1
            end
            print "\n"
            size = 0
        end
    end
end

puts "\n\nZadanie2"
test2_1 = 123
test2_2 = 0
test2_3 = 1234567890
test2_4 = 123123123
test2_5 = 42
puts "\nTest1: " + test2_1.to_s + " \n"
Zadanie2(test2_1)
puts "\nTest2: " + test2_2.to_s + " \n"
Zadanie2(test2_2)
puts "\nTest3: " + test2_3.to_s + " \n"
Zadanie2(test2_3)
puts "\nTest4: " + test2_4.to_s + " \n"
Zadanie2(test2_4)
puts "\nTest5: " + test2_5.to_s + " \n"
Zadanie2(test2_5)