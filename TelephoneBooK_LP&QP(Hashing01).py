size = int(input("Enter the table size : "))
n= int (input("\nENter the no. of records to be inserted : "))
hash_table = [-1]*size

def linear_probing(telephone_no):
    for i in range(size):
        index = (telephone_no + i)% size
        if(hash_table[index] == -1):
            hash_table[index] = (telephone_no)
            print("\nRecord Inserted")
            break

        else :
            print("table is full ! recod cannot be inserted")


def Quadratic(telephone_no):
    i = 0
    for i in range(size):
        index = (telephone_no % size + i * i ) % size
        if(hash_table[index] == -1):
            hash_table[index] = (telephone_no)
            print("Record Inserted")
            break

        else :
            i = i + 1
            if(i == size):
                print(" Eleemnet cannot be inserted")

def search(telephone_no):
    count = 1
    for i in range(size):
        index = (telephone_no + i) % size

        if(hash_table[index] == telephone_no):
            print("element found at index " , index)
            print("Required record : " , hash_table[index])

            print("No of comparisons =" , count)
            break
        elif (hash_table[index] != telephone_no):
            i = i + 1 
            count = count + 1
    
    else :
        print("record not found")


def display() :
    print("Index Telephone number")
    for i in range(size):
        if(hash_table[i] != -1):
            print(i , " " , hash_table[i])



while(True):
    choice = int(input("\nEnter the record usign linear probing \n2. Insert record using wuadratic probing \n3.Search \n4.Display record \n5.exit"))

    if(choice == 1) :
        for i in range(n) :
            teleno = int(input("Enter the telephone_no : "))
            linear_probing(teleno)
    
    elif(choice == 2):
        for i in range(n) :
            teleno = int(input("Enter the telephone_no : "))
            Quadratic(teleno)

    elif (choice == 3):
        tele_num = int(input("Enter the number to be searched : "))
        search(tele_num)
    
    if(choice == 4 ):
        display()

    else:
        print("Progam exited")
