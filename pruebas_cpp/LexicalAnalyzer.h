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


/*
    Enum of all the present token kind on the languaje to define.
    Here is and example of how to acces some defined value  into
    the enum object:

            enum Color { Red };
            Color c = Color::Red;
            Color d = Red;

*/
// enum class TokenKind{
//     tk_program,
//     tk_var,
//     tk_type_int,
//     tk_begin,
//     tk_end,
//     tk_type_float,
//     tk_id,
//     tk_write,
//     tk_read,
//     tk_val_int,
//     tk_val_float,
//     tk_coma,
//     tk_dos_ptos,
//     tk_pto_coma,
//     tk_op_sum,
//     tk_op_mult,
//     tk_op_resta,
//     tk_op_div,
//     tk_op_assign,
//     tk_error, 
//     tk_EOF
// };


/*
    Here we create an unordered map, so we lower the time complexity,
    and so we can find easily the reserved-keywords or operators.
        key(string) = lexeme
        value(string) = token
    std::string(1, character)
*/
std::unordered_map<std::string, std::string> keywords_tokens{
    // reserved keywords
    {"program",     "tk_program"},
    {"int",         "tk_type_int"},
    {"begin",       "tk_begin"},
    {"read",        "tk_read"},
    {"var",         "tk_var"},
    {"float",       "tk_type_float"},
    {"end",         "tk_end"},
    {"write",       "tk_write"},
    // single_character tokens
    {":",           "tk_dos_ptos"},
    {";",           "tk_pto_coma"},
    {"=",           "tk_op_assign"},
    {",",           "tk_coma"},
    {"+",           "tk_op_sum"},
    {"-",           "tk_op_resta"},
    {"*",           "tk_op_mult"},
    {"/",           "tk_op_div"},
    
    // Colors
    // reserver keywords
    {"tk_program",        "blue"},  
    {"tk_type_int",       "green"},  
    {"tk_begin",          "blue"},  
    {"tk_read",           "cyan"},  
    {"tk_var",            "blue"},  
    {"tk_type_float",     "gree"},  
    {"tk_end",            "blue"},  
    {"tk_write",          "cyan"},
    // single character tokens  
    {"tk_dos_ptos",       "black"},  
    {"tk_pto_coma",       "black"},  
    {"tk_op_assign",      "yellow"},  
    {"tk_coma",           "black"},  
    {"tk_op_sum",         "yellow"},  
    {"tk_op_resta",       "yellow"},  
    {"tk_op_mult",        "yellow"},  
    {"tk_op_div",         "yellow"},
    // additional tokens  
    {"tk_error",          "red"},  
    {"tk_val_float",      "black"},  
    {"tk_val_int",        "black"},  
    {"tk_id",             "magenta"} 
};
/*
    Missing tokens:
        - tk_EOF
        - to_error
        - tk_val_float
        - tk_val_int
        - tk_id
    This one's will be bet depending on automata.
*/

/*
    Here we create a new unordered map, for setting the text color,
    dependding on token kind. This will be also be returned to python.
        std::string key = token
        std::string value = color
    types                   : green
    structure_program_words : blue
    id's                    : magenta
    instructions            :  cyan
    error                   : red
    operators               : yellow
    values                  : black

    tkinter can recive hex colors or the following list in string:
        - white
        - black
        - red
        - green
        - blue
        - cyan
        - yellow
        - magenta
*/
// std::unordered_map<std::string, std::string> color_by_token{
//   // reserver keywords
//   {"tk_program",        "blue"},  
//   {"tk_type_int",       "green"},  
//   {"tk_begin",          "blue"},  
//   {"tk_read",           "cyan"},  
//   {"tk_var",            "blue"},  
//   {"tk_type_float",     "gree"},  
//   {"tk_end",            "blue"},  
//   {"tk_write",          "cyan"},
//   // single character tokens  
//   {"tk_dos_ptos",       "black"},  
//   {"tk_pto_coma",       "black"},  
//   {"tk_op_assign",      "yellow"},  
//   {"tk_coma",           "black"},  
//   {"tk_op_sum",         "yellow"},  
//   {"tk_op_resta",       "yellow"},  
//   {"tk_op_mult",        "yellow"},  
//   {"tk_op_div",         "yellow"},
//   // additional tokens  
//   {"tk_error",          "red"},  
//   {"tk_val_float",      "black"},  
//   {"tk_val_int",        "black"},  
//   {"tk_id",             "magenta"}  
// };
/*
    EOF not considered here
*/


/*
    This is the value object that will be inputted into the SymbolTable hashmap.

*/
class SymbolInfo{
    private:
    protected:
        // attributes
        std::string     lexeme;
        std::string     tokenKind;
        bool            declared = false;
        int             address;
        // memotypes
    public:
        // Constructor
        SymbolInfo(std::string t_lexeme, std::string t_tokenKind, bool t_declared, int t_address){
            this->lexeme    =   t_lexeme;
            this->tokenKind =   t_tokenKind;
            this->declared  =   t_declared;
            this->address   =   t_address;
        }

        // Getters
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

        // Setters
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

        // Functionality methods
         void print(){
            std::cout << "Lexeme: " << lexeme << "\n";
            std::cout << "Token kind: " << tokenKind << "\n";
            std::cout << "Declared: " << declared << "\n";
            std::cout << "address: " << address << "\n";
        }
};


/*
    In the case of our project, for lowering the time complexity, we decided the
    symbol table to be a hashmap. The key and value goes as follows:
        Key     : lexema(string)
        value   : SymbolInfor(class)
    This way we will just need to search for the key, if it doesnt exist on the
    table, we can add or check the values.
*/
std::map<std::string, SymbolInfo> SymbolsTable;




/*
    This is the class that represents a single token, with its info.
    This class contains the following attributes and methods.

    Atributes:
        - strin kind
        - string lexeme
        - int line
        - int entry              <<<<<<<< because our symbol table is a hashmap, our "entry" variable is the lexeme(which is the hashmap key)
        - string color
    Methods:
        - 
        - tag_coordinates() : string  ''

    
    Consider that the coordinates tkinter format goes as follows:
            "line.char" in string type

    TODO:  consider here to make the methods public, so user can easily acces the
    values on python
*/
class Token{
    private:
    protected:
        // Attributes
        std::string     kind;                   // changing kind to be string
        std::string     lexeme;                 // string lexeme
        int             line, character_index;  // Coordinates
        std::string     color;                  // Color from color toke from U_M
        int             token_size;             // This is the same as "count" in tkinter
        std::string     index;

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
        // TODO : complemete functionality here.
        std::string     get_index(){      // This method should return the coordinates in tkinter format
            // return coordinates
            return "line.char";
        }
        std::string     get_color(){
            return color;
        }
        int             get_token_size(){
            return token_size;
        }
        
        // Setters
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
        void            set_index(std::string t_index){
            this->index             = t_index;
        }
        void            set_color(std::string t_color){
            this->color             = t_color;
        }
        void            set_token_size(int t_token_size){
            this->token_size        = t_token_size;
        }

        // printers
        void print(){
            std::cout << "kind: " << kind << "\n";
            std::cout << "lexeme: " << lexeme << "\n";
            std::cout << "line: " << line << "\n";
            std::cout << "in line index:" << character_index <<"\n";
            std::cout << "color: " << color << "\n";
            std::cout << "token_size: " << token_size << "\n";
        }
        // Functionality Methods
};




/*
    The lexer class will be the one that gives more functionlity to
    the present mdoule. Here the lexer should recive the string txt
    or bucnh of HPC code to analyse.
*/
class Lexer{
    private:
    protected:
        char character;                     // actual character
        std::string input;                  // The input text/buch O' code
        int line_count = 1;                 // This variable will let us count the line location
        int in_line_count = 0;              // This is the number of characters stored per line
        // SYMBOL TABLE check if we should create the hashtable every time we initialize the Lexer.
        // ERROR REPORTE dont know if i should create and erro reporte class or what should i do.
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

        // is ... boolean checkers
        // TODO set functionality or checkers to the character checkers.
        bool isDigit(char c){
            return isdigit(c);
        }
        bool isLetter(char c){
            return isalpha(c);
        }
        bool isSeparator(char c){
            return isspace(c);
        }





        /*
        It will save the first char of the string to character variable.
        Consume method will delete the first character of the input text.
        */
        void consume(){
            /*
            if separator is a new line:
                set in_line_count to 0
                line_count ++
            */
            if(character=='\n'){
                in_line_count = 0;
                line_count ++;
                in_line_count = 0;
            }
            else{
                in_line_count ++;
            }
            /*
            Delete firts character.    
            string.erase(first character position, number characters to delete)
            */
            input.erase(0, 1);
            character = input[0];   

        }

        /*
        Method that will calculate the coordinate of some token, depending on the
        character count by each line and the. 
        */
        int calculate_in_line_index(int buff){
            return in_line_count - buff;
        }


        /*
        This method is supposed to treat tokens that start with a letter or
        ID valid character. This method is used in the nextToken method.
        */
        Token tokenId(){
            /*
            Define string variable that will work as a buffer, for appending
            id_valid characters to it and at the ebd checking what kind of
            token it is.
            */
           std::string buff;


            /*
            While loop to check wether the current character is a letter or
            a digit. Into the while loop, it will append the current
            character to the string buffer variable.
            */
           while(isLetter(character) || isDigit(character)){                                    // O(n)
                buff.push_back(character);      // append char to buff variable.
                consume();                      // consume current variable.
           }

            /*
            The loop will break when it detects a separator or another type
            of character.
            Then it should set the lexeme to be the buffer value
                buffer = lexeme
            */
            std::string lexeme = buff;

            /*
            Get the token kind depending on the lexeme.
            If statement to check if value is found on the reserves.
            Define variable that stores the token kind.
            */
           std::string token_kind;
           if(keywords_tokens.count(lexeme)){
               token_kind = keywords_tokens.at(lexeme);
           } else{
               token_kind = "tk_id";
           }
        
            /*
            Add the entry to the symbol table
                st.insert({string lexeme, SymbolInfo})
                SymbolInfo(std::string t_lexeme, std::string t_tokenKind, bool t_declared, int t_address)

                address parameterr may be the number of character on row

                TODO : check if what the address parameter is for.
                Entry parameter is the table_id
            */
                SymbolInfo symbol_table_row = SymbolInfo(lexeme, token_kind, true, 1);
                SymbolsTable.insert({lexeme, symbol_table_row});

            /*
            create and return Token.
            TODO : check if it should be added to a list.
            Token(std::string t_kind, std::string t_lexeme, int t_line, int t_character_index, std::string t_color, int t_token_size){
            */
            Token token_id = Token(token_kind, lexeme, line_count, calculate_in_line_index(buff.size()) , keywords_tokens.at(token_kind), buff.size());
            
            return token_id;
        }


        /*
            This method treats tokens that start with a digit. will decide if either is a
            int or float token value.
        */
        Token tokenValIntFloat(){
            /*
            Define string variable that works as buffer to contain an integer or float value.
            */
            std::string buff;
           
            /*
            Define boolean variable to mark in case there was a decimal point ocurrence.
            */
            bool decimal_point_ocurrence = false;


            /*
            While loop to check if current character is an digit or a ".".
            In case there is an ocurrence of ".", then mark the previous
            variable with a true.

            Set an if "if" for in case the point occyrrence is true or false.
            If it is true, then break the while loop. 

            The character is appended to the buffer string variable.
            */
            while(isDigit(character) || (character == '.')){
                if(character == '.' ){
                    decimal_point_ocurrence = true;
                }
                buff.push_back(character);
                consume();
            }

            /*
            if decimal point ocurrence is true, then create float_val_token 
            */
            /*
            if last if condition was false, return as default token as int_val_token
            */
            std::string token_kind;
            if(decimal_point_ocurrence == true){
                token_kind = "tk_val_float";
            } else{
                token_kind = "tk_val_int";
            }

            /*
            Add entry to symbol table.
            */
            std::string lexeme = buff;
            SymbolInfo symbol_table_row = SymbolInfo(lexeme, token_kind, true, 1);
            SymbolsTable.insert({lexeme, symbol_table_row});

            /*
            Create Token
            Token(std::string t_kind, std::string t_lexeme, int t_line, int t_character_index, std::string t_color, int t_token_size){
            */
            Token token_id = Token(token_kind, lexeme, line_count, calculate_in_line_index(buff.size()) , keywords_tokens.at(token_kind), buff.size());

            return token_id;
        }






        /*
            This is the main method where the input will be analyzed in search
            of the tokens.

            TODO : this method it is supposed to return an EOD token when the
            program ends. So try changing the the method return type.
        */
        Token nextToken(){
            /*
            While the present token is not the EOF or \0 cotinue reading the
            input.
            */
            while(character != '\0'){
                /*
                In case of character being a separator, skip to next iteration.
                */
                if(isSeparator(character)){
                    consume();
                    continue;
                }

                /*
                Check if the single & simple character exists on the reserver_kerwords
                unodered_map. if exists create token.
                Token(std::string t_kind, std::string t_lexeme, int t_line, int t_character_index, std::string t_color, int t_token_size){
                */
                if(keywords_tokens.count(std::string(1, character))){
                    std::string token_kind = keywords_tokens.at(std::string(1, character));
                    Token token_id = Token(token_kind, std::string(1, character), line_count, calculate_in_line_index(0), keywords_tokens.at(token_kind), 1);
                    consume();
                    // continue;
                    return token_id;
                }

                /*
                Here we check the first character of new token, depending on its type,
                it will redirect us to some other method.

                Check if current character is a letter. -> run method for tokenID
                Check if current character is a digit.  -> run method for tokenValDigit
                if is another kind of character return and error.
                Token(std::string t_kind, std::string t_lexeme, int t_line, int t_character_index, std::string t_color, int t_token_size){
                */
                if(isLetter(character)) return tokenId();
                if(isDigit(character))  return tokenValIntFloat();
                else{
                    std::string token_kind = "tk_error";
                    return Token(token_kind, std::string(1, character), line_count, calculate_in_line_index(1), keywords_tokens.at(token_kind), 1);
                }

            }
            
            /*
            In case the the while loop end, do something.
            */
            return Token("tk_EOF", std::string(1, character), line_count, calculate_in_line_index(character), "red", 1);
        }


        /*
            This method returns a vector of all the tokens on the txt input.
        */
        std::vector<Token> get_all_tokens(){
            Token token_iterator = Token();
            std::vector<Token> vector_of_tokens;
            while(token_iterator.get_kind() != "tk_EOF"){
                token_iterator = nextToken();
                vector_of_tokens.push_back(token_iterator);
            }
            return vector_of_tokens;
        }

        /*
            This method prints the whole SymbolTable.
        */
        void print_symbol_table(){
            for(auto i : SymbolsTable){
                i.second.print();
                std::cout << "=====================\n";
            }
        }

        /*
        This method returns a vector of all SymbolInfo object.
        */
        std::vector<SymbolInfo> get_symbol_table(){
            std::vector<SymbolInfo> vector_of_symbols;
            for(auto i : SymbolsTable){
                vector_of_symbols.push_back(i.second);
            }
            return vector_of_symbols;
        }



};


#endif