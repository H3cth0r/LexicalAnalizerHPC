
#ifndef LEX_ANALYZER
#define LEX_ANALYZER


#include <iostream>

// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>


#include <unordered_map>
#include <map>
#include <string>
#include <list>
#include <vector>



std::unordered_map<std::string, std::string> keywords_tokens{
    {"program",     "tk_program"},
    {"int",         "tk_type_int"},
    {"begin",       "tk_begin"},
    {"read",        "tk_read"},
    {"var",         "tk_var"},
    {"float",       "tk_type_float"},
    {"end",         "tk_end"},
    {"write",       "tk_write"},
    {":",           "tk_dos_ptos"},
    {";",           "tk_pto_coma"},
    {"=",           "tk_op_assign"},
    {",",           "tk_coma"},
    {"+",           "tk_op_sum"},
    {"-",           "tk_op_resta"},
    {"*",           "tk_op_mult"},
    {"/",           "tk_op_div"}
};

std::unordered_map<std::string, std::string> color_by_token{
  {"tk_program",        "blue"},  
  {"tk_type_int",       "green"},  
  {"tk_begin",          "blue"},  
  {"tk_read",           "cyan"},  
  {"tk_var",            "blue"},  
  {"tk_type_float",     "gree"},  
  {"tk_end",            "blue"},  
  {"tk_write",          "cyan"},
  {"tk_dos_ptos",       "black"},  
  {"tk_pto_coma",       "black"},  
  {"tk_op_assign",      "yellow"},  
  {"tk_coma",           "black"},  
  {"tk_op_sum",         "yellow"},  
  {"tk_op_resta",       "yellow"},  
  {"tk_op_mult",        "yellow"},  
  {"tk_op_div",         "yellow"},
  {"tk_error",          "red"},  
  {"tk_val_float",      "black"},  
  {"tk_val_int",        "black"},  
  {"tk_id",             "magenta"}  
};

class SymbolInfo{
    private:
    protected:
        std::string     lexeme;
        std::string     tokenKind;
        bool            declared = false;
        int             address;
    public:
        SymbolInfo(std::string t_lexeme, std::string t_tokenKind, bool t_declared, int t_address){
            this->lexeme    =   t_lexeme;
            this->tokenKind =   t_tokenKind;
            this->declared  =   t_declared;
            this->address   =   t_address;
        }

        std::string     get_lexeme(){
            return lexeme;
        };
        std::string     get_tokenKind(){
            return tokenKind;
        };
        bool            get_declared(){
            return declared;
        };
        int             get_address(){
            return address;
        };

        void            set_lexeme(std::string t_lexeme){
            this->lexeme    =   t_lexeme;
        };
        void            set_tokenKind(std::string t_tokenKind){
            this->tokenKind =   t_tokenKind;
        };
        void            set_declared(bool t_declared){
            this->declared  =   t_declared;
        };
        void            set_address(int t_address){
            this->address   =   t_address;
        };

         void print(){
            std::cout << "Lexeme: " << lexeme << "\n";
            std::cout << "Token kind: " << tokenKind << "\n";
            std::cout << "Declared: " << declared << "\n";
            std::cout << "address: " << address << "\n";
        }
};


std::map<std::string, SymbolInfo> SymbolsTable;


class Token{
    private:
    protected:
        // Attributes
        std::string     kind;                   // changing kind to be string
        std::string     lexeme;                 // string lexeme
        int             line, character_index;  // Coordinates
        std::string     color;                  // Color from color toke from U_M
        int             token_size;             // This is the same as "count" in tkinter

    public:
        // Constructor
        Token(){};
        Token(std::string t_kind, std::string t_lexeme, int t_line, int t_character_index, std::string t_color, int t_token_size){
            this->kind              =   t_kind;
            this->lexeme            =   t_lexeme;
            this->line              =   t_line;
            this->character_index   =   t_character_index;
            this->color             =   t_color;
            this->token_size        =   t_token_size;
        }

        // Getters
        std::string     get_kind(){
            return kind;
        }
        std::string     get_lexeme(){
            return lexeme;
        }
        int             get_line(){
            return line;
        }
        int             get_character_index(){
            return character_index;
        }
        std::string     get_index(){      // This method should return the coordinates in tkinter format
            return "line.char";
        }
        std::string     get_color(){
            return color;
        }
        int             get_token_size(){
            return token_size;
        }
        
        void            set_kind(std::string t_kind){
            this->kind              = t_kind;
        }  
        void            set_lexeme(std::string t_lexeme){
            this->lexeme            = t_lexeme;
        }
        void            set_line(int t_line){
            this->line              = t_line;
        }
        void            set_character_index(int t_character_index){
            this->character_index   = t_character_index;
        }
        void            set_color(std::string t_color){
            this->color             = t_color;
        }
        void            set_token_size(int t_token_size){
            this->token_size        = t_token_size;
        }

        void print(){
            std::cout << "kind: " << kind << "\n";
            std::cout << "lexeme: " << lexeme << "\n";
            std::cout << "line: " << line << "\n";
            std::cout << "in line index:" << character_index <<"\n";
            std::cout << "color: " << color << "\n";
            std::cout << "token_size: " << token_size << "\n";
        }
};


class Lexer{
    private:
    protected:
        char character;                     // actual character
        std::string input;                  // The input text/buch O' code
        int line_count = 1;                 // This variable will let us count the line location
        int in_line_count = 0;              // This is the number of characters stored per line

    public:
        std::list<Token> token_list; // This is a list of tokens, that will be returned to python interpreter.

        // Constructor
        Lexer(){}
        Lexer(std::string t_input){
            this->input     =   t_input;
            character = input[0];
        }

        // Getters
        char        get_character(){
            return character;
        }
        std::string get_input(){
            return input;
        }
        
        // Setters
        void    set_character(char t_character){
            this->character = t_character;
        }
        void    set_input(std::string t_input){
            this->input     = t_input;
        }


        bool isDigit(char c){
            return isdigit(c);
        }
        bool isLetter(char c){
            return isalpha(c);
        }
        bool isSeparator(char c){
            return isspace(c);
        }


        void consume(){

            if(character=='\n'){
                in_line_count = 0;
                line_count ++;
                in_line_count = 0;
            }
            else{
                in_line_count ++;
            }

            input.erase(0, 1);
            character = input[0];   

        }

        int calculate_in_line_index(int buff){
            return in_line_count - buff;
        }


        Token tokenId(){

           std::string buff;

           while(isLetter(character) || isDigit(character)){                                    // O(n)
                buff.push_back(character);      // append char to buff variable.
                consume();                      // consume current variable.
           }


            std::string lexeme = buff;


           std::string token_kind;
           if(keywords_tokens.count(lexeme)){
               token_kind = keywords_tokens.at(lexeme);
           } else{
               token_kind = "tk_id";
           }
        

                SymbolInfo symbol_table_row = SymbolInfo(lexeme, token_kind, true, 1);
                SymbolsTable.insert({lexeme, symbol_table_row});


            Token token_id = Token(token_kind, lexeme, line_count, calculate_in_line_index(buff.size()) ,color_by_token.at(token_kind), buff.size());
            
            return token_id;
        }


        Token tokenValIntFloat(){

            std::string buff;
           
            bool decimal_point_ocurrence = false;


            while(isDigit(character) || (character == '.')){
                if(character == '.' ){
                    decimal_point_ocurrence = true;
                }
                buff.push_back(character);
                consume();
            }


            std::string token_kind;
            if(decimal_point_ocurrence == true){
                token_kind = "tk_val_float";
            } else{
                token_kind = "tk_val_int";
            }

            std::string lexeme = buff;
            SymbolInfo symbol_table_row = SymbolInfo(lexeme, token_kind, true, 1);
            SymbolsTable.insert({lexeme, symbol_table_row});


            Token token_id = Token(token_kind, lexeme, line_count, calculate_in_line_index(buff.size()) ,color_by_token.at(token_kind), buff.size());

            return token_id;
        }


        Token nextToken(){

            while(character != '\0'){

                if(isSeparator(character)){
                    consume();
                    continue;
                }


                if(keywords_tokens.count(std::string(1, character))){
                    std::string token_kind = keywords_tokens.at(std::string(1, character));
                    Token token_id = Token(token_kind, std::string(1, character), line_count, calculate_in_line_index(0), color_by_token.at(token_kind), 1);
                    consume();
                    // continue;
                    return token_id;
                }

                if(isLetter(character)) return tokenId();
                if(isDigit(character))  return tokenValIntFloat();
                else{
                    std::string token_kind = "tk_error";
                    return Token(token_kind, std::string(1, character), line_count, calculate_in_line_index(1), color_by_token.at(token_kind), 1);
                }

            }
            

            return Token("tk_EOF", std::string(1, character), line_count, calculate_in_line_index(character), "red", 1);
        }



        std::vector<Token> get_all_tokens(){
            Token token_iterator = Token();
            std::vector<Token> vector_of_tokens;
            while(token_iterator.get_kind() != "tk_EOF"){
                token_iterator = nextToken();
                vector_of_tokens.push_back(token_iterator);
            }
            return vector_of_tokens;
        }


        void print_symbol_table(){
            for(auto i : SymbolsTable){
                i.second.print();
                std::cout << "=====================\n";
            }
        }


        std::vector<SymbolInfo> get_symbol_table(){
            std::vector<SymbolInfo> vector_of_symbols;
            for(auto i : SymbolsTable){
                vector_of_symbols.push_back(i.second);
            }
            return vector_of_symbols;
        }



};


#endif