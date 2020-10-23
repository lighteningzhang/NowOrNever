## 字符串相关

1. 循环移动的简便操作，向左循环移动b位：s = s.substr(b) + s.substr(0, b), 向右循环移动：s = s.substr(n - b) + s.substr(0, n - b)

2. 奇数位操作: 

   ```c++
   for (int i = 1; i < n; i += 2)
   ```

   偶数位操作：

   ```c++
   for (int i = 0; i < n; i += 2)
   ```

   

   