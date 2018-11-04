# aslrSmasher
gcc-4.8 vuln.c -w -fno-stack-protector -z execstack -m32 -o vuln

service telnet
{
    disable = no
    socket_type = stream
    protocol = tcp
    flags = IPv6
    wait = no
    user = root
    server = /sbin/vuln
    #server_args = -w
    log_type = FILE /dev/null
    log_on_success = HOST
    cps = 512 5
}

(gdb) i proc mappings 
process 11131
Mapped address spaces:

        Start Addr   End Addr       Size     Offset objfile
         0x8048000  0x804b000     0x3000        0x0 /sbin/vuln
         0x804b000  0x804c000     0x1000     0x2000 /sbin/vuln
         0x804c000  0x804d000     0x1000     0x3000 /sbin/vuln
        0xf7df0000 0xf7fa1000   0x1b1000        0x0 /lib/i386-linux-gnu/libc-2.24.so
        0xf7fa1000 0xf7fa3000     0x2000   0x1b0000 /lib/i386-linux-gnu/libc-2.24.so
        0xf7fa3000 0xf7fa4000     0x1000   0x1b2000 /lib/i386-linux-gnu/libc-2.24.so
        0xf7fa4000 0xf7fa7000     0x3000        0x0 
        0xf7fd2000 0xf7fd5000     0x3000        0x0 
        0xf7fd5000 0xf7fd7000     0x2000        0x0 [vvar]
        0xf7fd7000 0xf7fd9000     0x2000        0x0 [vdso]
        0xf7fd9000 0xf7ffc000    0x23000        0x0 /lib/i386-linux-gnu/ld-2.24.so
        0xf7ffc000 0xf7ffd000     0x1000    0x22000 /lib/i386-linux-gnu/ld-2.24.so
        0xf7ffd000 0xf7ffe000     0x1000    0x23000 /lib/i386-linux-gnu/ld-2.24.so
        0xfffdd000 0xffffe000    0x21000        0x0 [stack]
(gdb) 

