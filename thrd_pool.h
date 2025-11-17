#ifndef THRD_POOL_H
#define THRD_POOL_H

typedef struct thrdpool_s thrdpool_t; //def structure new name
typedef void (*handler_pt)(void *);

#ifdef __cplusplus
extern "C" 
{
#endif

thrdpool_t *thrdpool_create(int thrd_count);

void thrdpool_terminate(thrdpool_t *pool);

int thrdpool_post(thrdpool_t *pool, handler_pt func, void *arg);

void thrdpool_wait(thrdpool_t *pool);

#ifdef __cplusplus
}
#endif
#endif 