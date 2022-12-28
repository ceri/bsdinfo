# bsdinfo

## Description
My attempt at adding options to the original [bsdinfo](https://github.com/samupl/bsdinfo)
to add an option that I wanted, namely not to print the shell info and
to avoid printing empty boot method stuff.

## Installation

To build the program, simply run:

    make

The xterm-256 colour version is now default; if you want a non-colour
version then you can run `bsdinfon` or add the `-n` flag:

    bsdinfo -n

To install the binaries:

    make install

You will need to have root permissions to run `make install`, as it
requires write access to /usr/local/bin. The binaries will be installed at
`/usr/local/bin/bsdinfo` and `/usr/local/bin/bsdinfon`.

