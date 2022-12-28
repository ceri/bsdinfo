INSTALL=	install
INSTALL_EXEC=	$(INSTALL) -m 0755
CC=	cc

target all:
	${CC} -lkvm -lc ${CFLAGS} bsdinfo.c -o bsdinfo
	${CC} -lkvm -lc ${CFLAGS} -DXTERM bsdinfo.c -o bsdinfox

install:
	${INSTALL_EXEC} bsdinfo /usr/local/bin/bsdinfo
	${INSTALL_EXEC} bsdinfox /usr/local/bin/bsdinfox

deinstall:
	rm /usr/local/bin/bsdinfo
	rm /usr/local/bin/bsdinfox

clean:
	rm -rf bsdinfo
	rm -rf bsdinfox
