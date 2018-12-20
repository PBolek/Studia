require_relative "Zadanie2"
require 'yaml'

reader = '-'
list = []
#i = 0
if !File.open("Rozmiar_bazy.txt").eof?
    puts (File.open("Rozmiar_bazy.txt"){|f| f.readline}).chomp.to_i
    number_of_cds_in_db = (File.open("Rozmiar_bazy.txt"){|f| f.readline}).chomp.to_i
else
    number_of_cds_in_db = 0
end
if number_of_cds_in_db != 0
    for i in 0..number_of_cds_in_db - 1
        list.push(open("Baza.txt", 'r'){|f| YAML.load(f)})
    end
end

def print_menu
    puts "1 - Dodaj CD do bazy danych"
    puts "2 - Wyszukaj CD w bazie danych"
    puts "3 - Wypisz wszystkie CD w bazie danych"
    puts "4 - Usun CD z bazy danych"
    puts "0 - Zakoncz dzialanie programu"
end

def print_menu2
    puts "Po czym chcesz wyszukac?"
    puts "1 - id"
    puts "2 - lista utworow"
    puts "3 - autorze"
    puts "4 - czy zostala pozyczona?"
    puts "5 - kiedy zostala pozyczona"
end

while(reader.chomp != "0")
    print_menu
    reader = gets
    if reader.chomp == "1"
        puts "Podaj kolejno: id, liste utworow, autora, czy jest pozyczona (false/true), kiedy zostala pozyczona (YYYY/MM/DD)"
        reader = gets.chomp
        id = reader.to_i
        track_list = gets.chomp
        author = gets.chomp
        reader = gets.chomp
        if reader == "true"
            is_borrowed = true
        else
            is_borrowed = false
        end
        reader = gets.chomp
        help = ''
        for i in 0..3
            help = help + reader[i]
        end
        year = help.to_i
        month = ('' + reader[5] + reader[6]).to_i
        day = ('' + reader[8] + reader[9]).to_i
        cd = CD.new(id, track_list, author, is_borrowed, Time.new(year, month, day));
        helper = YAML.dump(cd)
        cos = YAML.load(helper)
        list.push(cos)
        number_of_cds_in_db = number_of_cds_in_db + 1
        list.compact!
    elsif reader.chomp == "2"
        print_menu2
        reader = gets.chomp
        if reader == "1"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i].get_id.to_s == reader && list[i] != nil
                    puts list[i].to_yaml
                end 
            end
        elsif reader == "2"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i].get_track_list == reader
                    puts list[i].to_yaml
                end
            end
        elsif reader == "3"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i].get_author == reader
                    puts list[i].to_yaml
                end
            end
        elsif reader == "4"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i].get_is_borrowed.to_s == reader
                    puts list[i].to_yaml
                end
            end
        elsif reader == "5"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i].get_when_borrowed.to_s == reader
                    puts list[i].to_yaml
                end 
            end
        end
    elsif reader.chomp == "3"
        for i in 0..number_of_cds_in_db - 1
            puts list[i].to_yaml
        end
    elsif reader.chomp == "4"
        print_menu2
        reader = gets.chomp
        if number_of_cds_in_db == 0
            break
        end
        if reader == "1"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i] != nil
                    if list[i].get_id.to_s == reader
                        list.delete_at(i)
                        number_of_cds_in_db = number_of_cds_in_db - 1
                    end
                end
            end
            list.compact!
        elsif reader == "2"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i] != nil
                    if list[i].get_track_list == reader
                        list.delete_at(i)
                        number_of_cds_in_db = number_of_cds_in_db - 1
                    end
                end
            end
            list.compact!
        elsif reader == "3"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i] != nil
                    if list[i].get_author == reader
                        list.delete_at(i)
                        number_of_cds_in_db = number_of_cds_in_db - 1
                    end
                end
            end
            list.compact!
        elsif reader == "4"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i] != nil
                    if list[i].get_is_borrowed.to_s == reader
                        list.delete_at(i)
                        number_of_cds_in_db = number_of_cds_in_db - 1
                    end
                end  
            end
            list.compact!
        elsif reader == "5"
            reader = gets.chomp
            for i in 0..number_of_cds_in_db - 1
                if list[i] != nil
                    if list[i].get_when_borrowed.to_s == reader
                        list.delete_at(i)
                        number_of_cds_in_db = number_of_cds_in_db - 1
                    end
                end
            end
            list.compact!
        end
    elsif reader.chomp == "0"
        File.open('Baza.txt', 'w') {|file| file.truncate(0) }
        File.open('Rozmiar_bazy.txt', 'w') {|file| file.truncate(0)}
        File.open('Rozmiar_bazy.txt', 'w') {|f| f.write(number_of_cds_in_db.to_s)}
        for i in 0..number_of_cds_in_db - 1
            open("Baza.txt", 'w'){|f| YAML.dump(list[i], f)}
        end
    end
end