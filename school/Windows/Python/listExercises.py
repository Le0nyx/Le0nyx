int_list = [1, 2, 3, 4, 5000, 6, 7, 8, 9, 10, 300]
word_list = ["kiwi", "banana", "cherry", "apple", "date", "elderberry", "fig", "grape", "honeydew", "lemon"]

# AA1 Schreibe eine Python-Funktion, die das Maximum aus einer gegebenen Liste von Zahlen zur ̈uckgibt.
print("\n\n AA1------------------\n")
print(max(int_list))

# AA2 Schreibe eine Python-Funktion, die das Minimum aus einer gegebenen Liste von Zahlen zur ̈uckgibt.
print("\n\n AA2------------------\n")
print(min(int_list))

# AA3 Schreibe eine Python-Funktion, die eine gegebene Liste von Zahlen aufsteigend sortiert.
print("\n\n AA3------------------\n")
def sort_list(list):
    return sorted(list)
print(sort_list(int_list))

# AA4 Schreibe eine Python-Funktion, die eine gegebene Liste von Wörtern alphabetisch sortiert.
print("\n\n AA4------------------\n")
def sort_list(list):
    return sorted(list)
print(sort_list(word_list))

# AA5 Schreibe eine Python-Funktion, die eine gegebene Zeichenkette umkehrt.
print("\n\n AA5------------------\n")
print("Hello"[::-1])

# AA6 Schreibe eine Python-Funktion, die eine gegebene Zeichenkette in eine Liste von W ̈ortern auftrennt.
print("\n\n AA6------------------\n")
def split_string(string):
    return string.split()
print(split_string("Hello World"))

# AA7 Schreibe eine Python-Funktion, die eine gegebene Liste von Zahlen umkehrt.
print("\n\n AA7------------------\n")
def reverse_list(list):
    return list[::-1]
print(reverse_list(int_list))

# AA8 Schreibe eine Python-Funktion, die pr ̈uft, ob eine gegebene Zahl eine Primzahl ist.
print("\n\n AA8------------------\n")
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
print(is_prime(7))
print(is_prime(4))

# AA9 Schreibe eine Python-Funktion, die eine gegebene Liste von Zahlen auf ungerade Zahlen filtert.
print("\n\n AA9------------------\n")
def filter_odd_numbers(list):
    return [num for num in list if num % 2 != 0]
print(filter_odd_numbers(int_list))

# AA10 Schreibe eine Python-Funktion, die das n-te Fibonacci-Zahl berechnet.
print("\n\n AA10------------------\n")
def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a
print(fibonacci(10))

# AA11 Schreibe eine Python-Funktion, die eine gegebene Liste von Zahlen auf aufeinanderfolgende Zahlen pruft.
print("\n\n AA11------------------\n")
def is_consecutive(list):
    return sorted(list) == list
print([1, 2, 3, 2, 5])
print(is_consecutive([1, 2, 3, 2, 5]))

# AA12 Schreibe eine Python-Funktion, die eine gegebene Liste von Zahlen auf Duplikate pr ̈uft.
print("\n\n AA12------------------\n")
def has_duplicates(list):
    return len(list) != len(set(list))
print(has_duplicates([1, 2, 3, 4, 5, 5]))

# AA13 Schreibe eine Python-Funktion, die eine gegebene Liste von Zahlen auf Nullen filtert.
print("\n\n AA13------------------\n")
def filter_zeros(list):
    return [num for num in list if num != 0]
print(filter_zeros([0, 1, 2, 0, 3, 0, 4, 5, 6, 7, 8, 9, 0]))

# AA14 Schreibe eine Python-Funktion, die eine gegebene Liste von W ̈ortern auf Palindrome pr ̈uft.
print("\n\n AA14------------------\n")
def is_palindrome(string):
    return string == string[::-1]
print(is_palindrome("hello"))
print(is_palindrome("level"))

# AA15 Schreibe eine Python-Funktion, die eine gegebene Liste von Zahlen auf ihre quadratischen Wurzeln abbildet.
print("\n\n AA15------------------\n")
def square_root_list(list):
    return [num ** 0.5 for num in list]
print(int_list)
print(square_root_list(int_list))