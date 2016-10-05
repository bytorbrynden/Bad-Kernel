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

**Please note** that if you plan to mess with the code, you'll need some other
tools. I will include my own instructions on how to set these up, at a later
date. For now, however, you can [reference this](http://wiki.osdev.org/GCC_Cross-Compiler).