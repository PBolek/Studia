# Piotr Bolek Lista 8 Zadanie 3

class Jawna
    def initialize(text)
        @text = text
    end

    def zaszyfruj(klucz)
        output = ''
        counter = 0
        while counter < @text.length
            output[counter] = klucz[@text[counter]]
            counter += 1
        end

        final = Zaszyfrowane.new(output)
    end

    def to_s()
        @text
    end
end

class Zaszyfrowane
    def initialize(text)
        @text = text
    end

    def odszyfruj(klucz)
        output = ''
        counter = 0
        while counter < @text.length
            output[counter] = klucz[@text[counter]]
            counter += 1
        end
        final = Jawna.new(output)
    end

    def to_s()
        @text
    end
end

klucz = {
    'a' => 'b',
    'b' => 'c',
    'c' => 'd',
    'd' => 'e',
    'e' => 'f',
    'g' => 'h',
    'h' => 'i',
    'i' => 'j',
    'j' => 'k',
    'k' => 'l',
    'l' => 'm',
    'm' => 'n',
    'o' => 'p',
    'p' => 'r',
    'r' => 's',
    's' => 't',
    't' => 'u',
    'u' => 'v',
    'v' => 'w',
    'w' => 'x',
    'x' => 'y',
    'y' => 'z',
    'z' => 'a'
}

klucz2 = {
    's' => 'r',
    'v' => 'u',
    'c' => 'b',
    'z' => 'y'
}

g = Jawna.new("ruby")
puts "Przed szyfrowaniem:"
puts g
h = g.zaszyfruj(klucz)
puts "Zaszyfrowane:"
puts h.to_s
g = h.odszyfruj(klucz2)
puts "Odszyfrowane:"
puts g.to_s