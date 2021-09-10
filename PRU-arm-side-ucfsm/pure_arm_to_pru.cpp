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
#ifdef TESTING
const int ENOFLINESPACE = 1;
#else
const int ENOFLINESPACE = 0;
#endif


int main () {

  char block[SIZE];

  ifstream input_file ("input.txt");
  ofstream output_file;
  output_file.open ("output.txt");
#ifdef ON_THE_ARM
  int filedesc = open("/dev/rpmsg_pru30", O_RDWR);
#endif

  if ((input_file.is_open())
   && (output_file.is_open())
#ifdef ON_THE_ARM
	&& (0<=filedesc )
#endif
     )
  {

    int ch;
    int counter =0;
    
    while  ( ((ch = input_file.get()) != EOF)
		&& (counter < (SIZE-ENOFLINESPACE))
           ) {
		block[counter]=ch;

		counter ++;
		if ((SIZE-ENOFLINESPACE) <= counter)
			{ counter =0;
			  // NOTE: if we do not have a null character this
			  // outputs funny stuff when testing
#ifdef TESTING
		          block[(SIZE-ENOFLINESPACE)]='\0';
#endif
			  for (int i=0; i< SIZE ; i++) output_file << block[i];
#ifdef ON_THE_ARM
			  for (int i=0; i< SIZE ; i++) cout << block[i] ;
			    
			  if(write(filedesc,block, SIZE) != SIZE)
			   { cerr << "Message not sent in full\n";
			   }
        		   else  cerr<< "Message sent successfully...\n";
#endif
			}
		 
             }

    // write out the tail of the file
    for (int i=0; i< counter ; i++) output_file << block[i];
#ifdef ON_THE_ARM
    for (int i=0; i< counter ; i++) cout << block[i] ;
    if(write(filedesc,block, counter) != counter)
      { cerr << "Message not sent in full\n";
      }
    else  cerr<< "Message sent successfully...\n";
#endif
    

    input_file.close();
    output_file.close();
#ifdef ON_THE_ARM
	close(filedesc);
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
