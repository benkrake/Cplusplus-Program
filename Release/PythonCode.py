import re
import string

#Count and print items and their associated quantities
def ListItemQuantities():
    #Create empty dictionary to input items read from file and open file
    itemDict = dict()
    file = open("Data.txt", "r")

    #for loop iterates through each line in file
    for line in file:
        line = line.strip()
        items = line.split(" ")
        #for loop iterates through each item after line.split(" ")
        for item in items:
            #if the current item in loop exists in itemDict, add 1 to the value for that key, else item value is set to 1
            if item in itemDict:
                itemDict[item] = itemDict[item] + 1
            else:
                itemDict[item] = 1
    #for loop iterates over each key in itemDict and prints the formatted key value pair
    for key in list(itemDict.keys()):
        print(key + ":", itemDict[key])
    file.close()


#Return value for number of specific item found in file
def ListSpecificItem(item):
    #Open file read only
    file = open("Data.txt", "r")
    info = file.read()
    #Count the quantity of the item passed from userInput in C++ and store value as instances for return
    instances = info.count(item)
    file.close()
    return instances;


#Creates file holding item and quantity pairs
def CreateQuantityFile():
    #Create empty dictionary to input items read from file and open file
    itemDict = dict()
    file = open("Data.txt", "r")

    #for loop iterates through each line in file
    for line in file:
        line = line.strip()
        items = line.split(" ")
        #for loop iterates through each item after line.split(" ")
        for item in items:
            #if the current item in loop exists in itemDict, add 1 to the value for that key, else item value is set to 1
            if item in itemDict:
                itemDict[item] = itemDict[item] + 1
            else:
                itemDict[item] = 1
    #for loop iterates over each key in itemDict and prints the formatted key value pair
    file.close()

    #Create new frequency.dat file with key value pairs from dictionary
    file = open("frequency.dat", "w")
    for key in list(itemDict.keys()):
        file.write('%s %s\n' % (key, itemDict[key]))
    file.close()