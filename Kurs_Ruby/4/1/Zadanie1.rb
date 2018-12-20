class Expression
    protected
        def value
        end
    public
        def get_value
            return @value
        end
        def to_s
            return @value.to_s
        end
end

class Number < Expression
    public
        def initialize(value)
            @value = value
        end
end

class Constant < Expression
    protected
        def name
        end
    public
        def initialize(name, value)
            @name = name
            @value = value
        end
        def to_s
            return "(" + @name + " = " + @value.to_s + ")"
        end
end

class Variable < Expression
    protected
        def name
        end
    public
        def initialize(name, value)
            @name = name
            @value = value
        end
        def to_s
            return "(" + @name + " = " + @value.to_s + ")"
        end
end

class Operator1 < Expression
    protected
        def left
        end
        def initialize(left)
            @left = left
        end
end

class Operator2 < Operator1
    protected
        def right
        end
        def initialize(left, right)
            @left = left
            @right = right
        end
end

class Add < Operator2
    public
        def get_value
            return @left.get_value + @right.get_value
        end
        def to_s
            return "(" + @left.to_s + " + " + @right.to_s + ")"
        end
        def simplification
            if @left.get_value == 0
                return Number.new(@right)
            elsif @right.get_value == 0
                return Number.new(@left)
            elsif @left.get_value == 0 && @right.get_value == 0
                return Number.new(0)
            end
            return self
        end
end

class Sub < Operator2
    public
        def get_value
            return @left.get_value - @right.get_value
        end
        def to_s
            return "(" + @left.to_s + " - " + @right.to_s + ")"
        end
        def simplification
            if @left.get_value == 0
                return Number.new(@right)
            elsif @right.get_value == 0
                return Number.new(@left)
            elsif @left.get_value == 0 && @right.get_value == 0
                return Number.new(0)
            end
            return self
        end
end

class Mult < Operator2
    public
        def get_value
            return @left.get_value * @right.get_value
        end
        def to_s
            return "(" + @left.to_s + " * " + @right.to_s + ")"
        end
        def simplification
            if @left.get_value == 1
                return Number.new(@right)
            elsif @right.get_value == 1
                return Number.new(@left)
            elsif @left.get_value == 0 || @right.get_value == 0
                return Number(0)
            end
            return to_s
        end
end

class Div < Operator2
    public
        def get_value
            if @right.get_value == 0
                return "You can't devide by 0!"
            end
            return @left.get_value / @right.get_value
        end
        def to_s
            return "(" + @left.to_s + " / " + @right.to_s + ")"
        end
        def simplification
            if @left.get_value == 0
                return Number.new(0)
            elsif @right.get_value == 1
                return Number.new(@left)
            elsif @left.get_value == @right.get_value
                return Number.new(1)
            end
            return to_s
        end
end

x = Add.new(Mult.new(Number.new(10), Div.new(Number.new(10), Constant.new("x", 10))), Sub.new(Number.new(10), Variable.new("z", 5)))
puts x.to_s
puts x.get_value