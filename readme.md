-std=c++11

新建before.txt将汇编指令输进去。
编译运行pre.cpp
编译运行run.cpp
从out.txt中获取机器码。

before.txt中格式：

![1677941333783](image/readme/1677941333783.png)

![1677941342689](image/readme/1677941342689.png)

---

不区分大小写（pre中会全部处理成大写）
-------------------------------------

标号声明处必须单独占一行且紧跟:   标号和:中间不能带空格

如：

mikku:
MOV R2,R1

---

LAD 和 STA 和 JMP 和 BZC 指令需要按书本58页的格式显示的把M给出（按00,01,10,11的方式）

如：

STA 00 FFH,R2

---

指令前端不要有多余空格。
指令结束后那一行有啥都无所谓。

---

本汇编语言默认立即数均为16进制。末尾带不带H都行

---

pre程序是预处理汇编代码。去掉16进制的H和记录修改跳转标号的位置信息。返回修改的汇编代码。
run程序是汇编转机器码代码。

---

测试用例见文件夹
