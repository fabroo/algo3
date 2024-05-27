def prim(adj):
    Vt = ['0000']
    Xt = []
    for i in range(len(adj) - 1):
        min_e = None
        min_v = None
        for v in Vt:
            for vecino in adj[v]:
                if vecino[0] in Vt: continue
                if min_e == None or min_e[1] > vecino[1]:
                    min_e = vecino
                    min_v = vecino[0]
        
        Xt.append(min_e)
        Vt.append(min_v)
    return Vt, Xt

def dist(v, w):
    acc = 0
    for i in range(len(v)):
        c1, c2 = int(v[i]), int(w[i])
        diff = abs(c1 - c2)
        if diff <= 5:
            acc += diff
        else:
            acc += 10 - diff
    return acc

cases = int(input())
for k in range(cases):
    i = input()
    parsed = ['0000'] + i.split(' ')[1:]
    adj = {}

    for v in parsed:
        for w in parsed:
            if v == w: continue
            d = dist(v, w)
            if v not in adj:
                adj[v] = [(w, d)]
            else:
                adj[v].append((w, d))

    Vt, Xt = prim(adj)
    min_num = sum([e[1] for e in Xt])
    print(min_num)