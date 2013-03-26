/****************************************************************************
 * syscall/syscall_stublookup.c
 *
 *   Copyright (C) 2011-2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <syscall.h>

/* The content of this file is only meaningful during the kernel phase of
 * a kernel build.
 */

#if defined(CONFIG_NUTTX_KERNEL) && defined(__KERNEL__)

/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

/****************************************************************************
 * Stub Function Prototypes
 ****************************************************************************/

/* These first system calls are supported regardless of the NuttX
 * configuration
 */

uintptr_t STUB__exit(int nbr, uintptr_t parm1);
uintptr_t STUB_exit(int nbr, uintptr_t parm1);
uintptr_t STUB_get_errno(int nbr);
uintptr_t STUB_getpid(int nbr);
uintptr_t STUB_sched_getparam(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_sched_getscheduler(int nbr, uintptr_t parm1);
uintptr_t STUB_sched_lock(int nbr);
uintptr_t STUB_sched_lockcount(int nbr);
uintptr_t STUB_sched_rr_get_interval(int nbr, uintptr_t parm1,
            uintptr_t parm2);
uintptr_t STUB_sched_setparam(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_sched_setscheduler(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_sched_unlock(int nbr);
uintptr_t STUB_sched_yield(int nbr);
uintptr_t STUB_sem_close(int nbr, uintptr_t parm1);
uintptr_t STUB_sem_destroy(int nbr, uintptr_t parm1);
uintptr_t STUB_sem_open(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5, uintptr_t parm6);
uintptr_t STUB_sem_post(int nbr, uintptr_t parm1);
uintptr_t STUB_sem_trywait(int nbr, uintptr_t parm1);
uintptr_t STUB_sem_unlink(int nbr, uintptr_t parm1);
uintptr_t STUB_sem_wait(int nbr, uintptr_t parm1);
uintptr_t STUB_set_errno(int nbr, uintptr_t parm1);
uintptr_t STUB_task_create(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);
uintptr_t STUB_task_delete(int nbr, uintptr_t parm1);
uintptr_t STUB_task_restart(int nbr, uintptr_t parm1);
uintptr_t STUB_up_assert(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_up_assert_code(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);

/* The following can be individually enabled */

uintptr_t STUB_vfork(int nbr);
uintptr_t STUB_atexit(int nbr, uintptr_t parm1);
uintptr_t STUB_on_exit(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_waitpid(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_wait(int nbr, uintptr_t parm1);
uintptr_t STUB_waitid(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4);

/* The following can only be defined if we are configured to execute
 * programs from a file system.
 */

uintptr_t STUB_posix_spawn(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_posix_spawnp(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_execv(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_execl(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);

/* The following are only defined is signals are supported in the NuttX
 * configuration.
 */

uintptr_t STUB_kill(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_sigaction(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_sigpending(int nbr, uintptr_t parm1);
uintptr_t STUB_sigprocmask(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_sigqueue(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_sigsuspend(int nbr, uintptr_t parm1);
uintptr_t STUB_sigtimedwait(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_sigwaitinfo(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_sleep(int nbr, uintptr_t parm1);
uintptr_t STUB_usleep(int nbr, uintptr_t parm1);

/* The following are only defined if the system clock is enabled in the
 * NuttX configuration.
 */

uintptr_t STUB_clock_systimer(int nbr);
uintptr_t STUB_clock_getres(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_clock_gettime(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_clock_settime(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_gettimeofday(int nbr, uintptr_t parm1, uintptr_t parm2);

/* The following are defined only if POSIX timers are supported */

uintptr_t STUB_timer_create(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_timer_delete(int nbr, uintptr_t parm1);
uintptr_t STUB_timer_getoverrun(int nbr, uintptr_t parm1);
uintptr_t STUB_timer_gettime(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_timer_settime(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4);

/* The following are defined if either file or socket descriptor are
 * enabled.
 */

uintptr_t STUB_close(int nbr, uintptr_t parm1);
uintptr_t STUB_ioctl(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_poll(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_read(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_select(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);
uintptr_t STUB_write(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);

/* The following are defined if file descriptors are enabled */

uintptr_t STUB_closedir(int nbr, uintptr_t parm1);
uintptr_t STUB_dup(int nbr, uintptr_t parm1);
uintptr_t STUB_dup2(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_fcntl(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_lseek(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_mkfifo(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_mmap(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_open(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_opendir(int nbr, uintptr_t parm1);
uintptr_t STUB_pipe(int nbr, uintptr_t parm1);
uintptr_t STUB_readdir(int nbr, uintptr_t parm1);
uintptr_t STUB_rewinddir(int nbr, uintptr_t parm1);
uintptr_t STUB_seekdir(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_stat(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_statfs(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_telldir(int nbr, uintptr_t parm1);

uintptr_t STUB_fs_fdopen(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_sched_getstreams(int nbr);

uintptr_t STUB_fsync(int nbr, uintptr_t parm1);
uintptr_t STUB_mkdir(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_mount(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);
uintptr_t STUB_rename(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_rmdir(int nbr, uintptr_t parm1);
uintptr_t STUB_umount(int nbr, uintptr_t parm1);
uintptr_t STUB_unlink(int nbr, uintptr_t parm1);

/* The following are defined if pthreads are enabled */

uintptr_t STUB_pthread_barrier_destroy(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_barrier_init(int nbr, uintptr_t parm1,
            uintptr_t parm2, uintptr_t parm3);
uintptr_t STUB_pthread_barrier_wait(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_cancel(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_cond_broadcast(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_cond_destroy(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_cond_init(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_pthread_cond_signal(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_cond_wait(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_pthread_create(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4);
uintptr_t STUB_pthread_detach(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_exit(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_getschedparam(int nbr, uintptr_t parm1,
            uintptr_t parm2, uintptr_t parm3);
uintptr_t STUB_pthread_getspecific(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_join(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_pthread_key_create(int nbr, uintptr_t parm1,
            uintptr_t parm2);
uintptr_t STUB_pthread_key_delete(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_mutex_destroy(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_mutex_init(int nbr, uintptr_t parm1,
            uintptr_t parm2);
uintptr_t STUB_pthread_mutex_lock(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_mutex_trylock(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_mutex_unlock(int nbr, uintptr_t parm1);
uintptr_t STUB_pthread_once(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_pthread_setcancelstate(int nbr, uintptr_t parm1,
            uintptr_t parm2);
uintptr_t STUB_pthread_setschedparam(int nbr, uintptr_t parm1,
            uintptr_t parm2, uintptr_t parm3);
uintptr_t STUB_pthread_setschedprio(int nbr, uintptr_t parm1,
            uintptr_t parm2);
uintptr_t STUB_pthread_setspecific(int nbr, uintptr_t parm1,
            uintptr_t parm2);
uintptr_t STUB_pthread_yield(int nbr);

uintptr_t STUB_pthread_cond_timedwait(int nbr, uintptr_t parm1,
            uintptr_t parm2, uintptr_t parm3);
uintptr_t STUB_pthread_kill(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_pthread_sigmask(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);

/* The following are defined only if message queues are enabled */

uintptr_t STUB_mq_close(int nbr, uintptr_t parm1);
uintptr_t STUB_mq_notify(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_mq_open(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_mq_receive(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4);
uintptr_t STUB_mq_send(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4);
uintptr_t STUB_mq_timedreceive(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);
uintptr_t STUB_mq_timedsend(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);
uintptr_t STUB_mq_unlink(int nbr, uintptr_t parm1);

/* The following are defined only if environment variables are supported */

uintptr_t STUB_clearenv(int nbr);
uintptr_t STUB_getenv(int nbr, uintptr_t parm1);
uintptr_t STUB_putenv(int nbr, uintptr_t parm1);
uintptr_t STUB_setenv(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_unsetenv(int nbr, uintptr_t parm1);

/* The following are defined only if networking AND sockets are supported */

uintptr_t STUB_accept(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_bind(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_connect(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);
uintptr_t STUB_getsockopt(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);
uintptr_t STUB_listen(int nbr, uintptr_t parm1, uintptr_t parm2);
uintptr_t STUB_recv(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4);
uintptr_t STUB_recvfrom(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_send(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4);
uintptr_t STUB_sendto(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5,
            uintptr_t parm6);
uintptr_t STUB_setsockopt(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);
uintptr_t STUB_socket(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3);

/* The following is defined only if CONFIG_TASK_NAME_SIZE > 0 */

uintptr_t STUB_prctl(int nbr, uintptr_t parm1, uintptr_t parm2,
            uintptr_t parm3, uintptr_t parm4, uintptr_t parm5);

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* Stub lookup tables.  This table is indexed by the system call number.
 * Given the system call number, the corresponding entry in this table
 * provides the address of the stub function.
 */

const uintptr_t g_stublookup[SYS_nsyscalls] =
{
#  undef SYSCALL_LOOKUP1
#  define SYSCALL_LOOKUP1(f,n,p) (uintptr_t)p
#  undef SYSCALL_LOOKUP
#  define SYSCALL_LOOKUP(f,n,p)  , (uintptr_t)p
#  include "syscall_lookup.h"
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#endif /* CONFIG_NUTTX_KERNEL && __KERNEL__ */

