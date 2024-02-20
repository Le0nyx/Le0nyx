# 1. Variablen erstellen
word1 = 'Python'
space = ' '
hyphen = '-'
word2 = 'Kurs'

# 2. 'Python - Kurs' ausgeben
print(word1 + space + hyphen + space + word2)
# 3. 'Python Python Python' ausgeben
print((word1 + space) * 3)
# 4. Die ersten drei Buchstaben von 'Python' ausgeben
print(word1[:3])
# 5. Die zweite Hälfte von 'Python' ausgeben
print(word1[len(word1)//2:])