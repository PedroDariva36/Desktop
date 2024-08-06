def can_transform(a, b):
    n = len(a)
    m = len(a[0])
    
    total_difference = 0
    
    for i in range(n):
        for j in range(m):
            total_difference += (b[i][j] - a[i][j]) % 3
    
    return total_difference % 3 == 0

# Example usage:
a = [
    [1,1,1],
    [1,1,1],
    [1,1,1]
]
b = [
    [0, 0 ,0],
    [0, 0 ,0],
    [0, 0 ,0],
]
a = [
    [0, 0,0,0,0,0,0],
    [0, 0,0,0,0,0,0]
]
b = [
    [2, 2, 2, 0, 1, 1, 1],
    [0, 1, 1, 1, 2, 2, 2]
]

print(can_transform(a, b))
