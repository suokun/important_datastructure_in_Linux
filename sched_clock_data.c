// in kernel/sched_clock.c 

struct sched_clock_data {
        u64                     tick_raw;
        u64                     tick_gtod;
        u64                     clock;
};


