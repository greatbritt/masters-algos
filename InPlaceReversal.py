# The following program produces an in-place reversal of a set of ints

ints = [1, 2, 3, 4, 5]

# Reverse the order of the ints
ints.reverse()

# Print content of ints to the console

print(ints)

# The time complexity of the reverse() method is O(n) where n is the number of elements in the array

# The space complexity of the reverse() method is O(1)
# This method reverses the array in-place without creating any new data structures.
# It achieves this by swapping elements from the beginning and end of the list until they meet in the middle.

import time


def track_runtime(ints):
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        result = ints(*args, **kwargs)
        end_time = time.perf_counter()
        print(f"Function '{ints.__name__}' took {end_time - start_time} seconds.")
        return result

    return wrapper


@track_runtime
def my_function():
    time.sleep(2)
    print("Function completed.")


my_function()

