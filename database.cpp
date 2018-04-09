//
//  database.cpp
//  Sorry
//
//  Created by User on 4/2/18.
//  Copyright © 2018 Xu Sun. All rights reserved.
//

#include "database.hpp"
#include <stdio.h>
#include <mysql.h>


int main (int argc, const char * argv[])
{
    MYSQL *connection, mysql;
    mysql_init(&mysql);
   // connection = mysql_real_connect(&mysql,"127.0.0.1","root","root123","sqltest",0,0,0);
    connection = mysql_real_connect(&mysql,"webdb.uvm.edu","xsun4_admin","tZKc6LyTtrBpIsBn","XSUN4_cs205",0,0,0);
    if (connection == NULL)
    {
        //unable to connect
        printf("Oh Noes!\n");
    }
    else
    {
        printf("Connected.\n");
    }
    return 0;
}


