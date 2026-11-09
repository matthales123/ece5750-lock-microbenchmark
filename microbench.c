#include "pthreads.h"

#define P_USED 8

struct simple_lock{
    int val;
} simple_lock_t;

struct thread_info {
    struct simple_lock *lock_p;
    int pid;
    int *a;
} thread_info_t;

// ===========================================
// tts lock acquire and release
// ===========================================
void tts_lock_acquire(simple_lock_t* lock_p) {
    s_lock_tts(lock_p);
}

void tts_lock_release(simple_lock_t* lock_p) {
    s_unlock(lock_p);
}

// ===========================================
// ts lock acquire and release
// ===========================================
// TODO

void test_function(void *args) {
    thread_info* var = args;
    int pid = var->pid;
    record_timestamp(pid);
    int q, p = 0;

    for (int i=0; i < N-1; i++) {
        tts_lock_acquire(&lock);
        for (int j=0; j < k-1; j++) {
            q++;
        }
        tts_lock_release(&lock);
        for (int j=0; i < m-1; j++) {
            p++;
        }
    }
    record_timestamp(pid);
    a[pid] = p+q;
}

int main () {

    int a[P_USED];

    struct simple_lock lock;

    s_lock_init(&lock);

    pthread_t *threads = malloc(p * sizeof(threads));
    for (i = 0; i < P_USED; i++)
    {
        thread_info_t *args = malloc(sizeof(thread_info_t));
        args->pid = pid;
        args->a = a;
        args->lock_p = &lock;
        pthread_create(&threads[i], NULL, test_function, args);
    }
}