require 'yaml'

class CD
    private
        def id
        end

        def track_list
        end

        def author
        end

        def is_borrowed
        end

        def when_borrowed
        end

        def is_borrowed_for_too_long
        end
    public
        def initialize(id, track_list, author, is_borrowed, when_borrowed)
            @id = id
            @track_list = track_list
            @author = author
            @is_borrowed = is_borrowed
            if is_borrowed == false
                @when_borrowed = nil
                @is_borrowed_for_too_long = false
            else
                @when_borrowed = when_borrowed
                if @when_borrowed.year < Time.now().year
                    @is_borrowed_for_too_long = true
                elsif @when_borrowed.year == Time.now() && @when_borrowed.month < Time.now().month
                    @is_borrowed_for_too_long = true
                else
                    @is_borrowed_for_too_long = false
                end
            end
        end

        def get_id
            return @id
        end

        def get_track_list
            return @track_list
        end

        def get_author
            return @author
        end

        def get_is_borrowed
            return @is_borrowed
        end
        
        def get_when_borrowed
            return @when_borrowed
        end

        def set_is_borrowed(is_borrowed)
            @is_borrowed = is_borrowed
            if @is_borrowed
                @when_borrowed = Time.localtime
            else
                @when_borrowed = nil
            end
        end

        def get_is_borrowed_for_too_long
            return @is_borrowed_for_too_long
        end
end