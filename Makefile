INSTALL=	install
INSTALL_EXEC=	$(INSTALL) -m 0755
CC=	cc
PREFIX?=	/usr/local

target all:
	${CC} -lkvm -lc ${CFLAGS} bsdinfo.c utils.c -o bsdinfo
	${CC} -lkvm -lc ${CFLAGS} -DNO_XTERM bsdinfo.c utils.c -o bsdinfon

install: all
	${INSTALL} -d -m 0755 ${PREFIX}/bin
	${INSTALL_EXEC} bsdinfo ${PREFIX}/bin/bsdinfo
	${INSTALL_EXEC} bsdinfon ${PREFIX}/bin/bsdinfon

deinstall:
	rm -f ${PREFIX}/bin/bsdinfo
	rm -f ${PREFIX}/bin/bsdinfon

clean:
	rm -rf bsdinfo
	rm -rf bsdinfon
