#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

string version = "v1.0.0";

string exractPath(string filePath){
	int slashCount = 0;
	int index, count = 0;
	for (char letter : filePath){
		if(letter == '\\'){
			index = count;
		}
		count += 1;
	}
	return filePath.substr(0,index+1);
}

bool isGitAvailable() {
    return (system("git --version") == 0);
}

int main(int argc, char *argv[]){
	if(argc > 1){
		string argument1 = "";
		string filePath = "";
		bool skipLine = false;
		for (int i=0; i<argc; i++){
			if(i==0){
				argument1 = argv[i];
				continue;
			}
			if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
				cout
				<< "This program is command line based script that takes following argument. It iterates a text file or csv file with single column of urls of websites and open them in the browser\n\n"
				<< "Arguments\t\tDescription:\n +-------------------------------+ \n"
				<< "file path\t\tPath to the text file consists of a list of urls\n"
				<< "-h\t--help\t\tFor help and description\n"
				<< "-v\t--version\tReturns the version of the program\n"
				<< "-s\t--skip\t\tSkips the first line of the file if used as heading\n"
				<< "-u\t--update\tUpdate links program\n";
				return 0;
			} else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0){
				cout << "links.exe: " << version << '\n';
				return 0;
			} else if(strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--update") == 0){
				if(isGitAvailable()){
					string cmd = "cd \""+exractPath(argument1)+"\" && git pull";
					cout << cmd << '\n';
					system(cmd.c_str());
					return 0;
				}else{
					cout << "Error Update!\nGit is not installed on your system\n";
					return 1;
				}
			} else {
				if(strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--skip") == 0){
					skipLine = true;
				}else{
					filePath = argv[i];
				}
			}
		}
		if (filePath != ""){
			ifstream file(filePath);
			string line;
			int count = 0;
			while(getline(file, line)){
				if (count == 0 && skipLine){
					count += 1;
					continue;
				}
				system(("start "+line).c_str());
			}
		}else{
			cout << "Error FileNotFound!\n Missing file argument\n";
			return 1;
		}
	} else {
		cout << "Error FileNotFound! \n"
		<< "Missing file argument, try using [-h] [--help]\n";
		return 1;
	}
	return 0;
}