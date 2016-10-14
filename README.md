# BADkernel
### *Bad and Dumb kernel for x86*.

Greetings, and welcome to the home of the BADkernel project. I started this
project to further my knowledge of kernel development, as well as to share some
(really basic) knowledge about the topic, with others.

In its current state, this kernel is by no means impressive, and it likely never
will be. My hope, however, is that others who are interested in getting into
kernel development, can use this as a "template" for their own kernels.

## Where should you start?
You're more than welcome to start anywhere you want, however, if you want to
start at the *very* beginning, I'd recommend checking out
[Kernel.S](./Kernel.S). Yes, it's written in Assembly, but it's really quite
simple.

I'd suggest you take a bit of time browsing the code, paying close attention to
any comments provided. If at any point in time you come across a term (or
anything else) that you don't understand, [Google it](https://www.google.com/)!

It is quite likely that at some point in the code, you will come across
something like follows:

```c
// TODO (You): Change this, and see what happens!
```

When you see a comment like that, if you're up to it, try messing around with
some of the values! Comments like those are included to help encourage you to
get your hands dirty. Hopefully after messing around with them a bit, you'll
have a better understanding of that part of the kernel.

**Please note** that if you plan to make changesto  the code, you'll need some
other tools. If you're on a Linux-based OS, you can take advantage of the script
I wrote to set these tools up.

If you want to use my script, open a shell, and navigate to the location in
which you cloned this repository, and run the following:

```bash
$ cd Tools
$ make build_cc
```

[This script](./Tools/Makefile), will attempt to download the required version
of GNU Binutils, as well as the version of GCC that is required. Once the
download operation is completed, the script will extract the downloaded files,
and begin launching the scripts necessary to build them. This process can take a
while, depending on your machine.

## Inspiration
The main inspiration for this project, was me wanting to learn more about
everything that goes into kernel development. On top of that, there are a couple
open-source kernels that helped to inspire me to write my own kernel:

 - [PowerNex](https://github.com/Vild/PowerNex)