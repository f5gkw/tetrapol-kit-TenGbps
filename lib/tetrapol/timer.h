#pragma once

#include <stdbool.h>
#include <sys/time.h>

typedef struct {
    struct timeval tv;
} time_evt_t;
typedef struct timer_priv_t timer_t;

typedef void (*timer_callback_t)(time_evt_t *te, void *ptr);

timer_t *timer_create(void);
void timer_destroy(timer_t *timer);
void timer_tick(timer_t *timer, int usec);
bool timer_register(timer_t *timer, timer_callback_t timer_func, void *ptr);
void timer_cancel(timer_t *timer, timer_callback_t timer_func, void *ptr);

/**
 * @brief time_delta Compute difference in two timestamps (us)
 * @param tv1
 * @param tv2
 * @return delta t in us
 */
int timeval_abs_delta(const struct timeval *tv1, const struct timeval *tv2);
