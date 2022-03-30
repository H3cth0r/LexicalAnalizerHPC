# LexicalAnalizerHPC


<div style="text-align : justify">

## General Description
The intention fo this project is to generate and create a sintax-lexical-analizer for
a generic languje seen on class, called HPC languaje. The main function 
of lexical-analizer is to read the input characters y to produce an output as a
sequence of tokens that then the parser will use for the sintactic analizer.

The lexic-analizer will read a sequence of characters from the source code, until it 
identifies a token, that it is then returned as an answer for the sintactic analizer.

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
</div>