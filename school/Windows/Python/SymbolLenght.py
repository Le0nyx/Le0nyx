def summe_zahlen(zahlen):
    summe = 0
    for zahl in zahlen:
        summe = summe + int(zahl)  # Convert the input to an integer
    return summe

zahlenfolge = []
eingabe = ""
while eingabe != "q":
    eingabe = input("Geben Sie eine Zahl ein (q zum Beenden): ")
    if eingabe.isdigit():
        zahlenfolge.append(eingabe)
    elif eingabe == "q":
        result = summe_zahlen(zahlenfolge)
        print("Die Summe der eingegebenen Zahlen ist: ", result)
    else:
        print("Fehler: Ungültige Eingabe")