import numpy as np

#多维数组及其属性

#生成二维数组（事实上传入的是以列表为元素的列表）
a = np.array([[0, 1, 2, 3], [4, 5, 6, 7]])
print("二维数组为：")
print(a)


#查看形状
#2行4列
print("数组形状为：", end = '')
print(a.shape)


#查看元素总个数
#
print("元素总个数为", end = '')
print(a.size)

#查看维数
print("元素维数为：", end = '')
print(a.ndim)