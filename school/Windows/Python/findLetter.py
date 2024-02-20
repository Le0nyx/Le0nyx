text = 'Hier steht ein beliebiger Text.'

# 1. Count the number of occurrences of the letter 'e'
count_e = text.count('e')
print(f"The letter 'e' appears {count_e} times in the text.")

# 2. Print the first word in uppercase and replace 'i' with '1' in the remaining text
first_word = text.split()[0].upper()
remaining_text = text.split()[1:]
modified_text = ' '.join(remaining_text).replace('i', '1')
print(f"{first_word} {modified_text}")
