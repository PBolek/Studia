require 'tk'

class Window
    def run
        @win = TkRoot.new { title 'Interface' }
        @entry = TkEntry.new(@win) { pack }
        @butt = TkButton.new(@win) { text 'Calculate'; pack}
        @butt.command = proc { self.oblicz; }
        @label = TkLabel.new(@win) {text '0'; pack }
        TkButton.new(@win) { 
            text 'EXIT';
            command {exit};
            pack; }
    end

    def Calculate
        @label.text = eval(@entry.value)
        @entry.value = ''
    end
end

Window.run
Tk.mainloop