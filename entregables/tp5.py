def solve():
    oferta_demanda = [int(x) for x in input().split(' ')]

    work_units = 0
    for i in range(len(oferta_demanda) - 1):
        work_units += abs(oferta_demanda[i])
        oferta_demanda[i + 1] += oferta_demanda[i]
    return work_units


while True:
    inhabitants = int(input())
    
    if inhabitants == 0:
        break

    sol = solve()
    print(sol)
