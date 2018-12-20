
class BinaryTree
    private
        def help
            if @right == nil && @left != nil
                return @left.help
            elsif @right != nil && @left == nil
                return @right
            elsif @right == nil && @left == nil
                return self
            else
                return @right.help
            end 
        end
    protected
        def left
        end
        def right
        end
        def value
        end
    public
        def initialize(value)
            @value = value
        end
        def value
            @value
        end
        def left
            @left
        end
        def right
            @right
        end
        def insert(element)
            if element < @value
                if @left == nil
                    @left = BinaryTree.new(element)
                else
                    @left.insert(element)
                end
            else
                if @right == nil
                    @right = BinaryTree.new(element)
                else
                    @right.insert(element)
                end
            end
        end
        def exist?(element)
            if element != @value && @right == nil && @left == nil
                return false
            elsif element == @value || element == @right.value || element == @left.value
                return true
            else
                if element > @value
                    @right.exist?
                else
                    @left.exist?
                end
            end
        end
=begin
        def remove(element)
            if(exist?(element))
                if element == @value
                    if @right == nil && @left == nil
                        return nil
                    elsif @right == nil && @left != nil
                        new_tree = BinaryTree.new(@left.value)
                        new_tree.insert(@left.left)
                        return new_tree
                    elsif @right != nil && @left == nil
                        new_tree = BinaryTree.new(@right.value)
                        new_tree.insert(@right.right)
                        return new_tree
                    elsif @right != nil && @left != nil
                        return self.help
                    end
                else
                    if element < @value
                        @left.remove(element)
                    else
                        @right.remove(element)
                    end
                end
            end
        end
=end
        def to_s
            if @right == nil && @left == nil
                return @value.to_s
            elsif @right != nil && @left == nil
                return @value.to_s + " " + @right.to_s
            elsif @right == nil && @left != nil
                return @left.to_s + " " + @value.to_s
            else
                return @left.to_s + " " + @value.to_s + " " + @right.to_s
            end
        end
end

class StringBT < BinaryTree
end

stringbt = StringBT.new("abba")
stringbt.insert("aa")
stringbt.insert("bb")
stringbt.insert("cc")
stringbt.insert("a")

bt = BinaryTree.new(10)
bt.insert(2)
bt.insert(3)
bt.insert(12)
bt.insert(15)
puts stringbt.to_s
bt = bt.remove(2)
puts bt.to_s