.table
.code
main:

jump fn_arith_END
fn_arith:
fn_arith_END:
jump fn_main_END
fn_main:
// Built-in
// Binary op
mov $1, 1
mov $2, $1
mov $2, $2
// Binary op
mov $1, 2
mov $2, $1
mov $2, $2
mov $1, 2
mov $3, $1
mov $3, $3
mul $1, $2, $3
// End Binary op

mov $3, $1
mov $3, $3
add $1, $2, $3
// End Binary op

mov $1, $1
println $1
// End Built-in

// Built-in
// Binary op
mov $1, 1
mov $2, $1
mov $2, $2
mov $1, 5
mov $3, $1
mov $3, $3
sub $1, $2, $3
// End Binary op

mov $1, $1
println $1
// End Built-in

// Built-in
// Binary op
mov $1, 1.300000
mov $2, $1
mov $2, $2
mov $1, 0.500000
mov $3, $1
mov $3, $3
div $1, $2, $3
// End Binary op

mov $1, $1
println $1
// End Built-in

// Built-in
// Binary op
mov $1, 1.500000
mov $2, $1
mov $2, $2
mov $1, 1.500000
mov $3, $1
mov $3, $3
mul $1, $2, $3
// End Binary op

mov $1, $1
println $1
// End Built-in

jump END_OF_PROGRAM
fn_main_END:
jump fn_main
END_OF_PROGRAM:
nop

