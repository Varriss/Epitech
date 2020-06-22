    .name "Abel"
    .comment "L'amer noir."

live %20

ld %50, r2
ld 84, r2

st r8, 855
st r8, r10

add r5,r6,r7
sub r5,r6,r7

and r1,r2,r3
and %20,r2,r3
and 854,r2,r3
and r1,%84,r3
and %20,%84,r3
and 854,%84,r3
and r1,81,r3
and %20,81,r3
and 854,81,r3

or r1,r2,r3
or %20,r2,r3
or 854,r2,r3
or r1,%84,r3
or %20,%84,r3
or 854,%84,r3
or r1,81,r3
or %20,81,r3
or 854,81,r3

xor r1,r2,r3
xor %20,r2,r3
xor 854,r2,r3
xor r1,%84,r3
xor %20,%84,r3
xor 854,%84,r3
xor r1,81,r3
xor %20,81,r3
xor 854,81,r3

zjmp %854

ldi r5,r6,r7
ldi %20,r6,r7
ldi 45,r6,r7
ldi r5,%80,r7
ldi %20,%80,r7
ldi 45,%80,r7

sti r2,r3,r4
sti r2,%20,r4
sti r2,20,r4
sti r2,r3,%80
sti r2,%20,%80
sti r2,20,%80

lld %50,r2
lld 82,r2

lldi r1,r2,r3
lldi %20,r2,r3
lldi 52,r2,r3
lldi r1,%942,r3
lldi %20,%942,r3
lldi 52,%942,r3

fork %854
lfork %854

aff r2