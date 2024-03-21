import numpy as np

##电影名称
mv_name = ["肖申克的救赎", "控方证人", "美丽人生", "阿甘正传", "霸王别姬", "泰坦尼克号", "辛德勒的名单", "这个杀手不太冷", "疯狂动物城", "海豚湾"]

##评分人数
mv_num = np.array([692795, 42995, 327855, 580897, 478523, 157074, 306904, 662552, 284652, 159302])

##评分
mv_score = np.array([9.6, 9.5, 9.5, 9.4, 9.4, 9.4, 9.4, 9.3, 9.3, 9.3])

##电影时长（分钟）
mv_length = np.array([142, 116, 116, 142, 171, 194, 195, 133, 109, 92])

##############################################

#数组排序

#sort函数
print("将评分人数从少到多进行排序：", end = '')
print(np.sort(mv_num))

#argsort函数
#返回从小到大的排列在在数组中的索引位置
print("从小到大的排列在在数组中的索引位置：", end = '')
order = np.argsort(mv_num)
print(order)

#评分人数最少/最多的电影名称
#order[0]表示评分人数最少的电影的索引
print("评分人数最少的电影名称为：", end = '')
print(mv_name[order[0]])
#order[-1]表示评分人数最少的电影的索引
print("评分人数最多的电影名称为：", end = '')
print(mv_name[order[-1]])

##############################################

#求和
print("评分人数之和为：")
print(np.sum(mv_num))
print(mv_num.sum())

#求极值
print("电影放映时长最大值为：", end = '')
print(np.max(mv_length))
print("电影评分最小值为：", end = '')
print(mv_score.min())

#求均值
print("电影时长的均值为：", end = '')
print(np.mean(mv_length))

#标准差
print("电影时长的标准差为：", end = '')
print(np.std(mv_length))

#方差
print("电影时长的方差为：", end = '')
print(np.var(mv_length))

#相关系数矩阵
#求两个变量有没有相关性
print("评分与市场的相关系数矩阵为：")
print(np.cov(mv_score, mv_length))