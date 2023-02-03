import openpyxl

#define a function to get 2 lists as input and plot them in excel sheet
def tabulate_lists(list1, list2):
    workbook = openpyxl.Workbook()
    worksheet = workbook.active
    worksheet.append(["size of n", "time taken"])
    for i in range(len(list1)):
        worksheet.append([list1[i], float(list2[i])])
    workbook.save("tabulated_lists.xlsx")

#define a function to get 6 and tabulate them in pairs in excel sheet with gap inbtween pairs
# def tabulate_lists_6(list1, list2, list3, list4, list5, list6):
#     workbook = openpyxl.Workbook()
#     worksheet = workbook.active
#     worksheet.append(["size of n", "time taken", "size of n", "time taken", "size of n", "time taken"])
#     for i in range(len(list1)):
#         worksheet.append([list1[i], float(list2[i]), list3[i], float(list4[i]), list5[i], float(list6[i])])
#     workbook.save("tabulated_lists.xlsx")

def read_from_file():
    file = open("time.txt", "r")
    n = []
    time_taken = []
    for line in file:
        n.append(int(line.split()[0]))
        time_taken.append(line.split()[1])
    return n, time_taken


tabulate_lists(n, time_taken)


