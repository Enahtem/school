
def binary_search_deluxe(arr, val):
    left = 0
    right = len(arr) - 1
    leftmost = -1
    rightmost = -1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] < val:
            left = mid + 1
        else:
            right = mid - 1
            leftmost = mid


    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] > val:
            right = mid - 1
        else:
            left = mid+1
            rightmost=mid

    return leftmost, rightmost

print(binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 12))
