# Python: dynamic typing + closures + scope demo
def make_counter(start=0):
    count = start          # 'count' lives in the enclosing (closure) scope
    def increment(step=1):
        nonlocal count     # explicit keyword required to write to the outer variable
        count += step
        return count
    return increment

counter = make_counter(10)
print("counter():", counter())   # 11
print("counter():", counter())   # 12
print("counter(5):", counter(5)) # 17

# Dynamic typing: the same variable can hold different types at different times
value = 5
print("value:", value, type(value))
value = "five"
print("value:", value, type(value))
value = [5]
print("value:", value, type(value))

# Duck typing: no interface is declared, Python only checks behavior at call time
def describe_length(x):
    return len(x)  # works for anything with __len__, fails at runtime otherwise

print("len of list:", describe_length([1, 2, 3]))
print("len of str:", describe_length("hello"))
try:
    describe_length(42)   # int has no __len__: raises at runtime, not compile time
except TypeError as e:
    print("TypeError caught:", e)
