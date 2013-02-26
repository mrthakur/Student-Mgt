Student-Mgt
===========
How to run the Code?


Before you run the code ,you must do these following things...


1.Install Phpmyadmin by reading following blog:-

http://blog.sudobits.com/2011/06/19/how-to-install-phpmyadmin-on-ubuntu-11-04-10-10/

2.Now import the database file vivek.sql ,by using this command:-

mysql -p -u username database_name < vivek.sql

3.After this,you must install Rude CGI Library in your system.

For that open terminal and run following command

$ sudo apt-get install librudecgi5

4.Install MySql Connector for C++

Follow blog:

http://mandeepsimak.wordpress.com/2012/12/15/mysql-connector-for-c/

5.Now download the file ie new.cpp and save it in cgi-bin folder.


 6.Open your terminal and type this command:-

 cd  /usr/lib/cgi-bin/

 g++ -o final new.cpp -I /usr/include/mysql -L /usr/include/mysql -lmysqlclient -lrudecgi

 Now open your browser and type this command:-   http://localhost/cgi-bin/final

               Type username:-vivek
               password:-pass







