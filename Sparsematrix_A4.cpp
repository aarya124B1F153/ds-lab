#include <iostream>
using namespace std;

int main() {
 int students, subjects;
 cout << "How many students? ";
 cin >> students;
 cout << "How many subjects? ";
 cin >> subjects;

 int marks[50][50]; 
 for (int i=0;i<students;i++){
  for (int j=0;j<subjects;j++){
   cout << "Marks of student " << i+1 << " subject " << j+1 << ": ";
   cin >> marks[i][j];
  }
 }

 cout << "\nMatrix of marks:\n";
 for (int i=0;i<students;i++){
  for (int j=0;j<subjects;j++){
   cout << marks[i][j] << " ";
  }
  cout << "\n";
 }

 cout << "\nSparse representation:\n";
 for (int i=0;i<students;i++){
  for (int j=0;j<subjects;j++){
   if(marks[i][j]!=0){
    cout << i << " " << j << " " << marks[i][j] << "\n";
   }
  }
 }

 cout << "\nAverage marks of each student:\n";
 for (int i=0;i<students;i++){
  float sum=0;
  for (int j=0;j<subjects;j++){
   sum+=marks[i][j];
  }
  cout << "Student " << i+1 << ": " << sum/subjects << "\n";
 }

 cout << "\nAverage marks of each subject:\n";
 for (int j=0;j<subjects;j++){
  float sum=0;
  for (int i=0;i<students;i++){
   sum+=marks[i][j];
  }
  cout << "Subject " << j+1 << ": " << sum/students << "\n";
 }

 return 0;
}

