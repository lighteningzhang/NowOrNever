## 字符串相关

1. 循环移动的简便操作，向左循环移动b位：s = s.substr(b) + s.substr(0, b), 向右循环移动：s = s.substr(n - b) + s.substr(0, n - b)

   

   字符串找循环位(顺时针，逆时针)与当前位的差, j在后，i在前, 逆时针：i - j, 顺时针 n - (i - j)，统一 abs (i - j), n - abs(i - j)

   

2. 奇数位操作: 

   ```c++
   for (int i = 1; i < n; i += 2)
   ```

   偶数位操作：

   ```c++
   for (int i = 0; i < n; i += 2)
   ```


## 排序

1. 桶排序

   明天明天看看 	

   https://www.acwing.com/solution/content/4337/