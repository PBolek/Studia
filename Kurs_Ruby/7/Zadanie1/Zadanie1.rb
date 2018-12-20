require "drb"

class LogSerwer
    def save(prg_id, msg)
        File.open("Baza_Danych.txt", 'w'){|f| f << (Time.now.to_s + " " + prg_id.to_s + " " + msg)}
    end

    def to_html
        html = '<html><body>'
        ObjectSpace.each_object(Object) do |o|
            if o.respond_to?('to_html')
                html += o.to_html
            else
                html += '<div>' + o.to_s + '</div>'
            end
        end
    end

    def raport(from, to, prg_id, re)
        i = 0
        time = ''
        prg = ''
        msg = ''
        File.open("Baza_Danych.txt", 'r') do |f|
            f.each_line do |line|
                while(line[i] != ' ')
                    time[i] = line[i]
                    i += 1
                end
                i += 1
                while(line[i] != ' ')
                    prg[i] = line[i]
                    i += 1
                end
                i += 1
                while(line[i] != ' ')
                    msg[i] = line[i]
                    i += 1
                end
                if(time >= from && time <= to)
                    if(prg == prg_id.to_s)
                        if(msg == re.to_s)
                            html = ('' + time + ' ' + prg + ' ' + msg).to_html
                            File.open("Raport.html", 'w'){ |g| g << html}
                        end
                    end
                end
                i = 0
            end
        end
    end

    def LogSerwer.Run
        @@server = LogSerwer.new
        DRb.start_service('druby://localhost:9000', @@server)
        DRb.thread.join
    end
end

LogSerwer.Run
obj = DRbObject.new_with_uri('druby://localhost:9000')
if obj.respond_to?('save')
    obj.save("1", "aaa")
end
