import array

arr = array.array('i', [1, 2, 6])

print("The newly created array is: ", end='')
for i in range(0, 3):
    print(arr[i], end=' ')
print()

arr.append(4)
print("Array after new element appended: ", end='')
for i in range(0, 4):
    print(arr[i], end=' ')
print()

arr.insert(2, 1)
print("Array after new element replaced: ", end='')
for i in range(0, 5):
    print(arr[i], end=' ')
print()

index = 3
print("Element popped at index:{1} is {0}.".format(arr.pop(index), index))
print("Array after element popped: ", end='')
for i in range(0, 4):
    print(arr[i], end=' ')
print()

element = 1
arr.remove(element)
print("First occurance of element {} removed.".format(element))
print("Array after element removed: ", end='')
for i in range(0, 3):
    print(arr[i], end=' ')
print()

arr.reverse()
print("Array after reverse: ", end='')
for i in range(0, 3):
    print(arr[i], end=' ')
print()

