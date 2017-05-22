# -*- coding:utf-8 -*-
_author_ = 'PC'
import copy
import random
import  time
def loading( res, pack, weight, value, pos):
    global  count
    global max

    count += 1
    if weight <= C:
        if value >= max:
            max = value
            res.append( (copy.deepcopy(pack),weight,value))
            # print "PACK = ", pack , "weight = ",weight
        for i in  range(pos, len(goods)):
            pack.append(i)
            loading(res, pack, weight+goods[i][1], value + goods[i][0], i+1 )
            pack.pop(-1)


def select_res(res):
    global max
    final_res = []
    for i in range(len(res))[::-1]:
        if  res[i][2] < max:
            break;
        final_res.append( res[i])
    return final_res


def loading_stack(goods,res, C):

    pack = []
    pack.append(0)
    value = goods[0][0]
    weight = goods[0][1]
    pos = 0
    layer = 0
    max = value
    while( len(pack) > 0):
        if weight + goods[pos+1][1] < C:
            pack.append(++pos)
            weight += goods[pos][1]
            value += goods[pos][0]
        else:
            pos += 1

        if value > max:
            max = value
            print pack
            res.append( copy.deepcopy(pack) )

        if pos == len(goods):
            pos = pack.pop(-1)



def Backtracking(goods,C):
    n = len(goods)
    pack = [0 for i in range(n)]
    weight = 0
    value = 0
    k  = 0
    max = 0

    while k >= 0:

        while k < n :
            # print  "pack = ", pack, "value = ", value, "weight = ", weight, "k = ", k
            if weight + goods[k][1] < C:
                pack[k] += 1
                value += goods[k][0]
                weight += goods[k][1]
            k += 1
        # print  "pack = ", pack, "value = ", value, "weight = ", weight, "k = ", k
        if weight > max:
            max = weight
            res.append(pack)
        if k >= n: k -= 1
        while pack[k] != 1 and k >= 0:
            k = k - 1
        if k >= 0:
            pack[k] = 0
            value -= goods[k][0]
            weight -= goods[k][1]
            k += 1












count = 0
# (价值,重量)
all=[]
goods=[]
for i2 in range(0,5):
    goods=[]
    for i in range(0,50):
        w=random.randint(1,40/3)
        v=random.randint(1,40/3)
        g=[]
        g.append(w)
        g.append(v)
        goods.append(g)
    all.append(goods)
# goods = [ [1,2], (3,3), (5,4), (9,7), (4,2), (8,6), (10,12), (3,1), (1,1), (13,11), (2,2), (4,5), (5,7), (6,5), (7,7) ]
# goods = [ (1,2), (3,3), (5,4), (4,2)]
res = []
C = 40
weight = 0
value = 0
pos = 0
pack = []
max = 0

for i in all:
    print "开始:"+time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
    Backtracking(i,40)
    print "结束:"+time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
    print "\n"
# loading_stack(goods,res, 10)
# loading(res, pack, weight, value,  pos)
# final_res =  select_res(res)
# # print final_res
# print  "count = ",count
# for i in final_res:
#     print i

