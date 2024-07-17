from bisect import bisect_left

# This sorted list will be used for the bisect operations
sorted_list = [7 ,3 ,5 ,3 ,6 ,2 ,9, 8]

# This value will be inserted into the sorted list
value = 5

# Find the insertion point for 5 to maintain sorted order
i = bisect_left(sorted_list, value)

print(f"The rightmost index to insert, so list remains sorted is: {i}")