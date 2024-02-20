name = input("Enter something: ")

if name.isdigit():
    number = int(name)
    result = number * 2
    print("Das Ergebnis ist:", result)
elif name.isalpha():
    length = len(name)
    print("Die Anzahl der Buchstaben ist:", length)
else:
    print("Fehler: Ungültige Eingabe")