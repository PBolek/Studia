# Piotr Bolek Lista 8 Zadanie 1

class Fixnum
    def initialize(number)
        @numer = number
    end

    def czynniki
        output = []
        1.upto(Math.sqrt(self)) do |x|
            next unless (self % x).zero?
            output.push(x)
            candidate = self / x
            output.push(candidate) unless candidate == x
        end
        output
    end

    def ack(y)
        if zero?
            y + 1
        elsif y.zero?
            (self - 1).ack(1)
        elsif
            argument = ack(y - 1)
            (self - 1).ack(argument)
        end
    end

    def doskonala
        dzielniki = []
        2.upto(Math.sqrt(self)) do |x|
            next unless (self % x).zero?
            dzielniki.push(x)
            candidate = self / x
            dzielniki.push(candidate) unless candidate == x
        end
        sum = 1
        dzielniki.each{ |n| sum += n }  
        sum == self
    end

    def slownie
        slownik = { 1 => 'jeden',
        2 => 'dwa',
        3 => 'trzy',
        4 => 'cztery',
        5 => 'pięć',
        6 => 'sześć',
        7 => 'siedem',
        8 => 'osiem',
        9 => 'dziewięć',
        0 => 'zero' }
        output = ''
        input = to_s.chars.map(&:to_i)
        input.each { |n| output += slownik[n] += ' ' }
        output
    end

end

g = 10
puts "Slownie:"
puts g.slownie
puts "Doskonala:"
puts g.doskonala
puts "Czynniki:"
puts g.czynniki
k = 2
puts "Ackermann(od (2,1)):"
puts k.ack(1)
