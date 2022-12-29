INSTALL?=	install
INSTALL_PROGRAM?=	$(INSTALL) -m 0755
INSTALL_MAN?=	$(INSTALL) -m 0644
CC?=	cc
PREFIX?=	/usr/local
DESTDIR?=	

target all:
	${CC} -lkvm -lc ${CFLAGS} bsdinfo.c utils.c -o bsdinfo
	${CC} -lkvm -lc ${CFLAGS} -DNO_XTERM bsdinfo.c utils.c -o bsdinfon

install: all
	${INSTALL} -d -m 0755 ${DESTDIR}/${PREFIX}/bin
	${INSTALL} -d -m 0755 ${DESTDIR}/${PREFIX}/man/man1
	${INSTALL_PROGRAM} bsdinfo ${DESTDIR}/${PREFIX}/bin/bsdinfo
	${INSTALL_PROGRAM} bsdinfon ${DESTDIR}/${PREFIX}/bin/bsdinfon
	${INSTALL_MAN} bsdinfo.1 ${DESTDIR}/${PREFIX}/man/man1/bsdinfo.1

deinstall:
	rm -f ${DESTDIR}/${PREFIX}/bin/bsdinfo
	rm -f ${DESTDIR}/${PREFIX}/bin/bsdinfon
	rm -f ${DESTDIR}/${PREFIX}/man/man1/bsdinfo.1

clean:
	rm -rf bsdinfo
	rm -rf bsdinfon
