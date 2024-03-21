import numpy as np

#where语句

#一维数组
a = np.array([0, 12, 5, 20])

#判断a中元素是否大于10
print("a中元素是否大于10：", end = '')
print(a > 10)

#返回a中元素大于10的索引位置
#where返回的是一个元组，元组中的数字表示索引位置
print("a中元素大于10的位置", end = '')
print(np.where(a > 10))

#也可以直接用数组操作
print("a中大于10的元素：")
print(a[a > 10])
#也可以用where
print(a[np.where(a > 10)])