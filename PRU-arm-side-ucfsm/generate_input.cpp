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
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#include<errno.h>
extern int errno;

const int SIZE = 100;
const int RPMSG_SIZE = 24;

int error_reporting() {
     cerr << "Unable to open file "; 
     cerr << "Error Number " << errno; 
     perror("Program");
     return 1;
}
	
int main(int argc, char* argv[]) {
     if (argc < 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " [text|binary]" << std::endl;
        return 1;
    }
    int times =0;
    do { cout << "enter the number of blocks:\n";
              cin >> times ;
   } while ( times<=0) ;

   if ('b'==argv[1][0] )
	{ cerr<< "BINATY FILE \n";
  	  ofstream output_file;
          output_file.open ("input.txt");
          int start =0;
          int counter =0;
          char to_extract[24];
          char block[24]; 
	  Comms_PRU_ucFSM PRU0_local_comms;
          int the_count =0;
          if ( (output_file.is_open()))
		{ while (the_count < times) {
                    the_count++;
                    cout << "start:" << start << "\n";
                    fill_struct_with_pattern_LEDS(start, &PRU0_local_comms);
                    //start++ ;
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
	            for (int i=0; i< 24 ; i++) output_file << block[i];
                   } // while
                 output_file.close();
	        }
	   else { return error_reporting();}

	}
   else
	{ char block[SIZE];
  	  ofstream output_file;
          output_file.open ("input.txt");
          if ( (output_file.is_open()))
             {
    
                 cerr << "Generating random textfile with " << times << " times " << SIZE << " characters= " << times*SIZE << "\n";

                 srand (time(NULL));

                 string source_characters ("0123456789ABCDEFGHIJKLMNOPQRSTUVWYZ abcdefghijklmnopqrstuvwxyz");

                 int position;
                 for (int block_id=0; block_id < times; block_id++)
		    { for (int index =0; index<SIZE; index++)
	                 { position = rand() % source_characters.size();
		           block[index] = source_characters.at(position);
		           cerr << "position=" << position << " char is=" << block[index] << '\n';
	                 }
	              for (int i=0; i< SIZE ; i++) output_file << block[i];
                      output_file << '\n';
	            }
                 output_file.close();
           }
	      else { return error_reporting();}
        } // else is text
  return 0;
}
