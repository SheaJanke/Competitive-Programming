def simplify(arr, switchIndex):
    arr[switchIndex] = 1
    n = len(arr)
    if(switchIndex >= 2 and arr[switchIndex-1] == 0 and arr[switchIndex-2] == 1):
        arr = simplify(arr, switchIndex-1)
    if(switchIndex < n-2 and arr[switchIndex+1] == 0 and arr[switchIndex+2] == 1):
        arr = simplify(arr, switchIndex+1)
    return arr

def getAnswer(arr):
    answer = 0
    for i in range(len(arr)):
        if arr[i] == 0:
            newArr = simplify([] + arr, i)
            answer += getAnswer(newArr)
    return max(1, answer)



for j in range(12):
    print(getAnswer([0 for i in range(j)]))
