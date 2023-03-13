#include<bits/stdc++.h>
#include "ErrorHandling.cpp"
#include "HelpCommand.cpp"
using namespace std;

set<string> keywords={
	"Create","Select","Describe","Table","Tables",
	"Primary","Key","Int","Varchar",
	"Date","Decimal","Drop","Into"
	,"Help","Values","From"
	,"Where","And","Or","Insert","Delete"
};

vector<string>Tokens;

void DisplayTokens()
{
	for(auto it:Tokens)
	{
		cout<<it<<" ";
	}
	cout<<endl;
}

void ParseIntoTokens(string Query)
{
    string temp="";

    for(int i=0;i<Query.size();i++)
    {
        char c = Query[i];

        if(c=='"')
        {
            i++;
            while(Query[i]!='"')
            {
                temp+=Query[i];
                i++;
            }
            
            if(temp!="")
                Tokens.push_back(temp);
            temp = "";
        }
        else if(c==' ' || c=='(' || c==')' || c==',' || c==';' || c=='*')
        {
            if(temp!="")
                Tokens.push_back(temp);
            if(c=='*')
                Tokens.push_back("*");
            temp = "";
        }
        else if(Query[i]=='!' && Query[i+1]=='=')
        {
            if(temp!="")
                Tokens.push_back(temp);
            temp = "";

            Tokens.push_back("!=");
            i++;
        }
        else if(c=='<' || c=='>'|| c=='=')
        {
            if(temp!="")
                Tokens.push_back(temp);
            temp = "";

            Tokens.push_back(string(1,c));
        }
        
        else 
        {
            temp += c; 
        }
    }
    if(temp!="")
        Tokens.push_back(temp);
}


void cvtIntoSmallCase()
{
	for(int i=0;i<Tokens.size();i++)
    {
        string x = Tokens[i];
        transform(x.begin(),x.end(),x.begin(),::tolower);
        if(keywords.find(x)!=keywords.end())
            Tokens[i] = x;
    }
}


int main()
{
	system("cls");
	string Query;
	 while(1)
	 {
	 	
	 	Tokens.clear();
	 	cout<<endl<<">> ~ ";
	 	getline(cin,Query);cout<<endl;
	 	if(Query.back()!=';')
	 	{
	 		cout<<"Error : missing ; at the end...";
	 		continue;
	 	}
	 	ParseIntoTokens(Query);
	 	cvtIntoSmallCase();
	 	DisplayTokens();

        bool checknoerrors=ErrorsChecking(Tokens);
        // if(checknoerrors)
        // {
        //     Execute();
        // }
	 }

     return 0;
}

