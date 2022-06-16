INSTALL=	install
INSTALL_EXEC=	$(INSTALL) -m 0755
CC=	cc

target all:
	${CC} -lkvm -lc ${CFLAGS} bsdinfo.c -o bsdinfo

install:
	${INSTALL_EXEC} bsdinfo /usr/local/bin/bsdinfo

deinstall:
	rm /usr/local/bin/bsdinfo

clean:
	rm -rf bsdinfo
