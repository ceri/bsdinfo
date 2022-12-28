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

int main(int argc, char *argv[])
{
    int i, proc_count = 0, nflag, sflag = 0, xflag;
    int ch;
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

#ifdef NO_XTERM
    nflag = 1, xflag = 0;
#else
    nflag = 0, xflag = 1;
#endif

    for (i = 0, kp = plist; i < nproc; i++, kp++) proc_count++;

    while ((ch = getopt(argc, argv, "nsx")) != -1)
      switch (ch) {
	case 'n':
	  nflag = 1, xflag = 0;
	  break;
	case 's':
	  sflag = 1;
	  break;
	case 'x':
	  nflag = 0, xflag = 1;
	  break;
	default:
	  usage();
	  break;
	}
      argc -= optind;
      argv += optind;
    
    printf("\n");
    printf(xflag? XLINE1 :NLINE1 ); printf("\n");
    printf(xflag? XLINE2 :NLINE2 );
	printval("OS", "kern.ostype"); printf(" "); psysctl("hw.machine_arch"); printf("\n");
    printf(xflag? XLINE3 :NLINE3 ); printval("Hostname", "kern.hostname");  printf("\n");
    printf(xflag? XLINE4 :NLINE5 ); printval("Kernel", "kern.osrelease");  printf("\n");
    printf(xflag? XLINE5 :NLINE5 ); printuptime(); printf("\n");
    printf(xflag? XLINE6 :NLINE6 ); printf("\033[1;31mProcesses:\033[0;0m %d\n", proc_count);
    printf(xflag? XLINE7 :NLINE7 ); printmem(); printf("\n");
    printf(xflag? XLINE8 :NLINE8 ); printcpu(); printf("\n");
    printf(xflag? XLINE9 :NLINE9 ); printshell(sflag); printf("\n");
    printf(xflag? XLINE10:NLINE10); printbootmethod(); printf("\n");
    printf(xflag? XLINE11:NLINE11); printf("\n");
    printf(xflag? XLINE12:NLINE12); printf("\n");
    printf(xflag? XLINE13:NLINE13); printf("\n");
    printf(xflag? XLINE14:NLINE14); printf("\n");
    printf(xflag? XLINE15:NLINE15); printf("\n");
    if (xflag) {
      printf(XLINE16); printf("\n");
      printf(XLINE17); printf("\n");
      printf(XLINE18); printf("\n");
    }
    printf("\n");
    return (0);
}
