/******************************************************************************************

(c) 2021 Vlad Estivill-Castro

******************************************************************************************/

extern "C" {
#include <stdint.h>
#include "pru_comms.h"
#include "PRU-ucfsm-general-defines.h"
}


#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <bits/stdc++.h>
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

#ifdef ON_THE_ARM
  int filedesc = open("/dev/rpmsg_pru30", O_RDWR);
#endif

  if ( true 
#ifdef ON_THE_ARM
	 && (0<=filedesc )
#endif
     )
  {

    Comms_PRU_ucFSM PRU0_local_comms;
    int times =0;
    int start =0;
    int counter =0;
    char to_extract[24];

    while (times < 30) {
		times++;
        	cout << "start:" << start << "\n";
		fill_struct_with_pattern_LEDS(start, &PRU0_local_comms);
        	start++ ;
        	start = start %24;

		get_struct (to_extract,PRU0_local_comms);
		int as_value ;
		stringstream ss4;
                counter =0;
        	for (int i=0; i<23; i++) {
			as_value = to_extract[i];
		        block[counter]=to_extract[i];
		        counter ++;
        		ss4 <<  "i="<< i << " value=" << as_value << ":" << bitset<8>(as_value).to_string() << ", ";
		}
		as_value = to_extract[23];
		block[counter]=to_extract[23];
		counter ++;
        	ss4 << as_value << ":" << bitset<8>(as_value).to_string() ;
		ss4 << " <*SENDING*>" << counter;
		cout << ss4.str();
        	cout << "<<\n";
#ifdef ON_THE_ARM
			  if(write(filedesc,block, counter) != counter)
			   { cerr << "Message not sent in full\n";
			   }
        		   else  cerr<< "Message sent successfully...\n";
#endif
		sleep(25);
	}// while

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
