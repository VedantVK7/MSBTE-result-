#include  "iostream"
#include  <fstream>
#include  <iomanip>
#include  "string.h"

using namespace std;
// Declaring global arrays of subject name, max. marks per subject and theory/practical wise max marks.
char sub[7][50]= {"ELEMENTS OF ELECTRICAL ENGINEERING (22215)","APPLIED MATHEMATICS (22224)","BASIC ELECTRONICS (22225)","PROGRAMMING IN 'C' (22226)","BUSINESS COMMUNICATION USING COMPUTERS (22009)","COMPUTER PERIPHERAL AND HARDWARE (22013)","WEB PAGE DESIGNING WITH HTML (22014)"};
int max_sub[7]= {95,100,95,95,50,100,100};
int max_th[7]= {70,70,70,70,35,50,50};
int max_pr[7]= {25,30,25,25,15,50,50};

class student     //class student having basic student info as members and show and get function
{
private:
    char name[50];
    char branch[50];
    char examination[50];
    long long int enroll,seat_no;

public:
    void getdata()
    {
        cin.getline(name,50);
        cout<<"   Enter name :";
        cin.getline(name,50);
        cout<<"   Enter Branch :";
        cin.getline(branch,50);
        cout<<"   Enter Examination :";
        cin.getline(examination,50);
        cout<<"   Enter Enrollment No. :";
        cin>>enroll;
        cout<<"   Enter Seat no. :";
        cin>>seat_no;
    }
    void putdata()
    {
        int i;

        for( i=0; i<168; i++)
            cout<<"_";
        cout<<endl;

        for( i=0; i<60; i++)
            cout<<" ";

        cout<<"Maharahstra Board Of Technical Education"<<endl;

        for( i=0; i<168; i++)
            cout<<"_";
        cout<<endl;

        cout<<"Name           : "<<name<<endl<<endl;

        cout<<"Enrollment No. : "<<enroll;
        for( i=0; i<23; i++)
            cout<<" ";

        cout<<"Examination : "<<examination;
        for( i=0; i<28-strlen(examination); i++)
            cout<<" ";

        cout<<"Seat Number : "<<seat_no;
        for( i=0; i<26; i++)
            cout<<" ";

        cout<<"Second Semester"<<endl<<endl;

        cout<<"Course : Diploma in "<<branch<<endl;
        for( i=0; i<168; i++)
            cout<<"_";

        cout<<"TITLE OF COURSE";
        for( i=0; i<60-strlen("TITLE OF COURSE"); i++)
            cout<<" ";
        cout<<"|      TH/PR       |";
        cout<<"              MARKS              |";
        cout<<"           TOTAL MARKS           |";
        cout<<"        CREDITS "<<endl;

        for( i=0; i<60; i++)
            cout<<" ";
        cout<<"|                  |";
        cout<<"      MAX.      |      OBT.      |";
        cout<<"      MAX.      |      OBT.      |"<<endl;
        for( i=0; i<168; i++)
            cout<<"_";
    }

    int check(long long int x)    //function to check given id is present or not
    {
        if(x == enroll || x == seat_no)
            return 1;
        else
            return 0;
    }

};

class marks : public student  //class marks having data members as theory mark, percentage etc.
{
private:
    char grade[50];
    float th_mark[7],pr_mark[7],percentage,total_per_sub[7],total_th,total_pr,total_marks;
    int no_of_backlog;
public:
    void set_grade()    //to set grade on the basis on no. of backlogs
    {
        if(no_of_backlog<3&&no_of_backlog>0)
        {
            strcpy(grade,"A.T.K.T.");
        }
        else if(percentage>=75)
        {
            strcpy(grade,"First Class Distinction");
        }
        else if(percentage<75 && percentage >= 60)
        {
            strcpy(grade,"First Class");
        }
        else if(percentage<60 && percentage >= 40 && no_of_backlog==0 )
        {
            strcpy(grade,"Pass");
        }
        else if(no_of_backlog>3)
        {
            strcpy(grade,"Fail");
        }
    }

    void calculate_total()  //to calculate subject wise and th/pr wise sum of marks
    {
        no_of_backlog=0;
        total_pr=0;
        total_th=0;
        for(int i=0; i < 7 ; i++ )
        {
            total_per_sub[i]=th_mark[i]+pr_mark[i];
            total_th= total_th + th_mark[i];
            total_pr= total_pr + pr_mark[i];
        }
        total_marks=total_th+total_pr;
        percentage=(total_marks*100)/635;
        for(int i=0; i<7; i++)
        {
            no_of_backlog=0;
            if(th_mark[i]<28||pr_mark[i]<10)
            {
                no_of_backlog++;
            }
        }
        set_grade();
    }

    void getmarks()    //to accept marks of 7 subject
    {
        getdata();
        for(int i=0; i<7; i++ )
        {
            cout<<"   Enter marks of "<<sub[i]<<endl;
            cout<<"   Theroy :";
            cin>>th_mark[i];
            cout<<"   Practical :";
            cin>>pr_mark[i];
            cout<<endl;
        }
        calculate_total();
        set_grade();
    }
    void put_grade()        //to display the total mark, grade and percentage of student
    {
        int i;
        cout<<"Date :           |";
        for(i=0; i<70; i++)
            cout<<" ";
        cout<<"|     TOTAL MAX     |    RESULT WITH     ";
        cout<<"|    TOTAL MARKS    |    TOTAL CREDIT"<<endl;
        cout<<"08/10/2022       |";
        for(i=0; i<70; i++)
            cout<<" ";
        cout<<"|       MARKS       |          %         ";
        cout<<"|     OBTAINED      |"<<endl;
        for( i=0; i<168; i++)
        {
            if(i==17 || i==88)
                cout<<"|";
            else if(i>16 && i<89)
                cout<<" ";
            else
                cout<<"_";
        }
        cout<<"                 |";
        for(i=0; i<70; i++)
            cout<<" ";
        cout<<"|        635        |       "<<setprecision(4)<<percentage<<"        ";
        cout<<"|         "<<total_marks<<"       |"<<endl;

        cout<<"                 |";
        for( i=0; i<150; i++)
            cout<<"_";
        for(i=0; i<118; i++)
        {
            if(i==17 || i==88)
                cout<<"|";
            else
                cout<<" ";
        }
        cout<<grade<<endl;
        for( i=0; i<168; i++)
            cout<<"_";
        cout<<endl<<endl;
    }

    void putmarks()      //to display subject wise marks of student
    {
        int j;
        cout<<endl;
        cout<<endl;
        putdata();
        for(int i=0; i<7; i++)
        {
            cout<<sub[i];
            for( j=0; j<60-strlen(sub[i]); j++)
                cout<<" ";
            cout<<"|      THEORY      |";
            cout<<"       "<<max_th[i]<<"       |       "<<th_mark[i]<<"       |";
            cout<<"      "<<max_sub[i];
            if(i==0||i==2||i==3||i==4)
                cout<<" ";
            cout<<"       |       "<<total_per_sub[i]<<"       |"<<endl;
            for( j=0; j<60; j++)
                cout<<" ";
            cout<<"|     PRACTICAL    |";
            cout<<"       "<<max_pr[i]<<"       |       "<<pr_mark[i]<<"       |";
            cout<<"                |                |"<<endl;
            for( j=0; j<168; j++)
                cout<<"_";
        }
        put_grade();
    }
};

void add_details()
{
    marks add;
    add.getmarks();
    fstream file("mark.txt",ios::app|ios::in|ios::out|ios::binary);
    if(!file)
    {
        cout<<"   File opening Error";
        return;
    }
    file.write((char*)&add,sizeof(add));
    file.close();
}

void search_data()    //to search the existance of object in file
{
    long long int login_credentials;
    cout<<"\n\n   Enter Enrollment number or Seat number :";
    cin>>login_credentials;
    marks take;
    fstream file("mark.txt",ios::app|ios::in|ios::out|ios::binary);
    if(!file)
    {
        cout<<"   File opening Error";
        return;
    }
    file.seekg(0,ios::beg);
    file.seekp(0,ios::beg);
    int temp=0;
    while(file)
    {
        file.read((char *)&take, sizeof(take));
        if(take.check(login_credentials))
        {
            take.calculate_total();
            take.putmarks();
            temp = 1;
            break;
        }
    }
    if(temp == 0)
        cout<<"\n\n   No data found with the given enrollment or seat number\n\n";
    file.clear();
    file.seekp(0);
    file.seekg(0);
    file.close();
}

int main()
{
    int ch,i;
    while(1)
    {
        cout<<"\n\n";
        for(i=0; i<70; i++)
            cout<<" ";
        cout<<"Press 1 for seeing result"<<endl;
        for(i=0; i<70; i++)
            cout<<" ";
        cout<<"Press 2 to add your details"<<endl;
        for(i=0; i<70; i++)
            cout<<" ";
        cout<<"Press 0 to exit"<<endl;
        for(i=0; i<70; i++)
            cout<<" ";
        cout<<"Your Choice :";
        cin>>ch;
        switch(ch)
        {
        case 1:
            search_data();
            break;
        case 2:
            add_details();
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}
