import matplotlib.pyplot as plt
from collections import Counter

with open('Pass.txt', 'r') as file:
    lines = file.readlines()

lines = [line.strip() for line in lines if line.strip()]

frequency = Counter(lines)
sorted_frequency = sorted(frequency.items(), key = lambda x:x[1], reverse = True)

labels, counts = zip(*sorted_frequency)

plt.bar(labels, counts)
plt.xlabel('Инструкции')
plt.ylabel('Частота')
plt.xticks(rotation=65, ha='right')
plt.figure(figsize=(12,12))
plt.tight_layout()
plt.show()