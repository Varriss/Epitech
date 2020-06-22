.name "Corruptor"
.comment "C0rRuPt0R!"

    ld %:after,r4
    ld %7, r10
    sti r1, %:live1, %1
    fork %:corrupt

live1:
    live %123
    ld %0, r3
    fork %:live1
    ld %0, r3
    zjmp %:live1

    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123
    live %123

corrupt:
    add r4, r10, r4
    sti r10, r4, %1
    ld %0, r3
    zjmp %:corrupt

after:
