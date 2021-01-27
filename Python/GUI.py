from tkinter import *
from tkcalendar import Calendar, DateEntry

f1 = ("Helvetica", 12)

root = Tk(className = "Sales Form")
root.geometry("500x600")
cols = ["Sales Person", "Company/Firm", "Address", "Contact Person", 
"Contact No.", "Contact Date", "Next Follow Up Date", "Last Meeting Date",
"Conversion Chances", "Demo Status", "Demo Date", "Lead Status", "Remarks"]

for i in range(len(cols)):
	Label(root, text = cols[i], font = f1).grid(row = i+1, sticky = W)

entries = []
for i in range(len(cols)):
	if (i==5 or i==6 or i==7 or i==10):
		entries.append(DateEntry(root, bg='darkblue',fg='white', borderwidth=2, font = f1))
	elif (i==len(cols)-1):
		entries.append(Text(root, font = f1, height = 10, width = 25))
	else:
		entries.append(Entry(root, font = f1))
	entries[i].grid(row = i+1, column = 1, sticky = W)

	
def display():
	disp = Tk(className = "Sales Form display")
	disp.geometry("500x400")
	for i in range(len(cols)):
		Label(disp, text = cols[i] + ':', font = f1).grid(row = i+1, sticky = W)
		if i==len(cols)-1:
			entry = entries[i].get('1.0', END)
		else:
			entry = entries[i].get()
		if entry == "":
			entry = "N/A"
		Label(disp, text = entry, font = f1).grid(row = i+1, column = 1, sticky = W)
	root.destroy()

close = Button(root, text = "Submit", bg = "Blue", width = 20, command = display, font = f1)
close.grid(row = len(cols)+1)
mainloop()