import numpy as np

#数组连接

#连接的数组要用（）包括到一个元组里
#除了给定的轴外，这些数组其他轴的长度必须是一样的

x = np.array([[1, 2, 3], [4, 5, 6]])
y = np.array([[7, 8, 9], [10, 11, 12]])

print("矩阵x为：")
print(x)
print("矩阵y为：")
print(y)

##############################################

#沿第一维连接
#第二参数axis默认为列（0）
z1 = np.concatenate((x, y))
print("按列拼接后的矩阵为：")
print(z1)

#沿第二维连接
z2 = np.concatenate((x, y), axis = 1)
print("按行拼接后的矩阵为：")
print(z2)

#沿第三维连接（concatenate不提供该功能）（用array）
z3 = np.array((x, y))
print("沿第三维拼接后的矩阵为：")
print(z3)

##############################################

#使用三种对应函数
#vstack
#hstack
#dstack

v = np.vstack((x, y))
h = np.hstack((x, y))
d = np.dstack((x, y))

print("按列拼接后的矩阵为：")
print(v)
print("按行拼接后的矩阵为：")
print(h)
print("沿第三维拼接后的矩阵为：")
print(d)