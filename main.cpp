#include <bits/stdc++.h>
#include "function.cpp"
#include "HelpCommand.cpp"
#include "ErrorHandling.cpp"
using namespace std;

set<string> keywords = {
                                "create","table","primary","key",
                                "int","varchar","date","decimal"
                                "drop",
                                "describe",
                                "insert","into","values",
                                "help","tables",
                                "select","from","where","and","or",
                           };


vector<string>Tokens;


void DisplayTokens()
{
    for(string x:Tokens)
        cout<<x<<endl;
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
            if(c=='*')//for handling special case in select
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
        else if(c=='<' || c=='>'|| c=='=')//OR other operators
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

void Execute()
{
    if(Tokens.empty())
        return;

    if(Tokens[0]=="create" && Tokens[1]=="table") 
    {CreateTable(Tokens);}

    else if(Tokens[0]=="drop" && Tokens[1]=="table")
    {DropTable(Tokens);}

    else if(Tokens[0]=="describe")
    {DescribeTable(Tokens);}

    else if(Tokens[0]=="help" && Tokens[1]=="tables")
    {HelpTables();}

    else if(Tokens[0]=="help")
    {HelpCommand(Tokens);}

    else if(Tokens[0]=="insert" && Tokens[1]=="into")
    {
        int res = InsertInto(Tokens);
        res==1 ? cout<<"Tuple inserted successfully"<<endl : cout<<"Tuple not inserted"<<endl;
    }

    else if(Tokens[0]=="select")
    {Select(Tokens);}
    
    else if(Tokens[0]=="update")
    {
        UpdateTable(Tokens);
    }

    else if(Tokens[0]=="delete" && Tokens[1]=="from")
    {
        DeleteFrom(Tokens);
    }
    
    else if(Tokens[0]=="quit")
    {
        cout<<"Program terminated successfully."<<endl;
        exit(0);
    }
    else
    {
        cout<<"INVALID QUERY"<<endl;
    }
    
}

void cvtIntoSmallerCase()
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
        attributes_of_table.clear();
        cout<<endl<<">> ";

        getline(cin,Query); cout<<endl;

        if(Query.back()!=';') 
        {
            cout<<"; missing at the end"<<endl;
            continue;
        }
        ParseIntoTokens(Query);
        cvtIntoSmallerCase();
        //DisplayTokens();
        bool noerrors = ErrorsChecking(Tokens);

        if(noerrors)
            Execute();  
    }
    
    return 0;
}