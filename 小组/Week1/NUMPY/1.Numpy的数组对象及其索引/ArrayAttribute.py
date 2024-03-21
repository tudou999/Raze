import numpy as np

#数组属性

a = np.array([1, 2, 3, 4]);

#查看类型
print(type(a))
#查看元素类型
print(a.dtype)

#查看形状，会返回一个元组，每个元素代表这一维的元素个数
print(a.shape)

#查看数组里面元素的个数
print(a.size)

#查看数组的维度
print(a.ndim)

