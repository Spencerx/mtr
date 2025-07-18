WHAT IS MTR?
===

mtr combines the functionality of the 'traceroute' and 'ping' programs
in a single network diagnostic tool.

As mtr starts, it investigates the network connection between the host
mtr runs on and a user-specified destination host.  After it
determines the address of each network hop between the machines,
it sends a sequence of ICMP ECHO requests to each one to determine the
quality of the link to each machine.  As it does this, it prints
running statistics about each machine.

mtr is distributed under the GNU General Public License version 2.
See the COPYING file for details.

INSTALLING
===

If you're building this from a tarball, compiling mtr is as
simple as:

	./configure && make

Please note that this refers to the tarballs from
 https://www.bitwizard.nl/mtr/files/
and not the tarballs that github can produce.

(in the past, there was a Makefile in the distribution that did
the `./configure` for you and then ran make again with the generated
Makefile, but this has suffered some bitrot. It didn't work well
with git.)

If you're building from the git repository, you'll need to run:

	./bootstrap.sh && ./configure && make

When it looks as if the compilation was successful, you can
test mtr with

	sudo ./mtr <host>

(fill in a hostname or IP address where it says ``<host>``) or
immediately continue on to installing:

	make install

Note that mtr-packet must be suid-root because it requires access to
raw IP sockets.  See SECURITY for security information.

Older versions used to require a non-existent path to GTK for a
correct build of a non-gtk version while GTK was installed. This is
no longer necessary. `./configure --without-gtk` should now work.
If it doesn't, try `make WITHOUT_X11=YES` as the make step.

On Solaris, you'll need to use GNU make to build.
(Use `gmake` rather than `make`.)

On Solaris (and possibly other systems) the "gtk" library may be
installed in a directory where the dynamic linker refuses to look when
a binary is setuid. Roman Shterenzon reports that adding
        -Wl,-rpath=/usr/lib
to the commandline will work if you are using gnu LD. He tells me that
you're out of luck when you use the sun LD. That's not quite true, as
you can move the gtk libraries to `/usr/lib` instead of leaving them in
`/usr/local/lib`.  (when the ld tells you that `/usr/local/lib` is untrusted
and `/usr/lib` is trusted, and you trust the gtk libs enough to want them
in a setuid program, then there is something to say for moving them
to the "trusted" directory.)

Building on MacOS should not require any special steps.

USING MTR ON WINDOWS
===

Using mtr on Windows requires Windows Subsystem for Linux (WSL).  
To install WSL with Ubuntu distribution (Default), see
[How to install Linux on Windows with WSL](https://learn.microsoft.com/en-us/windows/wsl/install).

After complete initial process,
simple as:

	sudo apt-get -y install mtr



BUILDING FOR WINDOWS (TRADITIONAL METHOD)
===

If you prefer traditional method.
Obtain Cygwin, see
https://cygwin.com/install.html.

Next, re-run cygwin's `setup-x86.exe` (or `setup-x86_64.exe` if you're using 64bit cygwin) with the following arguments,

which will install the packages required for building:

        setup-x86.exe --package-manager --wait --packages automake,pkg-config,make,gcc-core,libncurses-devel,libjansson-devel

Build as under Unix:

        ./bootstrap.sh && ./configure && make

Finally, install the built binaries:

        make install




WHERE CAN I GET THE LATEST VERSION OR MORE INFORMATION?
===

mtr is now hosted on github.
https://github.com/traviscross/mtr

See the mtr web page at http://www.BitWizard.nl/mtr/

Bug reports and feature requests should be submitted to the Github bug tracking system.

Patches can be submitted by cloning the Github repository and issuing
a pull request, or by email to me. Please use unified diffs. Usually
the diff is sort of messy, so please check that the diff is clean and
doesn't contain too much of your local stuff (for example, I don't
want/need the "configure" script that /your/ automake made for you).

(There used to be a mailinglist, but all it got was spam. So
when the server was upgraded, the mailing list died.)


REW
