import random


try:
    count = 0
    while True:
        colors = random.randint(100, 1000)
        print(f'白って{colors}色あんねん')
        count += 1
except:
    pass
finally:
    print(f'{count} 人のアンミカ')
