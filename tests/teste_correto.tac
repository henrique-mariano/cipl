.table
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

// Built-in
push $0
pop $2
mov $2, *$2
scanf $2
mov *$0, $2
// End Built-in

// Assign
// Var Declare
mema $2, 2
mov *$2, 0
mov $2[1], 1
//End Var Declare

mov *$2, 2
push $2
pop $2
mov *$1, *$2
// End Assign

// Built-in
// Binary op
push $0
// Binary op
push $1
push $1
pop $3
mov $5, *$3
pop $2
mov $4, *$2
mul $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0
mov $6[1], 1
//End Var Declare

mov *$6, $5
push $6
// End Binary op

pop $3
mov $5, *$3
inttofl $5, $5
pop $2
mov $4, *$2
add $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0.000000
mov $6[1], 2
//End Var Declare

mov *$6, $5
push $6
// End Binary op

pop $2
mov $2, *$2
println $2
// End Built-in

// Built-in
// Binary op
push $0
// Var Declare
mema $2, 2
mov *$2, 0
mov $2[1], 1
//End Var Declare

mov *$2, 5
push $2
pop $3
mov $5, *$3
inttofl $5, $5
pop $2
mov $4, *$2
sub $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0.000000
mov $6[1], 2
//End Var Declare

mov *$6, $5
push $6
// End Binary op

pop $2
mov $2, *$2
println $2
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $2, 2
mov *$2, 0
mov $2[1], 1
//End Var Declare

mov *$2, 1
push $2
// Var Declare
mema $2, 2
mov *$2, 0.000000
mov $2[1], 2
//End Var Declare

mov *$2, 2.300000
push $2
pop $3
mov $5, *$3
pop $2
mov $4, *$2
inttofl $4, $4
add $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0.000000
mov $6[1], 2
//End Var Declare

mov *$6, $5
push $6
// End Binary op

pop $2
mov $2, *$2
println $2
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $2, 2
mov *$2, 0.000000
mov $2[1], 2
//End Var Declare

mov *$2, 1.300000
push $2
// Var Declare
mema $2, 2
mov *$2, 0.000000
mov $2[1], 2
//End Var Declare

mov *$2, 0.500000
push $2
pop $3
mov $5, *$3
pop $2
mov $4, *$2
div $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0.000000
mov $6[1], 2
//End Var Declare

mov *$6, $5
push $6
// End Binary op

pop $2
mov $2, *$2
println $2
// End Built-in

// Built-in
// Binary op
// Var Declare
mema $2, 2
mov *$2, 0.000000
mov $2[1], 2
//End Var Declare

mov *$2, 1.500000
push $2
// Var Declare
mema $2, 2
mov *$2, 0.000000
mov $2[1], 2
//End Var Declare

mov *$2, 1.500000
push $2
pop $3
mov $5, *$3
pop $2
mov $4, *$2
mul $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0.000000
mov $6[1], 2
//End Var Declare

mov *$6, $5
push $6
// End Binary op

pop $2
mov $2, *$2
println $2
// End Built-in

// Built-in
// Binary op
// Binary op
// Binary op
// Binary op
push $1
// Var Declare
mema $2, 2
mov *$2, 0
mov $2[1], 1
//End Var Declare

mov *$2, 5
push $2
pop $3
mov $5, *$3
pop $2
mov $4, *$2
mul $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0
mov $6[1], 1
//End Var Declare

mov *$6, $5
push $6
// End Binary op

push $1
pop $3
mov $5, *$3
pop $2
mov $4, *$2
div $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0
mov $6[1], 1
//End Var Declare

mov *$6, $5
push $6
// End Binary op

// Var Declare
mema $2, 2
mov *$2, 0
mov $2[1], 1
//End Var Declare

mov *$2, 5
push $2
pop $3
mov $5, *$3
pop $2
mov $4, *$2
sub $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0
mov $6[1], 1
//End Var Declare

mov *$6, $5
push $6
// End Binary op

// Var Declare
mema $2, 2
mov *$2, 0
mov $2[1], 1
//End Var Declare

mov *$2, 3
push $2
pop $3
mov $5, *$3
pop $2
mov $4, *$2
add $5, $4, $5
// Var Declare
mema $6, 2
mov *$6, 0
mov $6[1], 1
//End Var Declare

mov *$6, $5
push $6
// End Binary op

pop $2
mov $2, *$2
println $2
// End Built-in

jump END_OF_PROGRAM
fn_main_END:
jump fn_main
END_OF_PROGRAM:
nop

