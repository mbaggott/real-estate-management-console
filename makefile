#############################################################################
# CPT323      - Assignment #1 - Real Estate Project
# Object Oriented Programming in C++
# Author           : Michael Baggott
# Student Number     : s3439668
# Start up code provided by Robert McQuillan - robert.mcquillan@rmit.edu.au
#############################################################################

all: testDriver.o user_interface.o staff.o sales_staff.o rentals_staff.o property.o residential.o rentals.o sales.o commercial.o res_rentals.o res_sales.o com_rentals.o com_sales.o staff_container.o property_container.o map_container.o utility1.o
	g++ -o assign2 testDriver.o user_interface.o staff.o sales_staff.o rentals_staff.o property.o residential.o rentals.o sales.o commercial.o res_rentals.o res_sales.o com_rentals.o com_sales.o staff_container.o property_container.o map_container.o utility1.o
	
testDriver.o: testDriver.cpp
	g++ -Wall -ansi -pedantic -g -std=c++11 -c testDriver.cpp

user_interface.o: user_interface.cpp user_interface.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c user_interface.cpp
	
staff.o: staff.cpp staff.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c staff.cpp
	
sales_staff.o: sales_staff.cpp sales_staff.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c sales_staff.cpp
	
rentals_staff.o: rentals_staff.cpp rentals_staff.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c rentals_staff.cpp
	
property.o: property.cpp property.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c property.cpp
	
residential.o: residential.cpp residential.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c residential.cpp	

rentals.o: rentals.cpp rentals.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c rentals.cpp	

sales.o: sales.cpp sales.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c sales.cpp	

commercial.o: commercial.cpp commercial.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c commercial.cpp					
	
res_rentals.o: res_rentals.cpp res_rentals.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c res_rentals.cpp			

res_sales.o: res_sales.cpp res_sales.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c res_sales.cpp
			
com_rentals.o: com_rentals.cpp com_rentals.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c com_rentals.cpp			

com_sales.o: com_sales.cpp com_sales.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c com_sales.cpp	

staff_container.o: staff_container.cpp staff_container.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c staff_container.cpp
	
property_container.o: property_container.cpp property_container.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c property_container.cpp
	
map_container.o: map_container.cpp map_container.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c map_container.cpp
	
utility1.o: utility1.cpp utility1.h
	g++ -Wall -ansi -pedantic -g -std=c++11 -c utility1.cpp	
		
.PHONY:clean
clean:
	rm -f *.o core assign1 a.out

