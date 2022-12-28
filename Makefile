INSTALL=	install
INSTALL_EXEC=	$(INSTALL) -m 0755
CC=	cc
DESTDIR?=	/usr/local

target all:
	${CC} -lkvm -lc ${CFLAGS} bsdinfo.c utils.c -o bsdinfo
	${CC} -lkvm -lc ${CFLAGS} -DNO_XTERM bsdinfo.c utils.c -o bsdinfon

install: all
	${INSTALL} -d -m 0755 ${DESTDIR}
	${INSTALL_EXEC} bsdinfo ${DESTDIR}/bin/bsdinfo
	${INSTALL_EXEC} bsdinfon ${DESTDIR}/bin/bsdinfon

deinstall:
	rm -f ${DESTDIR}/bin/bsdinfo
	rm -f ${DESTDIR}/bin/bsdinfon

clean:
	rm -rf bsdinfo
	rm -rf bsdinfon
