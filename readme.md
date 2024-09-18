# Links
A C++ program that reads a text file consists of links or URLs of websites and iterate it and open all the links listed in it. This program is only available for windows platform.
## Tutorial
### Required File Types
- A simple *.txt file where links are separated by new line
- A *.CSV file with a single column of links/URLs
### Installation
- Download the .zip file from GitHub ```"<>code" > "Download ZIP"```
- Extract the .zip file.
- Add to path (optional) go to: ```Search > Environment Variables > Environment Variable > path > new > <paste the path of link.exe>```
### Run
Open the folder where folder is extracted (if not added to path)
> .\links \path\to\file.txt

If you want to skip first line of the file. When you have used first line/row for heading, like ```Website Links``` then use ```-s``` after file name
> .\links \path\to\file.txt -s

or
> .\links \path\to\file.txt --skip

If you want to update links then it is required to install Git on your system.
> .\links -u

or
>.\links --update

For more information about links.exe you can simply run the following command

> .\links -h

or
> .\links --help