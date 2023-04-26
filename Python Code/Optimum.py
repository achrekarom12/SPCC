op = [{'l': '', 'r': ''} for _ in range(10)]
pr = [{'l': '', 'r': ''} for _ in range(10)]

n = int(input("Enter the Number of Values:"))
for i in range(n):
    op[i]['l'] = input("left: ")
    op[i]['r'] = input("right: ")

print("Intermediate Code")
for i in range(n):
    print(f"{op[i]['l']}={op[i]['r']}")

z = 0
for i in range(n-1):
    temp = op[i]['l']
    for j in range(n):
        if temp in op[j]['r']:
            pr[z]['l'] = op[i]['l']
            pr[z]['r'] = op[i]['r']
            z += 1
            break

pr[z]['l'] = op[n-1]['l']
pr[z]['r'] = op[n-1]['r']
z += 1

print("\nAfter Dead Code Elimination")
for k in range(z):
    print(f"{pr[k]['l']}\t={pr[k]['r']}")

for m in range(z):
    tem = pr[m]['r']
    for j in range(m+1, z):
        if pr[j]['r'] in tem:
            t = pr[j]['l']
            pr[j]['l'] = pr[m]['l']
            for i in range(z):
                if t in pr[i]['r']:
                    a = pr[i]['r'].index(t)
                    pr[i]['r'] = pr[i]['r'][:a] + pr[m]['l'] + pr[i]['r'][a+1:]

print("Eliminate Common Expression")
for i in range(z):
    print(f"{pr[i]['l']}\t={pr[i]['r']}")

for i in range(z):
    for j in range(i+1, z):
        if pr[i]['l'] == pr[j]['l'] and pr[i]['r'] == pr[j]['r']:
            pr[i]['l'] = ''

print("Optimized Code")
for i in range(z):
    if pr[i]['l'] != '':
        print(f"{pr[i]['l']}={pr[i]['r']}")
