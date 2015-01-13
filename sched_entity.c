# include/linux/sched.h


struct sched_entity {
        struct load_weight      load;           /* for load-balancing */
        struct rb_node          run_node;
        struct list_head        group_node;
        unsigned int            on_rq;

        u64                     exec_start;
        u64                     sum_exec_runtime;
        u64                     vruntime;
        u64                     prev_sum_exec_runtime;

        u64                     nr_migrations;

#ifdef CONFIG_SCHEDSTATS
        struct sched_statistics statistics;
#endif

#ifdef CONFIG_FAIR_GROUP_SCHED
        struct sched_entity     *parent;
        /* rq on which this entity is (to be) queued: */
        struct cfs_rq           *cfs_rq;
        /* rq "owned" by this entity/group: */
        struct cfs_rq           *my_q;
#endif

#ifdef CONFIG_SMP
        /* Per-entity load-tracking */
        struct sched_avg        avg;
#endif
};
