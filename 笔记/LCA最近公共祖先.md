倍增

![image-20201029164857465](C:\Users\lighteningzhang\AppData\Roaming\Typora\typora-user-images\image-20201029164857465.png)

核心：	

$fa[j][k] = fa[fa[j][k - 1]][k - 1]$ 本质: $2^k = 2^{k - 1} + 2^{k - 1}$ 

eg.:

$fa[j][1] = fa[fa[j][0]][0] = f[t][0]$

$fa[j][2] = fa[fa[j][1]][1] = fa[fa[t][0]][1]$