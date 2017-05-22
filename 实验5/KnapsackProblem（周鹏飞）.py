# -*- coding:utf-8 -*-
_author_ = 'PC'
import copy
import math
import time
import random
count = 0
max = 0

def loading(goods, res, pack, weight, value, pos, c):
    global  count
    global max

    count += 1
    if weight <= c:
        if value >= max:
            max = value
            res.append( (copy.deepcopy(pack),weight,value))
            # print "PACK = ", pack , "weight = ",weight
        for i in  range(pos, len(goods)):
            pack.append(i)
            loading(goods, res, pack, weight+goods[i][1], value + goods[i][0], i+1, c )
            pack.pop(-1)


def select_res(res):
    global max
    final_res = []
    for i in range(len(res))[::-1]:
        if  res[i][2] < max:
            break;
        final_res.append( res[i])
    return final_res


def Backtracking(goods,c):

    n = len(goods)
    res = []
    pack = [0 for i in range(n)]
    weight = 0
    value = 0
    k  = 0
    max = 0
    count = 0
    while k >= 0:
        while k < n :
            count += 1
            # print  "pack = ", pack, "value = ", value, "weight = ", weight, "k = ", k
            if weight + goods[k][1] <= c:
                pack[k] += 1
                value += goods[k][0]
                weight += goods[k][1]
            k += 1
        # print  "pack = ", pack, "value = ", value, "weight = ", weight, "k = ", k
        if value >= max:
            max = value
            res.append( (copy.deepcopy( pack ),weight,value) )

        if k >= n: k -= 1

        while pack[k] != 1 and k >= 0:
            k = k - 1

        if k >= 0:
            pack[k] = 0
            value -= goods[k][0]
            weight -= goods[k][1]
            k += 1
    # print "count = ",count,"n = ",len(goods)
    return res,max









if __name__ == '__main__':
    # (价值,重量)
    # goods = [ (1,2), (3,3), (5,4), (9,7), (4,2), (8,6), (10,12), (3,1), (1,1), (13,11), (2,2), (4,5), (5,7), (6,5), (7,7) ]
    all = []
    goods = []
    for i2 in range(0, 5):
        goods=[]
        for i in range(0, 50):
            w = random.randint(1, 40/2)
            v = random.randint(1, 40/2)
            g = []
            g.append(w)
            g.append(v)
            goods.append(g)
        all.append(goods)
    # goods = [ (1,2), (3,3), (5,4), (9,7)]
    res = []
    C = 40
    max = 0
    for i in all:
        print i
        print "C = ",C," number of goods = ",len(i)
        time1 = time.time()
        # print "goods = ",goods
        res, max =  Backtracking(i,C)
        final_res =  select_res(res)
        # print "res = ", final_res, "numberOfres = ",len(final_res)
        time2 = time.time()
        print "非递归耗时 = ",time2 - time1


        weight = 0
        value = 0
        pos = 0
        pack = []
        res = []
        count = 0

        # print "goods = ",goods
        time3 = time.time()
        loading(i,res, pack, weight, value,  pos, C)
        final_res =  select_res(res)
        time4 = time.time()
        print "递归耗时 = ", time4 - time3
        #
        # print  "count = ",count,"res = ",final_res, "numberOfres = ",len(final_res)
        # for i in final_res:
        #     print i

