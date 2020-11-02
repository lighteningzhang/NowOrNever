### 模板串

```c++
f[0][0] = true
for (int i = 0; i < n; i ++) {
    for (int j = 0; j <= i; j ++) {
        if (s[i] == s[j]) {
            if (j + 1 > i - 1 || f[j + 1][i - 1])
	        	f[j][i] = true;
        }
    }
}
```

