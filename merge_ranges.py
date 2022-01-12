arr = [ [6,8], [1,9], [2,4], [4,7], [11, 13] ]




arr.sort()

result = []

result.append(arr[0])

for range in arr[1:]:
    a, b = result[-1]
    x, y = range

    # a        b     x b   y b

    #not merge
    if b < x:
        result.append(range)
    else:
        b = max(y, b)
        result[-1] = (a, b)

print(result)