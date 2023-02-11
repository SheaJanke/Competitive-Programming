n, s = map(int, input().split())
allVals = []
for i in range(n):
    name, val = input().split()
    allVals.append((int(val), name))
sortedVals = sorted(allVals)
sortedVals.reverse()
answer = []
total = 0
for val, name in sortedVals:
    if(total + val <= s):
        answer.append(name)
        total += val
if total == s:
    print(len(answer))
    print("\n".join(answer))
else:
    print(0)
