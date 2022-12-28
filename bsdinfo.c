/*-
 * Copyright (c) 2012, Jakub Szafrański <samu@pirc.pl>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

 
#include <sys/types.h>
#include <sys/sysctl.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/timespec.h>
#include <time.h>
#include <sys/proc.h>
#include <kvm.h>
#include <vm/vm_param.h>
#include <string.h>
#include <sys/user.h>

#include "bsdinfo.h"
#include "daemon.h"

int main()
{
    int i, proc_count = 0;
    char buf[_POSIX2_LINE_MAX];
    const char *execf, *coref;
    static kvm_t *kd;
    struct kinfo_proc *kp;
    static int nproc;
    static struct kinfo_proc *plist;
    
    execf = NULL;
    coref = _PATH_DEVNULL;
    kd = kvm_openfiles(execf, coref, NULL, O_RDONLY, buf);
    plist = kvm_getprocs(kd, KERN_PROC_PROC, 0, &nproc);

    for (i = 0, kp = plist; i < nproc; i++, kp++) proc_count++;
    
    printf("\n");
    printf(LINE1 ); printf("\n");
    printf(LINE2 ); printval("OS", "kern.ostype"); printf(" "); psysctl("hw.machine_arch"); printf("\n");
    printf(LINE3 ); printval("Hostname", "kern.hostname");  printf("\n");
    printf(LINE4 ); printval("Kernel", "kern.osrelease");  printf("\n");
    printf(LINE5 ); printuptime(); printf("\n");
    printf(LINE6 ); printf("\033[1;31mProcesses:\033[0;0m %d\n", proc_count);
    printf(LINE7 ); printmem(); printf("\n");
    printf(LINE8 ); printcpu(); printf("\n");
    printf(LINE9 ); printshell(); printf("\n");
    printf(LINE10); printbootmethod(); printf("\n");
    printf(LINE11); printf("\n");
    printf(LINE12); printf("\n");
    printf(LINE13); printf("\n");
    printf(LINE14); printf("\n");
    printf(LINE15); printf("\n");
#ifdef XTERM
    printf(LINE16); printf("\n");
    printf(LINE17); printf("\n");
    printf(LINE18); printf("\n");
#endif
    printf("\n");
    return (0);
}
