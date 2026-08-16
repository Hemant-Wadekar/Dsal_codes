set1 = set()
set2 = set()

def Insert():
    a1 = int(input("\nEnter Number of elements to add in Set 1 :"))
    for i in range(a1):
        ele = int(input(f"Enter element {i+1} :"))
        set1.add(ele)
    print(set1)

    a2 = int(input("\nEnter Number of elements to add in Set 2 :"))
    for i in range(a2):
        ele = int(input(f"Enter element {i+1} :"))
        set2.add(ele)
    print(set2)


def Remove(): 
    print("Enter Set Number to Remove element : \n\t1.Set 1 \n\t2.Set 2")
    ch = int(input("Enter Choice:")) 
   
    if (ch == 1):
        a = int(input("Enter element to Remove :"))
        if a in set1:
            set1.remove(a)
        else:
            print(f"Element {a} not found in Set 1")
    elif(ch == 2):
        a = int(input("Enter element to Remove :"))
        if a in set2:
            set2.remove(a)
        else:
            print(f"Element {a} not found in Set 2")
    else:
        print("Invalid Choice")

def Size():
    print("Size of Set 1 is", len(set1))
    print("Size of Set 2 is", len(set2))

def Union():
    print("Union :", set1.union(set2))

def Intersection():
    print("Intersection :", set1.intersection(set2))

def Difference():
    print("Difference :", set2.difference(set1))

def Contains():
    a = int(input("Enter element you want to check: "))
    if a in set1 & set2: 
        print("set 1 and 2 contains the element ",a)
    elif a in set1: 
        print("set 1 contains the element ",a)
    elif a in set2:
        print("set 2 contains the element ",a)
    else:
        print("Element Not found in any Set")
    
def Subset():
    if set1.issubset(set2):
        print("Set 1 is a Subset of Set 2")
    else:
        print("Set 1 is not a Subset of Set 2")
    
def Display():
    print("Set 1 :", set1)
    print("Set 2 :", set2)


#main Program
while(1):
    print("\n\t************DSAL PRACTICAL NO.2 (A-4)************")
    print("\t****************SET OPERATIONS*******************")
    print("\t--------------------MENU-------------------------")

    print("\n\t1.Insert \t6.Difference \n\t2.Remove \t7.Contains \n\t3.Size \t\t8.Subset \n\t4.Union \t9.Display \n\t5.Intersection \t10.Exit")

    ch = int(input("Enter Your Choice (1-10) :"))
    
    if (ch == 1):
        Insert()
    elif (ch == 2):
        Remove()
    elif (ch == 3):
        Size()
    elif (ch == 4):
        Union()
    elif (ch == 5):
        Intersection()
    elif (ch == 6):
        Difference()
    elif (ch == 7):
        Contains()
    elif (ch == 8):
        Subset()
    elif (ch == 9):
        Display()
    elif (ch == 10):
        print("Exiting Program")
        break
    else:
        print("Invalid Choice")

    