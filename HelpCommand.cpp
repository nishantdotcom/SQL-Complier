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




void HelpCommand(vector<string> Tokens)
{
	if(Tokens[1]=="Create")
	{
		cout<<"Used to create tables in SQL"<<endl;
        cout<<"SYNTAX : ";
        cout<<"create table table_name (attr1 type1, attr2 type2 check(cond1 AND cond2), primary key(attr1));"<<endl;
        cout<<"Eg -"<<endl;
        cout<<"create table Student(roll int check(roll>0), name varchar(20) check(name!=\"ABC\"), dob date, percent decimal(4,2), primary key(roll));";
    }
}


























