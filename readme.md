## 实验要求:
1.定义一个用于存放整型数据的单链表，编程实现单链表的以下操作：
（1）置空MakeEmpty（）
（2）求长度Length（） 
（3）插入Insert（x，i）： 将x插入到第i个结点（不含头结点）之后； 
（4）删除Delete（x）：删除链表中值为x的结点，成功返回1，否则返回0； 
（5）删除 ReMove（i）：删除链表中第i个结点，成功返回1，否则返回0； 
（6）判断一个元素是否在链表中Find（x）：在链表中查找数值为x的结点，成功返回1，否则返回0；
（7）实现单链表数据的排序（升序或降序均可）；
（8）实现单链表数据的显示输出。
2.设计一个菜单，调用上述要求的所有功能并输出结果。
## 说明:
### 链表的定义
    本次实验使用的链表选用的结构类型出自于《数据结构（c语言版 第二版）》，即对于每链表
    都由节点(node)组成，节点之间由指针(pointer)连接。每个节点都存在两个域:数据域--存储具体数据;链域--存储下一个节点的指针。每个链表都必须具有一个头指针(head),头指针指向头节点,头节点不存储数据,即数据域不被赋值,头节点指向首元节点,从首元节点存储第一个数据。
### 实验的环境
    gcc:
        gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
    windows:
        win10/WindowsAPI
### 功能
    实现链表操作