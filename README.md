# os-lab2
## 实验二 进程控制<br>
#### 安全1601  战泓夷  16281022<br><br>
根据课堂所学内容和基础知识介绍，完成实验题目。
* 1、打开一个vi进程。通过ps命令以及选择合适的参数，只显示名字为vi的进程。寻找vi进程的父进程，直到init进程为止。记录过程中所有进程的ID和父进程ID。将得到的进程树和由pstree命令的得到的进程树进行比较。
首先使用vi打开编辑一个文件，输入内容后，在终端使用ps命令查找该进程，然后根据其父进程直至找到init进程。

![input_txt](https://github.com/16281022/-_16281022/blob/master/1.png)
![input_txt](https://github.com/16281022/-_16281022/blob/master/2.png)

在终端输入命令pstree -p 1查询进程树<br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/3.png)
![input_txt](https://github.com/16281022/-_16281022/blob/master/4.png)

二者比较：
ps命令是从当前进程一步步寻找父进程，查找的信息更丰富、全面，但是操作繁琐，不是很简便；而pstree是从初始进程开始，一次给出全部进程，结构清晰，但所包含的内容比较少。
<br>
* 2、编写程序，首先使用fork系统调用，创建子进程。在父进程中继续执行空循环操作；在子进程中调用exec打开vi编辑器。然后在另外一个终端中，通过ps –Al命令、ps aux或者top等命令，查看vi进程及其父进程的运行状态，理解每个参数所表达的意义。选择合适的命令参数，对所有进程按照cpu占用率排序。

按要求编写程序：<br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/5.png)

编译程序，打开另一终端：<br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/6.png)

* ps-l：将目前属于您自己这次登入的 PID 与相关信息列示出来，ps-A：显示所有进程信息
![input_txt](https://github.com/16281022/-_16281022/blob/master/7.png)
![input_txt](https://github.com/16281022/-_16281022/blob/master/8.png)

F  代表这个程序的旗标 (flag)， 4 代表使用者为 super user<br>
S  代表这个程序的状态 (STAT)<br>
UID  程序被该 UID 所拥有<br>
PID  就是这个程序的 ID <br>
PPID  则是其上级父程序的ID<br>
C CPU  使用的资源百分比<br>
PRI  这个是 Priority (优先执行序) 的缩写<br>
NI  这个是 Nice 值<br>
ADDR   这个是 kernel function，指出该程序在内存的那个部分。如果是个 running的程序，一般就是 "-"<br>
SZ  使用掉的内存大小<br>
WCHAN  目前这个程序是否正在运作当中，若为 - 表示正在运作<br>
TTY  登入者的终端机位置<br>
TIME  使用掉的 CPU 时间<br>
CMD  所下达的指令为何<br>

* ps aux： 列出目前所有的正在内存当中的程序<br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/9.png)
![input_txt](https://github.com/16281022/-_16281022/blob/master/10.png)

USER 该 process 属于那个使用者账号的<br>
PID  该 process 的号码<br>
%CPU 该 process 使用掉的 CPU 资源百分比<br>
%MEM 该 process 所占用的物理内存百分比<br>
VSZ  该 process 使用掉的虚拟内存量 (Kbytes)<br>
RSS  该 process 占用的固定的内存量 (Kbytes)<br>
TTY  该 process 是在那个终端机上面运作， tty1-tty6 是本机上面的登入者程序，若为 pts/0 等等的，则表示为由网络连接进主机的程序。<br>
STAT 该程序目前的状态<br>
R  该程序目前正在运作，或者是可被运作<br>
S  该程序目前正在睡眠当中 (可说是 idle 状态)，但可被某些讯号 (signal) 唤醒。<br>
T  该程序目前正在侦测或者是停止了<br>
Z  该程序应该已经终止，但是其父程序却无法正常的终止他，造成 zombie (疆尸) 程序的状态<br>
START 该 process 被触发启动的时间<br>
TIME  该 process 实际使用 CPU 运作的时间<br>
COMMAND 该程序的实际指令<br>

* top<br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/11.png)<br>
PID     进程id<br>
USER    进程所有者的用户名<br>
PR      优先级<br>
VIRT    进程使用的虚拟内存总量，单位kb。VIRT=SWAP+RES<br>
RES     进程使用的、未被换出的物理内存大小，单位kb。RES=CODE+DATA<br>
SHR     共享内存大小，单位kb<br>
S       进程状态(D=不可中断的睡眠状态,R=运行,S=睡眠,T=跟踪/停止,Z=僵尸进程)<br>
%CPU    上次更新到现在的CPU时间占用百分比<br>
%MEM    进程使用的物理内存百分比<br>
TIME+   进程使用的CPU时间总计，单位1/100秒<br>
COMMAND 命令名/命令行<br><br>
* 3、使用fork系统调用，创建如下进程树，并使每个进程输出自己的ID和父进程的ID。观察进程的执行顺序和运行状态的变化。<br>

（1）代码截图：<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/12.png)<br>
（2）编译结果：<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/13.png)<br>
（3）结果分析：<br><br>
P1：5255<br>
P2：5256<br>
P3：5257<br>
P4：5258<br>
P5：5259<br><br>

* 4、修改上述进程树中的进程，使得所有进程都循环输出自己的ID和父进程的ID。然后终止p2进程(分别采用kill -9 、自己正常退出exit()、段错误退出)，观察p1、p3、p4、p5进程的运行状态和其他相关参数有何改变。<br>
（1）使用kill -9<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/14.png)<br>
结果如下：<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/15.png)<br>
终止p2进程<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/16.png)<br>

（2）使用exit（1）<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/17.png)<br>
结果如下：<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/18.png)<br>
（3）段错误退出<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/19.png)<br>
结果如下：<br><br>
![input_txt](https://github.com/16281022/-_16281022/blob/master/20.png)<br>
