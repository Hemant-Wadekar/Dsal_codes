n = int(input("Enter no. of clients: "))
phone = []

for i in range(n):
    phone.append(int(input(f"Enter Number for client {i+1}: ")))

def print_hash(ht):
    for i in range(len(ht)):
        if(i != -1):
            print(f"{i} --> \t{ht[i]}")
        else:
            print(f"{i} --> \t-1")

def linear(m, ht):
    print("\nLinear")
    for n in phone:
        h = n % m
        # Collision check
        while(ht[h] != -1):
            h += 1
            if h == m: 
                h = 0
        ht[h] = n
    print_hash(ht)

def quadratic(m, ht):
    print("Quadratic")
    for n in phone:
        h = n % m
        i = 0
        # Collision check with quadratic probing
        while(ht[h] != -1):
            i += 1
            h = (n + (i * i)) % m  # Quadratic probing
        ht[h] = n
    print_hash(ht)

def double_hash(m, ht):
    print("Double Hashing")

    # Hash function 1
    def hash1(n):
        return n % m

    # Hash function 2
    def hash2(n):
        return 1 + (n % (m - 1))

    for n in phone:
        h1 = hash1(n)
        h2 = hash2(n)

        # Collision check using double hashing
        i = 0
        h = (h1 + i * h2) % m
        while(ht[h] != -1):
            i += 1
            h = (h1 + i * h2) % m

        ht[h] = n

    print_hash(ht)

m = int(input("\nEnter size of table: "))

while True:
    print("\n******** DSAL Practical 1 (A4) *********")
    print("*************** MENU ***************")
    ht = [-1] * m  
    print("\n1. Linear")
    print("2. Quadratic")
    print("3. Double Hash")
    print("4. Exit")
    ch = int(input("Enter Choice: "))

    if(ch == 1):
        linear(m, ht)
    elif(ch == 2):
        quadratic(m, ht)
    elif(ch == 3):
        double_hash(m, ht)
    elif(ch == 4):
        break
    else:
        print("Invalid Choice. Please Try Again.")

