//CFS scheduler

Linux 3.14
/kernel/sched/core.c
static void __sched __schedule(void)
{
    next = pick_next_task(rq);
}

/kernel/sched/fair.c
const struct sched_class fair_sched_class = {
    .pick_next_task         = pick_next_task_fair,
}

/kernel/sched/fair.c
static struct task_struct *pick_next_task_fair(struct rq *rq)
{
    se = pick_next_entity(cfs_rq);
}

/kernel/sched/fair.c
static struct sched_entity *pick_next_entity(struct cfs_rq *cfs_rq)
{
    struct sched_entity *second = __pick_next_entity(se);
}

/kernel/sched/fair.c
//__pick_first_entity() picks the left most node from the tree
static struct sched_entity *__pick_next_entity(struct sched_entity *se)
{
        struct rb_node *next = rb_next(&se->run_node);
        if (!next)
                return NULL;

        return rb_entry(next, struct sched_entity, run_node);    
}




