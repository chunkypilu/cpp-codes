

struct Directory {
	
	char tokens[20][20];
	
	int depth;

}

void setPath(Directory& dir, char* path) {
	//split path by '/'
	//...
	//
	dir.token[0] = "home";
	dir.token[1] = "priyank";
	dir.token[2] = "Downloads";
	dir.depth = 3;
}


void getPath(Directory& dir, char* path) {
	path[0] = '/0';
	for (int i = 0; i < dir.depth; i++) {
		strcat(path, "/");
		strcat(path, dir.tokens[i]);
	}
	strcat(path, "/");
}


int main() {

	Directory dir, dir2;
	char path[200];
	getline(cin, path);
	setPath(dir, path);
	getPath(dir2
	, path);
}
