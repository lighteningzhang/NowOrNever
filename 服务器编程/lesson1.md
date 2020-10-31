C/S模型:

优点： 

1. 协议选择灵活
2. 缓存数据

缺点：

			1. 对用户安全构威胁
   			2. 开发工作量大，调试困难

B/S模型：

优点：跨平台

## NAT映射表

把私有ip如192.168.0.1 映射为 公网ip

有一点疑惑是端口号怎么映射的？（不同进程都会进行映射？如qq微信，浏览器等）

## 打洞机制

公-公：直接访问

公-私：NAT映射

私-私：NAT映射，打洞

## socket--套接字

一个文件描述符指向两个缓冲区	

socket（伪文件）

IP地址：网络环境中标识一台主机

端口号：主机中唯一标识一个进程

IP + 端口号：在网络中唯一标识的一个进程

大端小端字节序的转换



ACK + 数字，是开区间还是闭区间

之所以四次挥手是允许半关闭状态

MTU/MSS？



高并发

SIGCHLD (内核调用？)

signal -- sigcation

**线程detach?**

线程分离detach



TCP数据报中 滑动窗口字段干啥的？

### 端口复用

## 多路IO转接

内核处理listen请求

select()

## select

## poll

1. 不再局限1024（改配置文件）
2. 监听、返回集合 分离
3. 搜索范围小

## Overview

![image-20201031204101183](C:\Users\lighteningzhang\AppData\Roaming\Typora\typora-user-images\image-20201031204101183.png)

![image-20201031204125558](C:\Users\lighteningzhang\AppData\Roaming\Typora\typora-user-images\image-20201031204125558.png)