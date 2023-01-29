# LexicalAnalizerHPC


<div style="text-align : justify">

## General Description
The intention fo this project is to generate and create a sintax-lexical-analizer for
a generic languje seen on class, called HPC languaje. The main function 
of lexical-analizer is to read the input characters y to produce an output as a
sequence of tokens that then the parser will use for the sintactic analizer.

The lexic-analizer will read a sequence of characters from the source code, until it 
identifies a token, that it is then returned as an answer for the sintactic analizer.

It is important to mention that on this case we'll be applying a manual implementation.

For this project will be creating some c++ extensions for creating the lexical-analizer and python for creating the GUI using a crossplatform python library called tkinter.

## Build Requirements
- Cmake (3.23)
- Python (3.9)
- CPP compiler


## Build tutorial for Cmake and pybind11 project
https://linuxtut.com/en/01d425c06f990e34870d/

## Video Running our Solution
https://user-images.githubusercontent.com/43997408/161891896-9a63740d-712b-48b9-abfd-00c12483e938.mp4

## Solution Document
If you would want to know more about our solution, please access the following [link](https://docs.google.com/document/d/1eHZ1_Sn-o0oPoRSZCUcQvl2j4jsT1BdwGNdYepmEdjA/edit?usp=sharing) <br> <br>


## Collateral Methods
- Delete comments.
- Conserve the line numbers for then asociate them to an error in case it happens.

## Concepts
- Token : lexic unit, in which a group of lexemes that match the same pattern. Tokens
are input symbols for the sintactic-analizer.
- Pattern : rule that describes a group of strings for the ones that produce a same output token.
- Lexeme : sequence of characters fromt he source-code that match a corresponding pattern of a token.

## Token attributes
Generaly presented as follows: <br>
<p style="text-align: center; "><b><.name, reference></b></p>

- <b>Name</b>: represents the tokeb name (tk_id, tk_number ...).
- <b>Reference</b>: entry ereference on the "symbol table" corresponding to the token.
<br>
For each token it is necesary to almacenate on the "symbol-table" information like the Lexeme, line-number on its first appearence and other data values that depend of the token type.

## Steps
1. Identify the collection of tokens that compose the languaje. Comes united to the representation process of the languaje by a generative gramatics.
2. Especify each token by an escheme to generate and recognize(usually a reglular expression).
3. Especify a transition diagram of the lexic analizer.

## HPC program general structure
```
program <program name>
var
    <variables declaration>
begin
    <instructions>
end
```

## Example Code
program programaEjemplo
var
    perro, gato:int;
    a, b, c: float;
begin
    perro = 2 + 2;
    read gato;
    write 2.2 + perro;
    read b;
    write a * b;
end
    

- **variable declaration** 
```
<lista de variables> : <tipo de datos>;
```
The identifiers on the list are separated by a comma. The data allowed data types are *float* and *int*.
- **instructions asignations**
```
identifier = <arithmetic_expression>
```
It only allows addition(+), substraction(-), product(*) and division(/), and other variable and constants, integer and real.
- **input/output instructions**
```
read identifier;
write <arithmetic expression>
```

<br>
There are different *reserved words*, all of them with a different and important sintactic
meaning. None of them can be used as an identifier of some variables. Each asignation is composed of an idenfier, an asignation operator, an arithmetic expression and ";".
The arithmetic expression can be constituted by identifiers, integer constants and arithmetic operators(+, -, *, /).


The sintactic elements of an input-instruction are the *read* keyword and an identifier.

The sintactic elements of an output-instruction are the *write* keyword and a arithmetic expression.

## Token Names
- **tk_val_float**
- **tk_op_sum**
- **tk_op_resta**
- **tk_op_mul**
- **tk_op_div**
- **tk_op_asig**
- **tk_coma**
- **tk_dos_ptos**
- **tk_pto_comma**
<br>

## General HPC languaje grammar
![HPC grammar](https://github.com/H3cth0r/LexicalAnalizerHPC/blob/main/resources/grammar_img_01.png?raw=true)
<br>
![HPC grammar](https://github.com/H3cth0r/LexicalAnalizerHPC/blob/main/resources/grammar_img_02.png?raw=truehttps://github.com/H3cth0r/LexicalAnalizerHPC/blob/main/resources/grammar_img_02.pnghttp://url/to/img.png)


- **tk_program** = program
- **tk_type_int** = int
- **tk_begin** = begin
- **tk_read** = read
- **tk_dos_ptos** = ":"
- **tl_op_asig** = "="
- **tk_id** = ( letra | "_" ) . ( letra | "_" | digit ) *
- **tk_val_int** = digit . digit*
- **letter** = A | B | ... | Z | a | b | ... | z
- **digit** = 0 | 1 | ... | 9
- **tk_val_float** = tk_val_int.tk_val_int
- **tk_var** = var
- **tk_type_float** = float
- **tk_end** = end
- **tk_write** = write
- **tk_comma** = ","
- **tk_pto_comma** = ";"
- **tk_op_arit** = + | - | * | /
  

</div>
