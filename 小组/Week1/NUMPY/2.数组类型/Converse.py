import numpy as np

#类型转换

a = np.array([1.5, -   3], dtype = float)
print("浮点数组a为：", end = '')
print(a)

#asarray函数
#会直接改变b的元素类型
b = np.array([1, 2, 3])
print("asarray类型转换后：", end = '')
print(np.asarray(b, dtype = float))

#astype函数
#非引用机制，会返回一个新的数组
c = np.array([1, 2, 3])
print("astype类型转换：", end = '')
print(c.astype(float))
print("原数组不变：", end = '')
print(c)
