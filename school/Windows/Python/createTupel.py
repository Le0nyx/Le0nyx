"""
A tuple is an immutable sequence of elements, enclosed in parentheses ().
In this script, a tuple named 'person' is created with the elements "Max", "Mustermann", and 30.
The tuple is then concatenated with the element "1234567890" using the '+' operator.
Next, the tuple is converted to a list, and the third element (age) is incremented by 1.
Finally, the list is converted back to a tuple and printed.

Output:
("Max", "Mustermann", 31, "1234567890")
"""


# AA6
person = ("Max", "Mustermann", 30)
person = person + ("1234567890",)

person = list(person)
person[2] += 1
person = tuple(person)
print(person)

# AA7
person = {
    'first_name': "Max",
    'last_name': "Mustermann",
    'age': 30,
    'phone_number': "1234567890"
}

print("\n\n")
print(person['first_name'])
print(person['phone_number'])