Welcome to the Opportunities of Binary Translation

author：[ER Altman](https://scholar.google.com.hk/citations?user=E2kFvGAAAAAJ&hl=zh-CN&oi=sra), [D Kaeli](https://scholar.google.com.hk/citations?user=Mkgn0qcAAAAJ&hl=zh-CN&oi=sra), [Y Sheffer](https://scholar.google.com.hk/citations?user=Bpx2sXEAAAAJ&hl=zh-CN&oi=sra)

ER Altman - IBM的研究部门的（ER 奥特曼）

D Kaeli 大学教授（凯利教授）

Y Sheffer   （sheofer）

设计新的处理器架构会需要大量的财力人物，而软件设计又是与硬件架构ISA紧紧联系在一起的，这种硬件和软件的强耦合性阻碍了新的处理器架构的出现与发展，为了打破这种现象，出现了二进制翻译的技术，该技术能够将架构A上的可执行程序在不重新编译的情况在架构B上运行，该文章提出了两种实现方案



为什么选择二进制代码进行翻译，而不是现代语言进行翻译？

二进制代码的语义十分清晰，便于自动和透明翻译，而现代语言大多数语义的定义不够严格，有未定义行为，并且可能会随着版本发生变化

语义是什么？程序语句的行为定义，x+y的结果是什么？是否会溢出？是否需要类型转换？



将旧ISA上的旧软件移植到新的ISA时：要么需要提供新处理模式，要么以让新ISA重新编译旧代码然后执行，要么**利用软件解决方案对程序进行解释翻译。**



三篇二进制翻译论文：**还没看**

![image-20250514105810720](https://raw.githubusercontent.com/upsetgrass/typora_pic_bed/main/image-20250514105810720.png)



三种翻译类型：

仿真器（emulators）、动态翻译器（dynamic translators）和静态翻译器（static translators）

1、仿真器在运行时解释程序指令，系统不缓存解释的指令，开发难度较低

2、动态翻译器对两个ISA之间进行翻译，运行时翻译，将翻译后的代码片段进行缓存（效率考虑），JAva JIT（Just-In-Time）编译器就是动态翻译器，在运行时将字节码动态翻译成本机指令

JIT编译器：JIT是一类技术，Latte是一种特定的JIT编译器实现，Latte能将Java字节码生成高质量的Sparc指令代码（risc的一种指令集架构）

3、静态翻译器是一种offline翻译技术，这个offline可以本意是离线，也可以解释为运行之前翻译技术，一次性把整个程序翻译成目标架构的二进制程序，由于其探测范围是整个程序，并且不追求实时快速，所以能够比动态二进制翻译执行更严格、高级（更深层的函数内联、死代码消除、控制流图重写等）的代码优化，并且静态翻译器能够利用上次运行收集到的profiles（执行剖面）数据

什么是profiles？是一种全局性的统计信息，反映的是整个二进制程序在某次运行过程中的动态行为特征，帮助优化器、编译器理解程序的运行，比如如下信息：

![image-20250514115501238](https://raw.githubusercontent.com/upsetgrass/typora_pic_bed/main/image-20250514115501238.png)

与动态翻译器保存的缓存不同，动态翻译器的缓存是供当次运行后续使用，静态翻译器保存的profile会以普通文件的形式保存到磁盘，供下一次编译优化使用



这三种单独看来都有缺陷，仿真器和动态翻译器运行时会有额外开销，而静态翻译器需要用户参与

![image-20250515093607227](https://raw.githubusercontent.com/upsetgrass/typora_pic_bed/main/image-20250515093607227.png)

因而出现了将上述三类翻译器进行混合，结合每一种方法的最佳特性





