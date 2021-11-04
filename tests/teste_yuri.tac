.table
char string0[] = "computed: "
char string1[] = "answer:   01011100010100111001011011010100"
.code
main:

jump fn_main_END
fn_main:
// Built-in
// String
mov $0, &string0
push $0
// End String

pop $0
write_STRING_0:
mov $1, 0
write_STRING_0_LOOP:
mov $2, '\0'
mov $3, $0[$1]
seq $2, $2, $3
brnz write_ENDING_0, $2
print $3
add $1, $1, 1
jump write_STRING_0_LOOP
write_ENDING_0:
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $4, $3, $2
seq $5, $2, $3
not $5, $5
and $0, $4, $5
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
not $0, $0
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $4, $3, $2
seq $5, $2, $3
not $5, $5
and $0, $4, $5
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
not $0, $0
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $4, $3, $2
seq $5, $2, $3
not $5, $5
and $0, $4, $5
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
not $0, $0
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $4, $3, $2
seq $5, $2, $3
not $5, $5
and $0, $4, $5
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
not $0, $0
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
slt $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
sleq $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $3
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
not $0, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $3
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
not $0, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $3
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
not $0, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $3
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
seq $3, $2, $3
not $0, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
and $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
or $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
and $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
or $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
and $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 1
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
or $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
and $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
print $0
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

mov *$0, 0
push $0
pop $1
mov $3, *$1
pop $0
mov $2, *$0
or $0, $2, $3
// Var Declare
mema $1, 2
mov *$1, 0
mov $1[1], 1
//End Var Declare

mov *$1, $0
push $1
// End Binary op

pop $0
mov $0, *$0
println $0
// End Built-in

// Built-in
// String
mov $0, &string1
push $0
// End String

pop $0
write_STRING_1:
mov $1, 0
write_STRING_1_LOOP:
mov $2, '\0'
mov $3, $0[$1]
seq $2, $2, $3
brnz write_ENDING_1, $2
print $3
add $1, $1, 1
jump write_STRING_1_LOOP
write_ENDING_1:
println 
// End Built-in

jump END_OF_PROGRAM
fn_main_END:
jump fn_main
END_OF_PROGRAM:
nop

