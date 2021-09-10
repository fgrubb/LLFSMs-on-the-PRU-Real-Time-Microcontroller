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
const int SIZE = 100;
const int ONE_AT_A_TIME_TO_FIND_EOF = 1;


int main () {

  char block[SIZE];

  ofstream output_file;
  output_file.open ("received.txt");
#ifdef ON_THE_ARM
  int filedesc = open("/dev/rpmsg_pru30", O_RDWR);
#endif
#ifdef TESTING
  int fd_testing = open("input.txt", O_RDONLY);
#endif

  if ( (output_file.is_open())
#ifdef ON_THE_ARM
	&& (0<=filedesc )
#endif
#ifdef TESTING
	&& (0<=fd_testing )
#endif
     )
  {

    int counter =0;
    int i=0;

    do {
#ifdef ON_THE_ARM
	counter = read (filedesc,block,24);
#endif
#ifdef TESTING
	counter = read (fd_testing,block,ONE_AT_A_TIME_TO_FIND_EOF);
#endif

	if (counter>0) {
 	  cerr<< "Data received successfully...\n";
	  i=0;
          do {
		output_file << block[i];
		i++; 
	  } while ( (i< counter)  && (block[i] !='\0') );
	}; // if 
    } while ( (block[i] !='\0') && (counter>0) );
    
    output_file.close();
#ifdef ON_THE_ARM
    close(filedesc);
#endif
#ifdef TESTING
    close(fd_testing);
#endif

  }
  else { cerr << "Unable to open file "; 
#ifdef ON_THE_ARM
	 cerr << "filedesc:"<< filedesc << "\n";
#endif
	 cerr << "Error Number " << errno; 
	 perror("Program");
  	 return 1;
	}

  return 0;
}
