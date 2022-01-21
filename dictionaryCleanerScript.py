import csv

list = []

#CHANGE PATH TO FLIE

with open('path to existing file', 'r') as csvfile:
	csvreader = csv.reader(csvfile, delimiter=',') 
	for row in csvreader:
		list.append(row[0])

#CHANGE PATH TO FLIE

with open("<path to new file>", 'w') as newfile:
	for word in list:
		if len(word) == 1:
			continue
		newfile.write(word + '\n')
