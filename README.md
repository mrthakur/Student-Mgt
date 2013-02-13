Student-Mgt
===========


Before you run the code ,you must do these following things...


1. Install Phpmyadmin and create a database as 'vivek'.

2. Now create three table as...


               1.    Student table :-  Column are   (s_name, s_name2, f_name, f_name2, m_name,      m_name2, trade_sem, rollno, reg_no, address, phne_no, e_mail)
               2.    Teacher Table :- Column are  (t_name, t_name2, dept, id, quali, sub_name, addr, phno, e_mail)      
               3.     User table :- Column are (User, Pass)


3. After this,you must install cgi in your system.For that you can read my blog:-mrthakur09.wordpress.com


4. Now just copy and paste the code.


5. Save  your file as .cpp file.


6. Open your terminal and run this command:-g++ -o final new.cpp -I /usr/include/mysql -L /usr/include/mysql -lmysqlclient -lrudecgi
               

               :- Here 'new.cpp' is my file name ,you must put your file name.
               
               :-'final' is the name of my .cgi file,you can give any name.

7. Now open your browser and type this command:-   http://localhost/cgi-bin/final


8. Here your output...
