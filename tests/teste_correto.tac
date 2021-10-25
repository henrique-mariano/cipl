.table
.code
main:

jump fn_main_END
fn_main:
// Built-in
// Binary op
mov $0, 1
mov $1, $0
mov $1, $1
// Binary op
mov $0, 2
mov $1, $0
mov $1, $1
mov $0, 2
mov $2, $0
mov $2, $2
mul $0, $1, $2
// End Binary op

mov $2, $0
mov $2, $2
add $0, $1, $2
// End Binary op

mov $0, $0
println $0
// End Built-in

// Built-in
// Binary op
mov $0, 1
mov $1, $0
mov $1, $1
mov $0, 5
mov $2, $0
mov $2, $2
sub $0, $1, $2
// End Binary op

mov $0, $0
println $0
// End Built-in

// Built-in
// Binary op
mov $0, 1.300000
mov $1, $0
mov $1, $1
mov $0, 0.500000
mov $2, $0
mov $2, $2
div $0, $1, $2
// End Binary op

mov $0, $0
println $0
// End Built-in

// Built-in
// Binary op
mov $0, 1.500000
mov $1, $0
mov $1, $1
mov $0, 1.500000
mov $2, $0
mov $2, $2
mul $0, $1, $2
// End Binary op

mov $0, $0
println $0
// End Built-in

// Built-in
// Binary op
// Binary op
// Binary op
// Binary op
mov $0, 2
mov $1, $0
mov $1, $1
mov $0, 5
mov $2, $0
mov $2, $2
mul $0, $1, $2
// End Binary op

mov $1, $0
mov $1, $1
mov $0, 2
mov $2, $0
mov $2, $2
div $0, $1, $2
// End Binary op

mov $1, $0
mov $1, $1
mov $0, 5
mov $2, $0
mov $2, $2
sub $0, $1, $2
// End Binary op

mov $1, $0
mov $1, $1
mov $0, 3
mov $2, $0
mov $2, $2
add $0, $1, $2
// End Binary op

mov $0, $0
println $0
// End Built-in

jump END_OF_PROGRAM
fn_main_END:
jump fn_main
END_OF_PROGRAM:
nop

