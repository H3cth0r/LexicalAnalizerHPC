"""
Importing TkInter
TkInter    is   a   binding   lib   from   tlc/tk.
It  is  an  standard  for developing python GUI's.
It is installed on windows.
"""
from logging import root
from tkinter import *
from collections import deque
"""
Importing Lexical Analyzer lib
"""
import sys
sys.path.append("C:/Users/Gar-m/Desktop/l'ecole/implementacion_metodos_computacionales/LexicalAnalizerHPC")
import build.hpcLexAnalyzer as hpcLA
"""
Main class that will enable us to generate a window.
"""
class TheMainWindow:
    """
    The TheMainWindow class constructor
    """
    def __init__(self, t_root):
        self.root = t_root                                  # Here we input the TKinter root constructor
        self.root.option_add("*Font", "Verdana 12")         # Declaring font 

        """
        Creating Main window frame
        """
        self.main_window = Frame(self.root)                 # Input Tkinter main constructor into Frame
        """
        Attributes used by stackify method
        """
        self.stack = deque(maxlen = 0)
        self.stackcursor = 0
        """
        Window/Frame label
        """
        self.label_one = Label(self.main_window, text= "HPC Lexical Analyzer")  # set label/title to window
        self.label_one.pack(padx = 5, pady = 5)
        """
        Creating txt input frame 
        """
        self.text_one = Text(self.main_window, width=90, height=25)            # creating text input box
        self.text_one.pack(padx=5, pady=5)
        """
        Buttons to be used
        """
        self.button_two = Button(self.main_window, text = "Clear", width = 8, command = self.clear)
        self.button_two.pack(padx = 5, pady = 5, side = LEFT)

        self.main_window.pack(padx = 5, pady = 5)
        """
        Creating space to print tokens on GUI
        """
        self.tokens_print_space = Text(self.main_window, width=30, height=8)
        self.tokens_print_space.pack(padx=5, pady=5, side=RIGHT) 
        self.tokens_print_space.config(state = "disabled")
        """
        Creating space to print symbol table
        """ 
        self.symbol_table_print = Text(self.main_window, width=40, height=8)
        self.symbol_table_print.pack(padx=5, pady=5, side=RIGHT)
        self.symbol_table_print.config(state='disabled')

    """
    create highlight
    """
    def generate_tag(self, t_token_kind, t_line, t_character_start, t_length, t_color):
        tag_name = t_token_kind + str(t_line) + str(t_length)
        coordinate_start    = str(t_line) + "." + str(t_character_start)
        coordinate_end      = str(t_line) + "." + str(int(t_character_start) + t_length)
        # tag_name, coordinate_start, coordinate_end
        self.text_one.tag_add(tag_name, coordinate_start, coordinate_end)
        # tag_name, foreground  = t_color
        self.text_one.tag_config(tag_name, foreground=t_color)
    
    """
    Highlighter Method
    """
    def highlighter(self):
        start   = "1.0"
        end     = "end"
        """
        Get the whole txt from the IDE
        """
        txt_input = self.text_one.get("1.0", "end")             # Getting the whole txt on GUI
        """
        Analyze input txt
        """
        my_lex = hpcLA.Lexer(txt_input) 
        my_list_of_tokens = my_lex.get_all_tokens()
        """
        Create Tags
        """
        tokens_string = ""
        txt_symbol_table = ""
        for i in my_list_of_tokens:
            self.generate_tag(i.get_kind(), 
                              i.get_line(),
                              i.get_character_index(),
                              i.get_token_size(),
                              i.get_color())
            tokens_string += '<' + i.get_kind() + '>'
            txt_symbol_table += "> " + i.get_lexene() + " : " + i.get_kind() +  " : " + " declared " + " : " + str(i.get_line()) + "." + str(i.get_character_index()) + " \n"

        """
        Input tokens into tokens square
        """ 
        self.tokens_print_space.config(state = "normal")
        self.tokens_print_space.delete("1.0", "end")
        self.tokens_print_space.insert("1.0", tokens_string)
        self.tokens_print_space.config(state = "disabled")
        """
        Print the symbol table
        """
        # my_symbol_table = my_lex.get_symbol_table()
        # txt_symbol_table = ""
        # for j in my_symbol_table:
        #     txt_symbol_table += ">> " + j.get_lexeme() + " : " + j.get_tokenKind() +  " : " + str(j.get_address()) + "\n"
        self.symbol_table_print.config(state = "normal")
        self.symbol_table_print.delete("1.0", "end")
        self.symbol_table_print.insert("1.0", txt_symbol_table)
        self.symbol_table_print.config(state = "disabled")

    """
    Update
    """
    def updater(self):
        self.stackify()
        self.highlighter()
    
    """
    Clear
    """
    def clear(self):
        self.text_one.delete("1.0", "end")

        self.tokens_print_space.config(state="normal")
        self.tokens_print_space.delete("1.0", "end")
        self.tokens_print_space.config(state="disabled")

        self.symbol_table_print.config(state="normal")
        self.symbol_table_print.delete("1.0", "end")
        self.symbol_table_print.config(state="disabled")
    
    """
    stackify
    """
    def stackify(self):
        self.stack.append(self.text_one.get("1.0", "end - 1c"))
        if self.stackcursor < 9:
            self.stackcursor += 1
    

root = Tk()
the_window = TheMainWindow(root)
root.bind("<Key>", lambda event: the_window.updater())
root.mainloop()