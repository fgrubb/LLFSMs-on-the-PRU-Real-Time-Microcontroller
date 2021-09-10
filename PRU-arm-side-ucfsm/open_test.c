#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
 
#include<errno.h>
extern int errno;

int main()
{
       write(2,"start\n",6);   
       int filedesc = open("/dev/rpmsg_pru30", O_RDWR);
       if(filedesc < 0) {
	        printf("filedesc = %d\n", filedesc);
       		write(2,"fail\n",5);   
		printf("Error Number % d\n", errno); 
	 	perror("Program");
			        return 1;
       }
		 
       if(write(filedesc,"This will be output to testfile.txt\n", 36) != 36)
			        {
			        write(2,"There was an error writing to testfile.txt\n",20);    // strictly not an error, it is allowable for fewer characters than requested to be written.
						        return 1;
							    }
		     
		        return 0;
}
