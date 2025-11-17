#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include "thrd_pool.h"
#include "spinlock.h"

typedef struct task_queue_s{
    void *head;
    void **tail;
    int block;
    spinlock_t lock;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

}task_queue_t



struct thrdpool_s
{
    task_queue_t *task_queue;
    atomic_init quit;
    int thrd_count;
    pthread_t *threads;
};




static void __threads_terminate(thrdpool_t *pool){
    atomic_store(&pool->quit, 1);
    __nonblock(pool->task_queue);
    int i;
    for(i=0; i<pool->thrd_count; i++){
        pthread_join(pool->threads[i], NULL);
    }

}


static int __threads_create(thrdpool_t *pool, size_t thrd_count)
{
    pthread_attr_t attr;
    int ret;

    ret = pthread_attr_init(&attr);
    if (ret == 0){
        pool->threads = (pthread_t  *)malloc(sizeof(pthread_t) * thrd_count);
        if (pool->threads){
            int i = 0;
            for(; i < thrd_count; i++){
                if (pthread_create(&pool->threads[i], &attr,__thrdpool_worker,pool))
                {
                    break;
                }
            }
            pool->thrd_count = i;
            pthread_attr_destroy(&attr);
            if (i == thrd_count)
                return 0;
            __threads_terminate(pool);
            free(pool->threads);

        }
        ret = -1;
    }
    return ret;

}
