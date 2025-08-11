.section .text
.globl _start
_start:
    li a7, 64    # Linux write 系统调用号
    li a0, 1     # stdout
    la a1, msg   # 字符串地址
    li a2, 12    # 字符串长度
    ecall        # 触发系统调用
    li a7, 93    # exit 系统调用
    li a0, 0     # 退出码，正常退出
    ecall

.section .rodata
msg:
    .string "hello world\n"
