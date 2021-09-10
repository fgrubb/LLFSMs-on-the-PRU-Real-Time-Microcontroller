cout << "In OUTPUT_TAIL\n" ;
block[counter]='\0'; counter++;
for (int i=0; i< counter ; i++) { output_file->put(block[i]);}
if(write(filedesc,block, counter) != counter)
      { cerr << "Message not sent in full\n"; }
else { cerr<< "Message sent successfully...\n";}
close(filedesc);
input_file->close();
output_file->close();
