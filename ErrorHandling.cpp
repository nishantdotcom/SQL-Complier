#include<bits/stdc++.h>
using namespace std;

bool doesTableExists(string tableName)
{
	fstream SchemaFile;
	SchemaFile.open("SchemaFile.txt",ios::in);
	if(SchemaFile)
	{
		string line;
		while(!SchemaFile.eof())
		{
			getline(SchemaFile,line);
			if(line[0]=='*')
			{
				string name=line.substr(1,line.size()-2);
				if(name==tableName)
				{
					SchemaFile.close();
					return true;
				}
			}
		}
	}
	return false;
}


bool ErrorsChecking(vector<string>&Tokens)
{
	//Error1->What if there is no tokens
	if(Tokens.empty())
	{
		return false;
	}
	//Error2-> Check the table already exisit or not
	if(Tokens[0]=="Create" && Tokens[1]=="Table")
	{
		if(doesTableExists(Tokens[2]))
		{
			cout<<"Table <"<<Tokens[2]<<"> already exists"<<endl;
			cout<<"Table not created"<<endl;
			return false;
		}


        //Error3->If Primary 
		int Tsize=Tokens.size();
		if(Tokens[Tsize-3]!="Primary" && Tokens[Tsize-2]!="Key")
		{
			cout<<"Defining Primary Key is mandatory"<<endl;
			cout<<"Table not created"<<endl;
			return false;
		}

	}
	else if(Tokens[0]=="Drop" && Tokens[1]=="Table")
	{
		if(!doesTableExists(Tokens[2]))
		{
			cout<<"Table <"<<Tokens[2]<<"> doesn't exists"<<endl;
			cout<<"Table not dropped"<<endl;
			return false;
		}
	}
	else if(Tokens[0]=="Describe")
	{
		if(!doesTableExists(Tokens[1]))
		{
			cout<<"Table <"<<Tokens[1]<<"> doesn't exists"<<endl;
			cout<<"Table cannot be described"<<endl;
			return false;
		}

	}
	else if(Tokens[0]=="Insert" && Tokens[1]=="Into")
	{
		if(!doesTableExists(Tokens[2]))
		{
			cout<<"Table <"<<Tokens[2]<<"> doesn't exists"<<endl;
			cout<<"Tuple not inserted"<<endl;
			return false;
		}
	}
	else if(Tokens[0]=="Select")
	{
		//Handle in Select function
	}
	else if(Tokens[0]=="Help" && Tokens[1]=="Tables")
	{
		//Do nothing
	}
	else if( Tokens[0]=="Help")
	{
		//Provide Enough Help Value
	}
	else if(Tokens[0]=="Delete" && Tokens[1]=="From")
	{
		if(!doesTableExists(Tokens[2]))
		{
			cout<<"Table <"<<Tokens[2]<<"> doesn't exists"<<endl;
			cout<<"0 row affected"<<endl;
			return false;
		}
	}
	else if(Tokens[0]=="Update")
	{
		if(!doesTableExists(Tokens[1]))
		{
			cout<<"Table <"<<Tokens[1]<<"> doesn't exists"<<endl;
			cout<<"0 rows affected"<<endl;
			return false;
		}
	}
	else if(Tokens[0]=="Quit")
	{

	}
	else {

	}
	return true;


}
























