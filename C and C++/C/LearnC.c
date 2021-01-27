#include <stdio.ch>

void main()
{
	int a;
	/*a decimal int constant cannot have "," "." " " and "-" in them although
	they can start with "-"
	
	a octal int constant has to start with 0 to identify it as an octal contant
	
	a hexadecimal constant .must begin with either 0x or 0X and followed by numbers 
	from 0-9 and a-f (not case-sensative)
	
	Qualifiers: not case sensative:
	u for unsigned ex: 949u
	l for long ex: 0xFFFl
	ul for unsigned long ex: 0xffefeul
	
	floating point constat is a base 10 number with either a decimal or an exponent:
	exponent has to be a integer
	cannot have commas in the number
	
	Escape sequences:
	bell(alert): /a
	backspace
	horz. tab
	vert. tab
	new line (line feed)
	form feed
	carriage return
	quotation mark
	apostrophe
	question mark
	backslash
	null
	
	