from tokenize import Token
from build.hpcLexAnalyzer import SymbolInfo, Lexer


# my_input = "program programaejemplo\nvar\n\tperro, gato : int;\nbegin\n\tperro = 2 + 2;\n\tread gato;\n\twrite 2.2 + 3;\nend"
my_input = """program ProgramaEjemplo
var
    perro, gato : int;
begin
    perro = 2 + 2;
    read gato;
    write 2.2 + 3;
end"""

my_lexer = Lexer(my_input)

# next_token = my_lexer.nextToken()
# next_token.print()
# print("=====================")
# next_token = my_lexer.nextToken()
# next_token.print()

list_of_tokens = []
def print_list_of_tokesn():
    list_of_tokens = my_lexer.get_all_tokens()
    for i in list_of_tokens:
        print(i.get_kind())

print_list_of_tokesn()



# Creating symbol info oject, which is a "row"
# row = SymbolInfo("perro", "tk_id", True, 1)
# row.print()



# Appending to SymbolsTable map the created row
# print(append_st_map("perro", row))