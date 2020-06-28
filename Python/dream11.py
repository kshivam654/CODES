import random
l = []
for _ in range(11):
    l = []
    while(len(l) < 11):
        r = random.randint(1,21)
        if r not in l:
            l.append(r)
    print(l)