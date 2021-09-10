/******************************************************************************************

(c) 2021 Vlad Estivill-Castro

******************************************************************************************/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
using namespace std;

#include<errno.h>
extern int errno;

const char NEWLINE = '\n';
const int SIZE = 24;

