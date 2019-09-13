#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include <stdio.h>
using namespace std;
//search and delete with any attribute
void insertRecord(char id[5],char name[20],char age[5],char grade[2],char city[10],char marks[5])
{
	fstream file("data.txt",ios::out|ios::app);
	file<<id<<' '<<name<<' '<<age<<' '<<grade<<' '<<city<<' '<<marks<<' ';
	file.close();
}
bool checkId(char ID[5]){
	char id[5];
	char name[20];
	char age[5];
	char grade[2];
	char city[10];
	char marks[5];
	fstream file("data.txt",ios::in);
	while(!file.eof()){
		file>>id; file>>name; file>>age; file>>grade; file>>city; file>>marks;
		if(strcmp(ID,id)==0){
			file.close();
			return false;
		}
	}
	return true;
}
void read(){
	char id[5];
	char name[20];
	char age[5];
	char grade[2];
	char city[10];
	char marks[5];
	fstream file("data.txt",ios::in);
	cout<<"######################"<<endl;
	cout<<"| ID * NAME * AGE * GRADE * CITY * MARKS |"<<endl;
	while(true){
		file>>id; file>>name; file>>age; file>>grade; file>>city; file>>marks;
		if(file.eof()) break;
		cout<<"| #"<<id<<"---"<<name<<"---"<<age<<"---"<<grade<<"------"<<city<<"---"<<marks<<"  |"<<endl;
	}
	cout<<"\n######################"<<endl;
	file.close();
}
bool search(char searchValue[20]){
	char value[20];
	fstream file("data.txt",ios::in);
	while(!file.eof()){
		file>>value;
		if(strcmp(value,searchValue)==0){
			cout<<value<<' ';
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}
bool updateRecord(char newId[5],char oldName[20],char newName[20],char newAge[5],char newGrade[2],char newCity[10],char newMarks[5])
{
	bool cont =true;
	char id[5];
	char name[20];
	char age[5];
	char grade[2];
	char city[10];
	char marks[5];
	bool updated = false;
	fstream temp("temp.txt",ios::app|ios::out);
	fstream file("data.txt",ios::in);
	temp.clear();
	while(cont){
		file>>id; file>>name; file>>age; file>>grade; file>>city; file>>marks;
		if(file.eof()) break;
		if(strcmp(name,oldName)!=0){
			temp<<id<<" ";
			temp<<name<<" ";
			temp<<age<<" ";
			temp<<grade<<" ";
			temp<<city<<" ";
			temp<<marks<<" ";
		}
		else{
			if(cont){
				temp<<newId<<" ";
				temp<<newName<<" ";
				temp<<newAge<<" ";
				temp<<newGrade<<" ";
				temp<<newCity<<" ";
				temp<<newMarks<<" ";
				cont=false;
			}
			else{
				temp<<id<<" ";
				temp<<name<<" ";
				temp<<age<<" ";
				temp<<grade<<" ";
				temp<<city<<" ";
				temp<<marks<<" ";	
			}
			updated = true;
		}
	}
	file.close();
	temp.close();
	remove("data.txt");
	rename("temp.txt","data.txt");
	return updated;
}
bool deleteRecord(char del[20],int attr){
	char id[5];
	char name[20];
	char age[5];
	char grade[2];
	char city[10];
	char marks[5];
	if(search(del)==true){
		fstream temp("temp.txt",ios::app|ios::out);
		fstream file("data.txt",ios::in);
		temp.clear();
		while(true){
			file>>id;
			file>>name;
			file>>age;
			file>>grade;
			file>>city;
			file>>marks;
			
			if(file.eof()) break;
			
			if(attr==1){
				if(strcmp(id,del)!=0){
					temp<<id<<" ";
					temp<<name<<" ";
					temp<<age<<" ";
					temp<<grade<<" ";
					temp<<city<<" ";
					temp<<marks<<" ";
				}
			}
			else if(attr==2){
				if(strcmp(name,del)!=0){
					temp<<id<<" ";
					temp<<name<<" ";
					temp<<age<<" ";
					temp<<grade<<" ";
					temp<<city<<" ";
					temp<<marks<<" ";
				}
			}
			else if(attr==3){
				if(strcmp(age,del)!=0){
					temp<<id<<" ";
					temp<<name<<" ";
					temp<<age<<" ";
					temp<<grade<<" ";
					temp<<city<<" ";
					temp<<marks<<" ";
				}
			}
			else if(attr==4){
				if(strcmp(grade,del)!=0){
					temp<<id<<" ";
					temp<<name<<" ";
					temp<<age<<" ";
					temp<<grade<<" ";
					temp<<city<<" ";
					temp<<marks<<" ";
				}
			}
			else if(attr==5){
				if(strcmp(city,del)!=0){
					temp<<id<<" ";
					temp<<name<<" ";
					temp<<age<<" ";
					temp<<grade<<" ";
					temp<<city<<" ";
					temp<<marks<<" ";
				}
			}
			else if(attr==6){
				if(strcmp(marks,del)!=0){
					temp<<id<<" ";
					temp<<name<<" ";
					temp<<age<<" ";
					temp<<grade<<" ";
					temp<<city<<" ";
					temp<<marks<<" ";
				}
			}
			else{
				cout<<"Invalid Operation!"<<endl;
				return false;
			}
			
		}
		file.close();
		temp.close();
		remove("data.txt");
		rename("temp.txt","data.txt");
		return true;
	}
	else{
		return false;
	}
}
void homeScreen(){
	while(true)
	{
		char choise;
		cout<<"\t\t\t\t#################################"<<endl;
		cout<<"\t\t\t\tStudents Records Storage System "<<endl;
		cout<<"\t\t\t\t#################################"<<endl;
		cout<<endl<<"\t\t\t\t1- Add record."<<endl;
		cout<<"\t\t\t\t2- Read records."<<endl;
		cout<<"\t\t\t\t3- Delete record."<<endl;
		cout<<"\t\t\t\t4- Update record."<<endl;
		cout<<"\t\t\t\t5- Search record."<<endl;
		cout<<"\t\t\t\t6- Exit program."<<endl;
		cout<<"\t\t\t\t7- Open the Data File."<<endl;
		cout<<" Enter your choise: ";
		cin>>choise;
		switch(choise){
			case '1':{
				char ID[5],newName[20],newAge[5],newGrade[2],newCity[10],marks[5];
				cout<<"Enter new ID: ";
				cin>>ID;
				bool status = checkId(ID);
				if(!status){
					cout<<"Wrong ID..."<<endl;
					break;
				}
				cout<<"Enter new Name: ";
				cin>>newName;
				cout<<"Enter new Age: ";
				cin>>newAge;
				cout<<"Enter new Grade: ";
				cin>>newGrade;
				cout<<"Enter new City: ";
				cin>>newCity;
				cout<<"Enter new Marks: ";
				cin>>marks;
				insertRecord(ID,newName,newAge,newGrade,newCity,marks);
				break;
			}
			case '2':
				read();
				break;
			case '3':{
				int attr;
				cout<<"1-Delete with ID.\n";
				cout<<"2-Delete with Name.\n";
				cout<<"3-Delete with Age.\n";
				cout<<"4-Delete with Grade.\n";
				cout<<"5-Delete with City.\n";
				cout<<"6-Delete with Marks.\n";
				cout<<"Enter Deletion Method: "; cin>>attr;
				char val[20];
				switch(attr){
					case 1:
						cout<<"Enter ID to delete: ";
						break;
					case 2:
						cout<<"Enter Name to delete: ";
						break;
					case 3:
						cout<<"Enter Age to delete: ";
						break;
					case 4:
						cout<<"Enter Grade to delete: ";
						break;
					case 5:
						cout<<"Enter City to delete: ";
						break;
					case 6:
						cout<<"Enter Marks to delete: ";
						break;
					default:
						cout<<"Invalid Operation!"<<endl;
						exit(0);
				}
				cin>>val;
				bool status = deleteRecord(val,attr);
				if(status)
					cout<<"# Deleted successfuly!"<<endl;
				else
					cout<<"# "<<val<<" not found!"<<endl;
				break;
			}
			case '4':{
				char newId[5],oldName[20],newName[20],newAge[5],newGrade[2],newCity[10],newMarks[5];
				int status;
				cout<<"Enter name to update: ";
				cin>>oldName;
				if(search(oldName)){
					cout<<"Enter new ID: "; cin>>newId;
					if(!checkId(newId)){
						cout<<"Wrong ID..."<<endl;
						break;
					}
					cout<<"Enter new Name: "; cin>>newName;
					cout<<"Enter new Age: "; cin>>newAge;
					cout<<"Enter new Grade: "; cin>>newGrade;
					cout<<"Enter new City: "; cin>>newCity;
					cout<<"Enter new Marks: "; cin>>newMarks;
					status = updateRecord(newId,oldName,newName,newAge,newGrade,newCity,newMarks);
					if(status){
						cout<<"# Record updated successfuly!"<<endl;
					}
					else{
						cout<<"# Update failed!"<<endl;
					}
				}else{
					cout<<"# "<< oldName << " not found in records!"<<endl;
				}
				break;
			}
			case '5':{
				char searchVal[20];
				cout<<"Enter {ID,Name,Age,Grade,City,Marks} to search: "; cin>>searchVal;
				if(search(searchVal)){
					cout<<"Record Exist!"<<endl;
				}
				else{
					cout<<"Not found!"<<endl;
				}
				break;
			}
			case '6':{
				return;
			}
			case '7':{
				system("notepad data.txt");
				break;
			}
			default:{
				cout<<" Invalid input!"<<endl;
				break;
			}
		}
	}
}
int main(){
	homeScreen();
	system("exit");
}
