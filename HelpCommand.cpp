#include<bits/stdc++.h>
using namespace std;

void HelpTables()
{
	fstream SchemaFile;
	SchemaFile.open("SchemaFile.txt",ios::in);
	if(!SchemaFile)
	{
		cout<<"Schema File not found"<<endl;
		return;
	}
	if(SchemaFile.peek()==-1)
	{
		cout<<"No table found"<<endl;
		return;
	}
	cout<<"Table in the database are :"<<endl;
	string line;
	while(!SchemaFile.eof())
	{
		getline(SchemaFile,line);
		if(line.front()=='*' && line.back()=='*')
		{
			cout<<line.substr(1,line.size()-2)<<endl;

		}
	}
}

