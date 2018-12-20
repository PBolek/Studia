
class Meeting
    public
        def initialize(time_of_meeting)
            @time_of_meeting = time_of_meeting
        end
        def get_time_of_meeting
            return @time_of_meeting
        end
        def time_to_meeting
            years = @time_of_meeting.year - Time.now().year
            months = @time_of_meeting.month - Time.now().month
            days = @time_of_meeting.day - Time.now().day
            hours = @time_of_meeting.hour - Time.now().hour
            minutes = @time_of_meeting.min - Time.now().min
            seconds = @time_of_meeting.sec - Time.now().sec
            return years.to_s + "/" + months.to_s + "/" + days.to_s + "/" + hours.to_s + "/" + minutes.to_s + "/" + seconds.to_s
        end
    protected
        def time_of_meeting
        end
    private
end

cos = Meeting.new(Time.new(2018, 11, 23, 12, 00, 00))
puts cos.time_to_meeting