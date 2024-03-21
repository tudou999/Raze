import numpy as np

#数组中所有数的类型相同
a = np.array([1, 2, 3, 4]);
b = np.array([2, 3, 4, 5]);

#生成全是0的数组
#默认给浮点数
c = np.zeros(4)

#生成全是1的数组
#dtype用于自己定义数据类型
d = np.ones(4, dtype = int);

#fill将所有元素修改为同一指定数字
#如果fill的数据类型跟原有类型不同，则fill自动转换为原有类型
e = np.array([1, 2, 3, 4]);
e.fill(5)

#如果一定要fill的类型，就先将原有数组的元素进行强制类型转换
f = np.array([1, 2, 3, 4]);
f = f.astype(float)
f.fill(2.5)

#生成整数序列
#不包括10，生成10之前的
#第三参数为步长，默认为1
g = np.arange(1, 10, 2)

#生成等差数列
#包括10，第三参数为元素个数
h = np.linspace(1, 10, 10)

#生成0到1之间的随机数
#括号内为元素个数
i = np.random.rand(10)
#若要服从标准正态分布
k = np.random.randn(10)
#生成随机整数
#包括10，第三个参数为元素个数
l = np.random.randint(1, 10, 10)

print(a + b)
print(c)
print(d)
print(e)
print(f)
print(g)
print(h)
print(i)
print(k)

