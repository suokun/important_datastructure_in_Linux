//include/linux/sched.h

#ifdef CONFIG_SCHEDSTATS
struct sched_statistics {
        u64                     wait_start;
        u64                     wait_max;
        u64                     wait_count;
        u64                     wait_sum;
        u64                     iowait_count;
        u64                     iowait_sum;

        u64                     sleep_start;
        u64                     sleep_max;
        s64                     sum_sleep_runtime;

        u64                     block_start;
        u64                     block_max;
        u64                     exec_max;
        u64                     slice_max;

        u64                     nr_migrations_cold;
        u64                     nr_failed_migrations_affine;
        u64                     nr_failed_migrations_running;
        u64                     nr_failed_migrations_hot;
        u64                     nr_forced_migrations;

        u64                     nr_wakeups;
        u64                     nr_wakeups_sync;
        u64                     nr_wakeups_migrate;
        u64                     nr_wakeups_local;
        u64                     nr_wakeups_remote;
        u64                     nr_wakeups_affine;
        u64                     nr_wakeups_affine_attempts;
        u64                     nr_wakeups_passive;
        u64                     nr_wakeups_idle;
};
#endif        

