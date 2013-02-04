#include <iostream>
#include <rude/cgi.h>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <iostream>
#include <mysql/mysql.h> // MySQL Include File
#include <cstring>
#include<cstdio>


#define SERVER "localhost"
#define USER "root"
#define PASSWORD "vivek"
#define DATABASE "vivek"


using namespace std;
using namespace rude;
CGI cgi;

class college
{
    char s_name[50],s_name2[50],f_name[50],f_name2[50],m_name[45],m_name2[50],email[25],trade_sem[15];
    int rollno,regno,phoneno,id,phno;
    char t_name[50],t_name2[50],dept[10],quali[23],sub_name[20],addr[50],e_mail[35];
    char nuser[50],pass[50];

public:
    void config();
    void login();
    void newuser();
    void menu();
    void del();
    void search();
    void show_data_student();
    void show_data_teacher();
    void get_data();
    void del_student();
    void del_teacher();
    void updated();
    void update_data_student();
    void update_data_teacher();
    void info_of_student();
    void info_of_teacher();
    MYSQL *connect;
    MYSQL_RES *res_set;
    MYSQL_ROW row;
} s1;




void college::newuser()
{
    char nuser[50],pass[50];
    s1.config();
    cout<<"<html><body><form><h1 style='text-align:center'>CHANGE USER</h1><br>"<<endl;
    cout<<"Enter New user name==<input type='text' name='nuser'<br>";

    cout<<"Enter New User Password=<input type='text' name='pass'><br>";
    cout<<"<input type='submit' value='login' name='login-form' />"
        <<"<input type='hidden' name='action' value='newuser'></form></body></html>";
    if (strcmp(cgi.value("login-form"),"login")==0)
    {
        char sql[512];
        char sql1[512];
        sprintf(sql,"delete from User");
        mysql_query(connect,sql);
        sprintf(sql1,"insert into User values('%s','%s')",cgi.value("nuser"),cgi.value("pass"));
        mysql_query(connect,sql1);
        cout<<"<script type='text/javascript'>window.location='final?action=login'</script>";
    }



}



void college::config()
{


    connect=mysql_init(NULL); // Initialise the instance

    if(!connect)
    {
        cout<<"MySQL Initialization Failed";

    }


    connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);
    if(connect)
    {
        cout<<"\n";
    }
    else
    {
        cout<<"Connection Failed!\n";
    }

}


void college::login()
{
    char stu[50],pass[50];
    cout<<"<html><body><form method='post'>";
    cout<<"<h1 style='text-align:center'>LOGIN FORM</h1>";
    cout<<"Enter the username:<input type='text' name='username' /><br>";
    cout<<"Enter the password:<input type='text' name='password' />"
        <<"<input type='submit' value='login' name='login-form' />"
        <<"</form></body></html>";

    //Post
    if (strcmp(cgi.value("login-form"),"login")==0)
    {


        s1.config();
        char sql[512];
        sprintf(sql,"select * from User where User='%s' and Pass='%s'",cgi.value("username"),cgi.value("password"));
        if (mysql_query(connect,sql)==0)
        {
            unsigned int i = 0;
            res_set = mysql_store_result(connect);

            unsigned int numrows = mysql_num_rows(res_set);

            if (numrows==1)
            {
                cout<<"enter here";
                cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";

            }
            else
            {
                cout<<"Try again";

            }
        }


    }
}


void college::menu()
{


    cout<<"<html><body><form action='final?action=showmenu' ><h1 style='text-align:center'>MAIN MENU</h1>"<<endl;

    cout<<"1. ADD NEW RECORD .................<br> :";
    cout<<"2. UPDATE RECORD  ................. :<br>";
    cout<<"3. DELETE RECORD  ................. :<br>";
    cout<<"4. SEARCH RECORD  ................. :<br>";
    cout<<"5. CHANGE USER AND PASSWORD........ :<br>";
    cout<<"QUIT=0............................. :<br>";
    cout<<"ENTER YOUR CHOICE......<input type='text' name='ch' />"
        <<"<input type='submit' name='enter' /><input type='hidden' value='1' name='mainmenu-option' /><input type='hidden' name='action' value='showmenu' >"
        <<"</form></body></html>";
    if (strcmp(cgi.value("mainmenu-option"),"1")==0)
    {
        if (strcmp(cgi.value("ch"),"1")==0)
        {

            cout<<"<script type='text/javascript'>window.location='final?action=add1'</script>";
        }
        else if (strcmp(cgi.value("ch"),"2")==0)
        {

            cout<<"<script type='text/javascript'>window.location='final?action=update'</script>";
        }


        else if (strcmp(cgi.value("ch"),"3")==0)
        {

            cout<<"<script type='text/javascript'>window.location='final?action=deleted'</script>";
        }
        else if (strcmp(cgi.value("ch"),"4")==0)
        {

            cout<<"<script type='text/javascript'>window.location='final?action=search'</script>";
        }
        else if (strcmp(cgi.value("ch"),"5")==0)
        {

            cout<<"<script type='text/javascript'>window.location='final?action=newuser'</script>";
        }
        else
        {
            cout<<"no done";
            cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";
        }

    }


    /*s1.get_data();
    menu();
    break;
            case 2:
    updated();
    menu();
    break;
            case 3:
    del();
    menu();
    break;
            case 4:
    s1.search();
    menu();
    break;
            case 5:
    s1.newuser();
    break;
            case 0:
    printf("THANKS TO VISIT.............");
            default:
    cout<<"Wrong entry:try again";
    s1.menu();
    break;
            }
        }
        while(ch!=0);*/
}


void college::get_data()
{


    cout<<"<html><body>###################################################<br>";
    cout<<"<h2 style='text-align:center'>ADD RECORD</h2><br> ";
    cout<<"####################################################<br>";
    cout<<"1. INFORMATION OF STUDENT<br>";
    cout<<"2. INFORMATION OF TEACHER<br>";

    cout<<"ENTER YOUR CHOICE......<br><form><input type='text' name='choice' />"
        <<"<input type='submit' name=choice /><input type='hidden' name='action' value='add1'></form></body></html>";

    if(strcmp(cgi.value("choice"),"1")==0)
    {
        cout<<"<script type='text/javascript'>window.location='final?action=infoofstudent'</script>";

    }
    else if(strcmp(cgi.value("choice"),"2")==0)
    {
        cout<<"<script type='text/javascript'>window.location='final?action=infoofteacher'</script>";

    }
}

void college::info_of_student()
{
    cout<<"<html><body><form method='post'>*******************************<br>";
    cout<<"<h2 style='text-align:center'>INFORMATION OF STUDENT</h2><br>";
    cout<<"*******************************<br>";
    cout<<" Student First name==      : <input type='text' name='s_name' /><br>";

    cout<<" Student last name==       : <input type='text' name='s_name2' /><br> ";

    cout<<" Father first name==       : <input type='text' name='f_name' /><br>";

    cout<<" Father last name ==      : <input type='text' name='f_name2' /><br>";

    cout<<" Mother First name==       : <input type='text' name='m_name' /><br>";
    cout<<" Mother last name==       : <input type='text' name='m_name2' /><br>";

    cout<<" Class ==            : <input type='text' name='trade_sem' /><br>";

    cout<<" Rollno ==           : <input type='text' name='rollno' /><br>";

    cout<<" Reg.no==            : <input type='text' name='regno' /><br>";

    cout<<" Address ==          : <input type='text' name='addr' /><br>";

    cout<<" Phoneno==           : <input type='text' name='phoneno' /><br>";

    cout<<" E-mail==            : <input type='text' name='email' /><br>";

    cout<<"<input type='submit' value='done' name='enter' /><input type='hidden' name='action' value='infoofstudent'>"
        <<"</form></body></html>";


    if (strcmp(cgi.value("enter"),"done")==0)
    {
        s1.config();
        char sql[512];
        sprintf(sql,"insert into student values('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",cgi.value("s_name"),cgi.value("s_name2"),cgi.value("f_name"),cgi.value("f_name2"),cgi.value("m_name"),cgi.value("m_name2"),cgi.value("trade_sem"),cgi.value("rollno"),cgi.value("regno"),cgi.value("addr"),cgi.value("phoneno"),cgi.value("email"));

        mysql_query(connect,sql);
        cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";
    }
}


void college::info_of_teacher()
{
    cout<<"<html><body><form>*******************************"<<endl;
    cout<<"<h2 style='text-align:center'>INFORMATION OF TEACHER</h2><br>";
    cout<<"*******************************<br>";
    cout<<" Teacher First name      : <input type='text' name='t_name' /><br>";

    cout<<" Teacher last name      : <input type='text' name='t_name2' /><br>";


    cout<<" Department        : <input type='text' name='dept' /><br>";

    cout<<" ID NO.            : <input type='text' name='id' /><br>";

    cout<<" Qualification     : <input type='text' name='quali' /><br>";

    cout<<" Subject name      : <input type='text' name='sub_name' /><br>";

    cout<<" Address           : <input type='text' name='addr' /><br>";

    cout<<" Phoneno           : <input type='text' name='phno' /><br>";

    cout<<" E-mail            : <input type='text' name='e_mail' /><br>";
    cout<<"<input type='submit' value='done' name='enter' /><input type='hidden' name='action' value='infoofteacher'>"
        <<"</form></body></html>";


    if (strcmp(cgi.value("enter"),"done")==0)
    {

        s1.config();
        char sql[512];
        sprintf(sql,"insert into teacher values('%s','%s','%s','%s','%s','%s','%s','%s','%s')",cgi.value("t_name"),cgi.value("t_name2"),cgi.value("dept"),cgi.value("id"),cgi.value("quali"),cgi.value("sub_name"),cgi.value("addr"),cgi.value("phno"),cgi.value("e_mail"));

        mysql_query(connect,sql);
        cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";
    }
}

void college::search()
{
    cout<<"<html><body><form><h2 style='text-align:center'>SEARCH RECORD</h2><br>";

    cout<<"1. INFORMATION OF STUDENT<BR>";
    cout<<"2. INFORMATION OF TEACHER<BR>"   ;
    cout<<"0. MENU .........<br>"<<endl;
    cout<<"ENTER YOUR CHOICE......<input type='text' name='choice1' />"
        <<"<input type='submit' name='enter' /><input type='hidden' name='action' value='search'> "
        <<"</form></body></html>";

    if (strcmp(cgi.value("choice1"),"1")==0)
    {

        cout<<"<script type='text/javascript'>window.location='final?action=show_data_student'</script>";
    }
    else if (strcmp(cgi.value("choice1"),"2")==0)
    {

        cout<<"<script type='text/javascript'>window.location='final?action=show_data_teacher'</script>";
    }

    else if (strcmp(cgi.value("choice1"),"0")==0)
    {
        cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";
    }


}


void college::show_data_student()
{


    cout<<"<html><body><form><h1 >enter roll no of student to be searched</h1><br>";
    cout<<"<input type='text' name='sch' />"
        <<"<input type='submit' name='enter' /><a href='final?action=showmenu'>MENU</a><input type='hidden' name ='action' value='show_data_student'>"
        <<"</form></body></html>";
    s1.config();
    char sql[512];
    sprintf(sql,"select * from student where rollno='%s'",cgi.value("sch"));

    mysql_query(connect,sql);
    unsigned int i = 0; /* Create a counter for the rows */

    res_set = mysql_store_result(connect); /* Receive the result and store it in res_set */

    unsigned int numrows = mysql_num_rows(res_set); /* Create the count to print all rows */
    cout<<"<html><body><form><h1 style='text-align:center'> ::::::::RECORD MENU::::::: <h1><br> ";


    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout<<"Student first name            : "<<row[i]<<endl;
        cout<<"<br>Student last name             : "<<row[i+1]<<endl;

        cout<<"<br>Father First name             : "<<row[i+2]<<endl;

        cout<<"<br>Father Last name              : "<<row[i+3]<<endl;
        cout<<"<br>Mother First name             : "<<row[i+4]<<endl;
        cout<<"<br>Mother Last name              : "<<row[i+5]<<endl;
        cout<<"<br>Class                         : "<<row[i+6]<<endl;
        cout<<"<br>Rollno                        : "<<row[i+7]<<endl;
        cout<<"<br>Reg.no                        : "<<row[i+8]<<endl;
        cout<<"<br>Address                       : "<<row[i+9]<<endl;
        cout<<"<br>Phoneno                       : "<<row[i+10]<<endl;
        cout<<"<br>E-mail                        : "<<row[i+11]<<endl;
    }
    // cout<<"<script type='text/javascript'>window.location='final?action=add1'</script>"; to call search again
}

void college::show_data_teacher()
{
    cout<<"<html><body><form><h1 >enter id of teacher to be searched</h1><br>";
    cout<<"<input type='text' name='sch' />"
        <<"<input type='submit' name='enter' /><a href='final?action=showmenu'>MENU</a><input type='hidden' name='action' value='show_data_teacher'>"
        <<"</form></body></html>";

    s1.config();
    char sql[512];
    sprintf(sql,"select * from teacher where id='%s'",cgi.value("sch"));
    mysql_query(connect,sql);
    unsigned int i = 0; /* Create a counter for the rows */
    res_set = mysql_store_result(connect); /* Receive the result and store it in res_set */
    unsigned int numrows = mysql_num_rows(res_set); /* Create the count to print all rows */


    cout<<" <html><body><form><h1 style='text-align:center'>INFORMATION OF TEACHER</h1><br>"<<endl;

    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout<<"<br>Teacher name            : "<<row[i]<<endl;
        cout<<"<br>Department              : "<<row[i+1]<<endl;
        cout<<"<br>Qualification           : "<<row[i+2]<<endl;
        cout<<"<br>subject name            : "<<row[i+3]<<endl;
        cout<<"<br>Address                 : "<<row[i+4]<<endl;
        cout<<"<br>Phoneno                 : "<<row[i+5]<<endl;
        cout<<"<br>ID NO.                  : "<<row[i+6]<<endl;
        cout<<"<br>E-mail                  : "<<row[i+7]<<endl;
    }
    // cout<<"<script type='text/javascript'>window.location='final?action=add1'</script>"; to call search again
}

void college::updated()
{

    cout<<"<html><body><form><h1 style='text-align:center'>UPDATE RECORD</h1><Br>"<<endl;

    cout<<"1. STUDENT<br>";
    cout<<"2. TEACHER<br>";
    cout<<"0. MENU .........<br>"<<endl;
    cout<<"ENTER YOUR CHOICE......<input type='text' name='ch2' />"
        <<"<input type='submit' name='enter' /><a href='final?action=showmenu'>MENU</a><input type='hidden' name='action' value='update'>"
        <<"</form></body></html>";

    if (strcmp(cgi.value("ch2"),"1")==0)
    {

        cout<<"<script type='text/javascript'>window.location='final?action=update_data_student'</script>";
    }
    else if (strcmp(cgi.value("ch2"),"2")==0)
    {
        cout<<"<script type='text/javascript'>window.location='final?action=update_data_teacher'</script>";
    }
    else if (strcmp(cgi.value("ch2"),"0")==0)
    {

        cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";
    }

}
void college::update_data_student()
{
    cout<<"<html><body><form><h1 >enter roll no of student to be updated</h1><br>";
    cout<<"<input type='text' name='sch' />"
        <<"<input type='submit' name='enter' value='Submit'/><a href='final?action=showmenu'>MENU</a><input type='hidden' name ='action' value='update_data_student'>"
        <<"</form></body></html>";
    if(strcmp(cgi.value("enter"),"Submit")==0)
    {
        s1.config();
        char sql[512];
        sprintf(sql,"delete from student where rollno='%s'",cgi.value("sch"));
        if(mysql_query(connect,sql)==0)
        {

            cout<<"<script type='text/javascript'>window.location='final?action=infoofstudent'</script>";
        }


    }
}
void college::update_data_teacher()
{
    cout<<"<html><body><form><h1 style='text-align:center'>enter id of teacher</h1><br>";
    cout<<"<input type='text' name='de' />"
        <<"<input type='submit' name='enter' value='Submit'/><a href='final?action=showmenu'>MENU</a>"
        <<"</form></body></html>";
    if(strcmp(cgi.value("enter"),"Submit")==0)
    {
        s1.config();
        char sql[512];
        sprintf(sql,"delete from teacher where id='%s'",cgi.value("de"));
        if(mysql_query(connect,sql)==0)
        {

            cout<<"<script type='text/javascript'>window.location='final?action=infoofteacher'</script>";
        }
    }

}
void college::del()
{
    cout<<"<html><body><form><h1 style='text-align:center'>DELETE RECORD:::::::</h1><br>  "<<endl;

    cout<<"1. RECORD OF STUDENT<br>"<<endl;
    cout<<"2. RECORD OF TEACHER<br>"<<endl;
    cout<<"0. MENU .........<br>"<<endl;

    cout<<"ENTER YOUR CHOICE......<input type='text' name='ch2' />"
        <<"<input type='submit' name='enter' /><a href='final?action=showmenu'>MENU</a><input type='hidden' name='action' value='deleted'>"
        <<"</form></body></html>";

    if (strcmp(cgi.value("ch2"),"1")==0)
    {

        cout<<"<script type='text/javascript'>window.location='final?action=del_student'</script>";
    }
    else if (strcmp(cgi.value("ch2"),"2")==0)
    {
        cout<<"<script type='text/javascript'>window.location='final?action=del_teacher'</script>";
    }
    else if (strcmp(cgi.value("ch2"),"0")==0)
    {

        cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";
    }

}


void college::del_student()
{

    cout<<"<html><body><form><h1 >Enter roll no of student</h1><br>";
    cout<<"<input type='text' name='de' />"
        <<"<input type='submit' name='enter' value='submit' /><a href='final?action=showmenu'>MENU</a>"
        <<"</form></body></html>";
    if(strcmp(cgi.value("enter"),"Submit")==0)
    {

        s1.config();
        char sql[512];

        sprintf(sql,"delete from student where rollno='%s'",cgi.value("de"));
        if(mysql_query(connect,sql)==0)
        {
            cout<<"<script type='text/javascript'>window.location='final?action=showmenu'</script>";
        }
    }
}
void college::del_teacher()
{
    cout<<"<html><body><form><h1 >Enter id of tearcher</h1><br>";
    cout<<"<input type='text' name='de' />"
        <<"<input type='submit' name='enter' />"
        <<"<a href='final?action=showmenu'>MENU</a></form></body></html>";
    s1.config();
    char sql[512];
    sprintf(sql,"delete from teacher where id='%s'",cgi.value("de"));
    mysql_query(connect,sql);

}



int main()
{
    cout<<"Content-type:text/html;charset=utf8\r\n\r\n";

    if (strcmp(cgi.value("action"),"showmenu")==0)
    {
        s1.menu();
    }


    else if (strcmp(cgi.value("action"),"login")==0)
    {
        s1.login();
    }
    else if(strcmp(cgi.value("action"),"add1")==0)
    {

        s1.get_data();
    }
    else if(strcmp(cgi.value("action"),"del_student")==0)
    {

        s1.del_student();
    }
    else if(strcmp(cgi.value("action"),"del_teacher")==0)
    {

        s1.del_teacher();
    }
    else if(strcmp(cgi.value("action"),"infoofstudent")==0)
    {

        s1.info_of_student();
    }
    else if(strcmp(cgi.value("action"),"infoofteacher")==0)
    {

        s1.info_of_teacher();

    }
    else if(strcmp(cgi.value("action"),"update")==0)
    {
        s1.updated();
    }



    else if(strcmp(cgi.value("action"),"deleted")==0)
    {

        s1.del();
    }
    else if(strcmp(cgi.value("action"),"newuser")==0)
    {

        s1.newuser();

    }
    else if(strcmp(cgi.value("action"),"search")==0)
    {

        s1.search();
    }
    else if(strcmp(cgi.value("action"),"show_data_student")==0)
    {

        s1.show_data_student();
    }
    else if(strcmp(cgi.value("action"),"show_data_teacher")==0)
    {

        s1.show_data_teacher();
    }

    else if(strcmp(cgi.value("action"),"update_data_student")==0)
    {

        s1.update_data_student();
    }
    else if(strcmp(cgi.value("action"),"update_data_teacher")==0)
    {

        s1.update_data_teacher();
    }

    else
    {

        s1.login();
    }
    return 0;
}
