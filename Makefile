INSTALL?=	install
INSTALL_PROGRAM?=	$(INSTALL) -m 0755
CC?=	cc
PREFIX?=	/usr/local
DESTDIR?=	

target all:
	${CC} -lkvm -lc ${CFLAGS} bsdinfo.c utils.c -o bsdinfo
	${CC} -lkvm -lc ${CFLAGS} -DNO_XTERM bsdinfo.c utils.c -o bsdinfon

install: all
	${INSTALL} -d -m 0755 ${DESTDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} bsdinfo ${DESTDIR}/${PREFIX}/bin/bsdinfo
	${INSTALL_PROGRAM} bsdinfon ${DESTDIR}/${PREFIX}/bin/bsdinfon

deinstall:
	rm -f ${DESTDIR}/${PREFIX}/bin/bsdinfo
	rm -f ${DESTDIR}/${PREFIX}/bin/bsdinfon

clean:
	rm -rf bsdinfo
	rm -rf bsdinfon
