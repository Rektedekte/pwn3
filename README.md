CVE-2021-4034 Proof of Concept
==============================

Qualys researches found a pretty cool local privilege escalation vulnerability
in Polkit's `pkexec`: [writeup][qualys-wup], [tweet][qualys-tweet]. This vuln
has been around and exploitable on major Linux distros for quite a long time.
Security patches have been published, so I decided to write a very simple PoC to
show how trivial it is to exploit this. The code in this repo should be really
self-explanatory after reading the linked write-up. Also thanks to
[@Drago1729][drago-twitter] for the idea and [the help][drago-tweet].

How to:

1. Get a vulnerable version of `pkexec` e.g. from `policykit-1 <= 0.105-31` in
   the [Debian repos][polkit-debian] or even built [from source][polkit-source].
   You can  have it locally installed or just copy the `pkexec` executable alone
   directly in this directory (make sure it's executable and setuid root).
2. Ensure you have GCC installed in order to compile the two C helpers in this
   repo.
3. Run `./expl.sh` and enjoy.

**NOTE**: `expl.sh` will first look for `pkexec` in the current working directory,
then fall-back to `$PATH`. Since `pkexec` is usually a setuid-root executable,
maybe run this in a VM and not on your machine, y'know...

Demo:

![result](terminal.gif)

Cheers, @mebeim :)


[qualys-wup]:    https://www.qualys.com/2022/01/25/cve-2021-4034/pwnkit.txt
[qualys-tweet]:  https://mobile.twitter.com/qualys/status/1486034484323569664
[polkit-debian]: http://ftp.us.debian.org/debian/pool/main/p/policykit-1/
[polkit-source]: https://salsa.debian.org/utopia-team/polkit/-/commits/master/
[drago-twitter]: https://twitter.com/Drago1729/
[drago-tweet]:   https://twitter.com/Drago1729/status/1486145716544319494
