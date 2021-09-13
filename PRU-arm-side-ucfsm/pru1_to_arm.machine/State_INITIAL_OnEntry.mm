cout << "In INITIAL\n";
block = new char[SIZE];
output_file = new ofstream();
output_file->open ("received.txt");
filedesc = open("/dev/rpmsg_pru31", O_RDWR);
