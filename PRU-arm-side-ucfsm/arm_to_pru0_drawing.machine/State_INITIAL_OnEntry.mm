block = new char[SIZE];
input_file = new  ifstream ("input.txt");
output_file = new ofstream();
output_file->open ("output.txt");
filedesc = open("/dev/rpmsg_pru30", O_RDWR);
