INSTALL=	install
INSTALL_EXEC=	$(INSTALL) -m 0755
CC=	cc

target all:
	${CC} -lkvm -lc ${CFLAGS} bsdinfo.c utils.c -o bsdinfo
	${CC} -lkvm -lc ${CFLAGS} -DNO_XTERM bsdinfo.c utils.c -o bsdinfon

install: all
	${INSTALL_EXEC} bsdinfo /usr/local/bin/bsdinfo
	${INSTALL_EXEC} bsdinfon /usr/local/bin/bsdinfon

deinstall:
	rm -f /usr/local/bin/bsdinfo
	rm -f /usr/local/bin/bsdinfon

clean:
	rm -rf bsdinfo
	rm -rf bsdinfon
