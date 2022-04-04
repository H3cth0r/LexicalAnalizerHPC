#include "LexicalAnalyzer.h"


int main(){

    // Token my_token = Token("instruction", "int", 10, 3, "blue", 3);
    // my_token.print();

    // Lexer my_lexer = Lexer();
    // std::cout << "is letter?: " << my_lexer.isLetter('s');
    // std::cout << "is digit?: "  << my_lexer.isDigit('1');
    // return 0;



    /*
    TODO
    1. fix line number token data
    */

    std::string txt_input = "program programaejemplo\nvar\n\tperro, gato : int;\nbegin\n\tperro = 2 + 2;\n\tread gato;\n\twrite 2.2 + 3;\nend";
    Lexer my_lexer = Lexer(txt_input);
    Token token_ptr = Token();
    // Token my_token = my_lexer.nextToken();
    // Token my_token_two = my_lexer.nextToken();
    // my_token.print();
    // std::cout << "=====================\n";
    // my_token_two.print();

    // for(int i = 0; i < 26; i++){
    //     token_ptr = my_lexer.nextToken();
    //     token_ptr.print();
    //     std::cout << "====================\n";
    // }

    std::vector<Token> my_vector_of_tokens = my_lexer.get_all_tokens();
    for(int i = 0; i <= my_vector_of_tokens.size(); i++){
        my_vector_of_tokens[i].print();
        std::cout << "====================\n";
    }
    my_lexer.print_symbol_table();

    // std::vector<SymbolInfo> my_vector_of_symbols = my_lexer.get_symbol_table();
    // for(int i = 0; i <= my_vector_of_symbols.size(); i++){
    //     my_vector_of_symbols[i].print();
    //     std::cout << "=========================\n";
    // }
    // std::cout << "yes" << std::endl;


    return 0;

};