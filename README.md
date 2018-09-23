# Morphology Reduction in BNF Format
Analyze and simplify the morphology of a language in BNF format.

# Sample Input
```
G = <{Z, U, C, a, b, c}, {a, b, c}, {Z = U | a, U = a | b | C, C = aCb | bCa}, {Z}>
```

# Design
Add `CTree` and `Grammar` class to simplify coding steps.


# Functions
Delete useless (dead-loop, nonreachable) branches in grammar tree.

* Input `G = <{Z, U, C, a, b, c}, {a, b, c}, {Z = U | a, U = a | b | C, C = aCb | bCa}, {Z}>`
```
Target Content in BNF Format:
G = <{Z, U, C, a, b, c}, {a, b, c}, {Z = U | a, U = a | b | C, C = aCb | bCa}, {Z}>

---- Starting Analysis ----
7 Rules, Started with Z: 
C := aCb
C := bCa
U := a
U := b
U := C
Z := U
Z := a

---- Grammar Tree for G ----

Original Grammar Tree: 
Z 1
|- U 0
|- |- U 1
|- |- |- a 0
|- |- |- |- a 1
|- |- |- b 0
|- |- |- |- b 1
|- |- |- C 0
|- |- |- |- C 1
|- |- |- |- |- aCb 0
|- |- |- |- |- |- a 1
|- |- |- |- |- |- C 1
|- |- |- |- |- |- |- bCa 0
|- |- |- |- |- |- |- |- b 1
|- |- |- |- |- |- |- |- C 1
|- |- |- |- |- |- |- |- a 1
|- |- |- |- |- |- b 1
|- |- |- |- |- bCa 0
|- |- |- |- |- |- b 1
|- |- |- |- |- |- C 1
|- |- |- |- |- |- a 1
|- a 0
|- |- a 1

---- Working on the Tree ----
>> Cut bCa Branch
>> Cut bCa Branch
>> Cut aCb Branch
>> Cut C Branch

After Cleaning Grammar Tree: 
Z 1
|- U 0
|- |- U 1
|- |- |- a 0
|- |- |- |- a 1
|- |- |- b 0
|- |- |- |- b 1
|- a 0
|- |- a 1
```
