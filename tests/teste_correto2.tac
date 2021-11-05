.table
char string0[] = "Digite o valor de i: "
char string1[] = ""
char string2[] = "O seu valor de i é este -> "
char string3[] = "O valor de n é este -> "
.code
main:

// int x
// Var Declare
mema $0, 2
mov *$0, 0
mov $0[1], 1
//End Var Declare

jump fn_list_pass_END
fn_list_pass:
fn_list_pass_END:
jump fn_valid_map_END
fn_valid_map:
fn_valid_map_END:
jump fn_valid_filter_END
fn_valid_filter:
fn_valid_filter_END:
jump fn_main_END
fn_main:
// int i
// Var Declare
mema $5, 2
mov *$5, 0
mov $5[1], 1
//End Var Declare

// float n
// Var Declare
mema $6, 2
mov *$6, 0.000000
mov $6[1], 2
//End Var Declare

// Built-in
// String
mov $7, &string0
push $7
// End String

pop $7
write_STRING_0:
mov $8, 0
write_STRING_0_LOOP:
mov $9, '\0'
mov $10, $7[$8]
seq $9, $9, $10
brnz write_ENDING_0, $9
print $10
add $8, $8, 1
jump write_STRING_0_LOOP
write_ENDING_0:
// End Built-in

// Built-in
push $5
pop $7
mov $7, *$7
scani $7
mov *$5, $7
// End Built-in

// Built-in
// String
mov $7, &string1
push $7
// End String

pop $7
write_STRING_1:
mov $8, 0
write_STRING_1_LOOP:
mov $9, '\0'
mov $10, $7[$8]
seq $9, $9, $10
brnz write_ENDING_1, $9
print $10
add $8, $8, 1
jump write_STRING_1_LOOP
write_ENDING_1:
println 
// End Built-in

// Built-in
// String
mov $7, &string2
push $7
// End String

pop $7
write_STRING_2:
mov $8, 0
write_STRING_2_LOOP:
mov $9, '\0'
mov $10, $7[$8]
seq $9, $9, $10
brnz write_ENDING_2, $9
print $10
add $8, $8, 1
jump write_STRING_2_LOOP
write_ENDING_2:
// End Built-in

// Built-in
push $5
pop $7
mov $7, *$7
println $7
// End Built-in

// Assign
// Var Declare
mema $7, 2
mov *$7, 0.000000
mov $7[1], 2
//End Var Declare

mov *$7, 5.500000
push $7
pop $7
mov *$6, *$7
// End Assign

// Built-in
// String
mov $7, &string3
push $7
// End String

pop $7
write_STRING_3:
mov $8, 0
write_STRING_3_LOOP:
mov $9, '\0'
mov $10, $7[$8]
seq $9, $9, $10
brnz write_ENDING_3, $9
print $10
add $8, $8, 1
jump write_STRING_3_LOOP
write_ENDING_3:
// End Built-in

// Built-in
push $6
pop $7
mov $7, *$7
println $7
// End Built-in

jump END_OF_PROGRAM
fn_main_END:
jump fn_main
END_OF_PROGRAM:
nop

