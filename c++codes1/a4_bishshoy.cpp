#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {

	
	chdir("/home/priyank/Downloads");
	execl("/bin/pwd", "pwd", (char*)NULL);
	

	return 0;
	
}
