import sys, heapq

input = sys.stdin.readline

type, k = map(int,input().split())
n = int(input().strip())
arr = [int(input().strip()) for _ in range(n)]

def insertion():
    total_cnt = 0
    for i in range(1, k+1):
        cnt = 0
        for j in range(i):
            if arr[i] < arr[j]:
                cnt+=1
        if cnt != i:
            cnt += 1
        total_cnt += cnt
    return total_cnt

def selection():
    for i in range(0,k):
        min_ = arr[i]
        idx = i
        for j in range(i+1,n):
            if min_ > arr[j]:
                min_ = arr[j]
                idx = j
        arr[i], arr[idx] = arr[idx], arr[i]

    for i in range(n):
        print(arr[i])
    return 

def heapsort():
    heapq.heapify(arr)
    
    for _ in range(k):
        res = heapq.heappop(arr)
        heapq.heapify(arr)

    for i in range(len(arr)):
        print(arr[i])
    return 

def quick(arr,low,high,k):
    if low < high and k > 0:
        pi = partition(arr,low,high)
        k -= 1
        quick(arr,low,pi-1,k)
        quick(arr,pi+1,high,k)
    return

def partition(arr, low, high):
    pivot = arr[low]
    l = low + 1
    r = high
    while True:
        while l <= r and arr[l] <= pivot:
            l += 1
        while l <= r and arr[r] >= pivot:
            r -= 1
        if l <= r:
            arr[l], arr[r] = arr[r], arr[l]
            l+=1
            r-=1
        else:
            break
    arr[low], arr[r] = arr[r], arr[low]
    return r

if type == 1:
    print(insertion())
elif type == 2:
    selection()
elif type == 3:
    heapsort()
elif type == 4:
    quick(arr,0,n-1,k)
    for i in arr:
        print(i)