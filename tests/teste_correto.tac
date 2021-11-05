.table
char string0[] = "Escreva o valor de c: "
char string1[] = "O valor de c eh: "
char string2[] = ""
.code
main:

jump fn_main_END
fn_main:
// float a
// Var Declare
mema $0, 2
mov *$0, 0.000000
mov $0[1], 2
//End Var Declare

// int b
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

// int c
// Var Declare
mema $2, 2
mov *$2, 0
mov $2[1], 1
//End Var Declare

// Assign
// Var Declare
mema $3, 2
mov *$3, 0.000000
mov $3[1], 2
//End Var Declare

mov *$3, 1.000000
push $3
pop $3
mov *$0, *$3
// End Assign

// Assign
// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 2
push $3
pop $3
mov *$1, *$3
// End Assign

// Built-in
// String
mov $3, &string0
push $3
// End String

pop $3
write_STRING_0:
mov $4, 0
write_STRING_0_LOOP:
mov $5, '\0'
mov $6, $3[$4]
seq $5, $5, $6
brnz write_ENDING_0, $5
print $6
add $4, $4, 1
jump write_STRING_0_LOOP
write_ENDING_0:
// End Built-in

// Built-in
push $2
pop $3
mov $3, *$3
scani $3
mov *$2, $3
// End Built-in

// Built-in
// Binary op
// Unary Op
// Binary op
// Unary Op
// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 5
push $3
pop $4
push $4
// End Unary Op

// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 2
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
sub $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $4
mov $3, *$4
minus $3, $3
// Var Declare
mema $5, 2
mov *$5, 0
mov $5[1], 1
//End Var Declare

mov *$5, $3
push $5
// End Unary Op

// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 2
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
mul $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// Binary op
// Unary Op
// Binary op
// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 1
push $3
// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 2
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
add $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $4
mov $3, *$4
minus $3, $3
// Var Declare
mema $5, 2
mov *$5, 0
mov $5[1], 1
//End Var Declare

mov *$5, $3
push $5
// End Unary Op

// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 5
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
add $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// Binary op
push $0
// Binary op
push $1
push $1
pop $4
mov $6, *$4
pop $3
mov $5, *$3
mul $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $4
mov $6, *$4
inttofl $6, $6
pop $3
mov $5, *$3
add $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0.000000
mov $7[1], 2
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// Binary op
push $0
// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 5
push $3
pop $4
mov $6, *$4
inttofl $6, $6
pop $3
mov $5, *$3
sub $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0.000000
mov $7[1], 2
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 1
push $3
// Var Declare
mema $3, 2
mov *$3, 0.000000
mov $3[1], 2
//End Var Declare

mov *$3, 2.300000
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
inttofl $5, $5
add $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0.000000
mov $7[1], 2
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $3, 2
mov *$3, 0.000000
mov $3[1], 2
//End Var Declare

mov *$3, 1.300000
push $3
// Var Declare
mema $3, 2
mov *$3, 0.000000
mov $3[1], 2
//End Var Declare

mov *$3, 0.500000
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
div $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0.000000
mov $7[1], 2
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $3, 2
mov *$3, 0.000000
mov $3[1], 2
//End Var Declare

mov *$3, 1.500000
push $3
// Var Declare
mema $3, 2
mov *$3, 0.000000
mov $3[1], 2
//End Var Declare

mov *$3, 1.500000
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
mul $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0.000000
mov $7[1], 2
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// Binary op
// Binary op
// Binary op
// Binary op
push $1
// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 5
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
mul $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

push $1
pop $4
mov $6, *$4
pop $3
mov $5, *$3
div $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 5
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
sub $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

// Var Declare
mema $3, 2
mov *$3, 0
mov $3[1], 1
//End Var Declare

mov *$3, 3
push $3
pop $4
mov $6, *$4
pop $3
mov $5, *$3
add $6, $5, $6
// Var Declare
mema $7, 2
mov *$7, 0
mov $7[1], 1
//End Var Declare

mov *$7, $6
push $7
// End Binary op

pop $3
mov $3, *$3
println $3
// End Built-in

// Built-in
// String
mov $3, &string1
push $3
// End String

pop $3
write_STRING_1:
mov $4, 0
write_STRING_1_LOOP:
mov $5, '\0'
mov $6, $3[$4]
seq $5, $5, $6
brnz write_ENDING_1, $5
print $6
add $4, $4, 1
jump write_STRING_1_LOOP
write_ENDING_1:
// End Built-in

// Built-in
push $2
pop $3
mov $3, *$3
print $3
// End Built-in

// Built-in
// String
mov $3, &string2
push $3
// End String

pop $3
write_STRING_2:
mov $4, 0
write_STRING_2_LOOP:
mov $5, '\0'
mov $6, $3[$4]
seq $5, $5, $6
brnz write_ENDING_2, $5
print $6
add $4, $4, 1
jump write_STRING_2_LOOP
write_ENDING_2:
println 
// End Built-in

jump END_OF_PROGRAM
fn_main_END:
jump fn_main
END_OF_PROGRAM:
nop

