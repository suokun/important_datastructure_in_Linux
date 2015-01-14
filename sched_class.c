//kernel/sched/sched.h



#define ENQUEUE_WAKEUP          1
#define ENQUEUE_HEAD            2
#ifdef CONFIG_SMP
#define ENQUEUE_WAKING          4       /* sched_class::task_waking was called */
#else
#define ENQUEUE_WAKING          0
#endif
#define ENQUEUE_REPLENISH       8

#define DEQUEUE_SLEEP           1

struct sched_class {
        const struct sched_class *next;

        void (*enqueue_task) (struct rq *rq, struct task_struct *p, int flags);
        void (*dequeue_task) (struct rq *rq, struct task_struct *p, int flags);
        void (*yield_task) (struct rq *rq);
        bool (*yield_to_task) (struct rq *rq, struct task_struct *p, bool preempt);

        void (*check_preempt_curr) (struct rq *rq, struct task_struct *p, int flags);

        struct task_struct * (*pick_next_task) (struct rq *rq);
        void (*put_prev_task) (struct rq *rq, struct task_struct *p);

#ifdef CONFIG_SMP
        int  (*select_task_rq)(struct task_struct *p, int task_cpu, int sd_flag, int flags);
        void (*migrate_task_rq)(struct task_struct *p, int next_cpu);

        void (*pre_schedule) (struct rq *this_rq, struct task_struct *task);
        void (*post_schedule) (struct rq *this_rq);
        void (*task_waking) (struct task_struct *task);
        void (*task_woken) (struct rq *this_rq, struct task_struct *task);

        void (*set_cpus_allowed)(struct task_struct *p,
                                |const struct cpumask *newmask);

        void (*rq_online)(struct rq *rq);
        void (*rq_offline)(struct rq *rq);
#endif

        void (*set_curr_task) (struct rq *rq);
        void (*task_tick) (struct rq *rq, struct task_struct *p, int queued);
        void (*task_fork) (struct task_struct *p);
        void (*task_dead) (struct task_struct *p);

        void (*switched_from) (struct rq *this_rq, struct task_struct *task);
        void (*switched_to) (struct rq *this_rq, struct task_struct *task);
        void (*prio_changed) (struct rq *this_rq, struct task_struct *task,
                        |    int oldprio);

        unsigned int (*get_rr_interval) (struct rq *rq,
                                        |struct task_struct *task);

#ifdef CONFIG_FAIR_GROUP_SCHED
        void (*task_move_group) (struct task_struct *p, int on_rq);
#endif
};





       
