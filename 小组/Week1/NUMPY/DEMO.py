import numpy as np

#1.创建一个1到10的数组，然后逆序输出
a1 = np.arange(1, 11)
a1 = -a1
a1 = np.sort(a1)
a1 = -a1
print(a1)


#2.创建一个长度为20的全1数组，然后变成一个4×5的二维矩阵并转置。
a2 = np.ones(20, int)
a2.shape = 4, 5
a2 = a2.transpose()
print(a2)


#3.创建一个3x3x3的随机数组。
a3 = np.random.random((3, 3, 3))
print(a3)


#4.从1到10中随机选取10个数，构成一个长度为10的数组，并将其排序。获取其最大值最小值，求和，求方差。
a4 = np.random.randint(1, 10, 10)
a4 = np.sort(a4)
print(np.max(a4))
print(np.min(a4))
print(np.sum(a4))
print(np.var(a4))


#5.从1到10中随机选取10个数，构成一个长度为10的数组，选出其中的奇数。
a5 = np.random.randint(1, 10, 10)
print(a5[np.where(a5 % 2 == 1)])


#6.生成0到100，差为5的一个等差数列，然后将数据类型转化为整数。
a6 = np.arange(0, 101, 5, dtype=int)
print(a6)


#7.从1到10中随机选取10个数，大于3和小于8的取负数。
a7 = np.random.randint(1, 10, 10)
a7[np.where(a7 > 3)] = -a7[np.where(a7 > 3)]
a7[np.where(a7 < 8)] = -a7[np.where(a7 < 8)]
print(a7)


#8.在数组[1, 2, 3, 4, 5]中相邻两个数字中间插入1个0。
a8 = np.array([1, 2, 3, 4, 5])
i = a8.size - 1
while i >= 1:
    a8 = np.insert(a8, i, 0,)
    i -= 1
print(a8)


#9.新建一个5乘5的随机二位数组，交换其中两行？比如交换第一二行。
a9 = np.random.randint(0, 100, 25)
a9.shape = 5, 5
b = a9[0]
a9[0] = a9[1]
a9[1] = b
print(a9)


#10.把一个10\*2的随机生成的笛卡尔坐标转换成极坐标。

#11.创建一个长度为10并且除了第五个值为1其余的值为2的向量。
#12.创建一个长度为10的随机向量，并求其累计和。
#13.将数组中的所有奇数替换成-1。
#14.构造两个4乘3的二维数组，按照3种方法进行连接？
#15.获取数组 a 和 b 中的共同项（索引位置相同，值也相同）(a = np.array([1,2,3,2,3,4,3,4,5,6])，b = np.array([7,2,10,2,7,4,9,4,9,8]))
#16.从数组 a 中提取 5 和 10 之间的所有项。a=np.array([7,2,10,2,7,4,9,4,9,8])
