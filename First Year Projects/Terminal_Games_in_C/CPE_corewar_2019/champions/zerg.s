        .name "zerg"
        .comment "EZ"

        sti r1, %:alive, %1

alive:  live %234
        fork %:alive
        ld %0, r3
        zjmp %:alive
