for (int i=0; i< SIZE ; i++) {output_file->put(block[i]); }
if (write(filedesc,block, SIZE) != SIZE)
      { cerr << "Message not sent in full\n";  }
